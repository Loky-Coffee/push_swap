/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 06:04:21 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 19:07:20 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_big_main(t_env *env)
{
	if (env->a_size == 5)
		sort5(env);
	else if (env->a_size == 3)
		sort3(env);
	else
	{
		if (env->a_size < 150)
			sort_a_to_b(env);
		else
			make_chunks(env);
		sort5(env);
		while (env->b_size > 0)
			search_less_cost(env);
	}
	while ((env->a[env->a_size - 1] + 1) == env->a[0])
		rra(env);
}

int	main(int argc, char **argv)
{
	t_env	env;

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
	sort_big_main(&env);
	free_all(&env, ONLY_FREE);
	return (0);
}
