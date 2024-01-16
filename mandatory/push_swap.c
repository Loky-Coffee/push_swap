/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 06:04:21 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/15 19:41:21 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	intex_stack_a(t_env *env)
{
	long int small;
	int buffer;

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

void	make_sort_array(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->a_size)
	{
		env->sort[i] = env->a[i];
		i++;
	}
	intex_stack_a(env);
}

static int	parse_args(int argc, char **argv, t_env *env)
{
	if (argc > 1)
	{
		while (argc > 1)
		{
			ft_is_int(argv[argc - 1]);
			env->a[argc - 2] = ft_atoi(argv[argc - 1]);
			argc--;
		}
		argc--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	env;

	env = (t_env){0};
	if (argc < 2)
		return (0);
	env.a_size = argc - 1;
	env.b_size = 0;
	env.a = ft_calloc(argc + 2, sizeof(int));
	env.b = ft_calloc(argc + 2, sizeof(int));
	env.sort = ft_calloc(argc + 2, sizeof(int));
	if (!env.a || !env.b)
		ft_error("Calloc Error", 2);
	if (!parse_args(argc, argv, &env))
		return (0);
	if (argc == 4)
		sort3(&env);
	else if(argc > 4)
		sort_big_main(&env);
	free(env.a);
	free(env.b);
	return (0);
}
