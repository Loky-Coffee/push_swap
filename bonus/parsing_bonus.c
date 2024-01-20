/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:47:27 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 20:29:09 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	parse_args(int argc, char **argv, t_env *env)
{
	if (argc > 0)
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

void	spaceing(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '\t')
			argv[1][i] = ' ';
		i++;
	}
}

int	parse_args_array(char **argv, t_env *env)
{
	int		i;
	char	**buffer;

	i = 0;
	buffer = NULL;
	spaceing(argv);
	buffer = ft_split(argv[1], ' ');
	if (buffer[0] == 0)
		exit(0);
	if (buffer == 0)
		return (0);
	while (buffer[i] != 0)
	{
		if (!ft_is_int(buffer[i]))
		{
			free_split(buffer);
			return (0);
		}
		env->a[i] = ft_atoi(buffer[i]);
		i++;
	}
	env->a_size = i;
	free_split(buffer);
	return (1);
}

int	not_2_time_same_nbr(t_env *env)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	if (env->a_size == 2 && env->a[0] > env->a[1])
	{
		sa(env);
		return (0);
	}
	while (y < env->a_size)
	{
		x = env->a[y];
		i = y + 1;
		while (i < env->a_size)
		{
			if (env->a[i] == x)
				free_all(env, ERROR);
			i++;
		}
		y++;
	}
	return (1);
}

int	check_array_sortet(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->a_size - 1)
	{
		if (env->a[i] > env->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
