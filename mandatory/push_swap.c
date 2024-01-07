/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 06:04:21 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/07 09:20:45 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	env.ar = ft_calloc(argc - 1, sizeof(char *));
	env.br = ft_calloc(argc - 1, sizeof(char *));
	env.a = ft_calloc(argc + 2, sizeof(int));
	env.b = ft_calloc(argc + 2, sizeof(int));
	if (!env.ar || !env.br)
		return (0);
	if (!parse_args(argc, argv, &env))
		return (0);
	// sort_big(&env);
	free(env.ar);
	free(env.br);
	free(env.a);
	free(env.b);
	return (0);
}
