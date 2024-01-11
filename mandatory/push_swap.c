/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 06:04:21 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/11 11:48:26 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_sort_array(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->a_size)
	{
		env->sort[i] = env->a[i];
		i++;
	}
	i = 0;
	while (i < env->a_size)
	{
		if (env->max < env->sort[i])
			env->max = env->sort[i];
		i++;
	}
	i = 0;
	while (i < env->a_size)
	{
		if (env->min > env->sort[i])
			env->min = env->sort[i];
		i++;
	}
	env->average_small = ((env->min + env->max) / 3);
	env->average_big = ((env->min + env->max) / 3) * 2;
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
	// sort_small_main(&env);
	make_sort_array(&env);
	sort_big_main(&env);
	free(env.sort);
	free(env.a);
	free(env.b);
	return (0);
}
