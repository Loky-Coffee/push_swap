/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 06:04:21 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 22:02:56 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	intex_stack_a(t_env *env)
{
	long int	small;
	int			buffer;

	env->x = 1;
	buffer = MAX_INT;
	small = MIN_INT - 1;
	env->i = 0;
	while (env->x <= env->a_size)
	{
		while (env->i < env->a_size)
		{
			if (env->sort[env->i] <= buffer && env->sort[env->i] > small)
			{
				buffer = env->sort[env->i];
				env->index = env->i;
			}
			env->i++;
		}
		small = buffer;
		buffer = MAX_INT;
		env->a[env->index] = env->x;
		env->x++;
		env->i = 0;
	}
	free(env->sort);
}

void	make_index_array(t_env *env)
{
	int	i;

	env->sort = ft_calloc(env->a_size, sizeof(int));
	i = 0;
	while (i < env->a_size)
	{
		env->sort[i] = env->a[i];
		i++;
	}
	intex_stack_a(env);
}
int	check_args(t_env *env)
{
	if (ft_strncmp(env->line, "sa\n", ft_strlen(env->line)))
		sa(env);
	else if (ft_strncmp(env->line, "sb\n", ft_strlen(env->line)))
		sb(env);
	else if (ft_strncmp(env->line, "ss\n", ft_strlen(env->line)))
		ss(env);
	else if (ft_strncmp(env->line, "pa\n", ft_strlen(env->line)))
		pa(env);
	else if (ft_strncmp(env->line, "pb\n", ft_strlen(env->line)))
		pb(env);
	else if (ft_strncmp(env->line, "ra\n", ft_strlen(env->line)))
		ra(env);
	else if (ft_strncmp(env->line, "rb\n", ft_strlen(env->line)))
		rb(env);
	else if (ft_strncmp(env->line, "rr\n", ft_strlen(env->line)))
		rr(env);
	else if (ft_strncmp(env->line, "rra\n", ft_strlen(env->line)))
		rra(env);
	else if (ft_strncmp(env->line, "rrb\n", ft_strlen(env->line)))
		rrb(env);
	else if (ft_strncmp(env->line, "rrr\n", ft_strlen(env->line)))
		rrr(env);
	else
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
int	checker(t_env *env)
{
	while (1)
	{
		env->line = get_next_line(STDIN_FILENO);
		if (env->line == NULL)
			return (0);
		if(check_args(env) == EXIT_FAILURE)
		{
			free(env->line);
			break;
		}
		else if (check_args(env) == EXIT_SUCCESS)
		{
			free(env->line);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	env;

	printf("LALA");
	fflush(stdout);
	env = (t_env){0};
	if (argc < 2)
		return (0);
	env.b_size = 0;
	env.a = ft_calloc(argc * 251, sizeof(int));
	env.b = ft_calloc(argc * 251, sizeof(int));
	if (!env.a || !env.b)
		ft_error("Calloc Error", 2);
	if (argc == 2)
		parse_args_array(argv, &env);
	else
	{
		env.a_size = argc - 1;
		parse_args(argc, argv, &env);
	}
	not_2_time_same_nbr(&env);
	make_index_array(&env);
	if (check_array_sortet(&env))
		free_all(&env, ONLY_FREE);
	checker(&env);

	free_all(&env, ONLY_FREE);
	return (0);
}
