/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 09:16:43 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 19:01:27 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_only_one_minus(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			x++;
			if (x == 2)
				ft_error("Error\n", 1);
		}
		i++;
	}
}

static void	ist_not_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((!ft_isdigit(str[i])) && (str[i] != '-') && (str[i] != '+'))
			ft_error("Error\n", 1);
		i++;
	}
	check_only_one_minus(str);
}

/// @brief Checks if the string is a valid int
/// @param str The string to check
/// @return int 1 if the string is a valid int, 0 otherwise
int	ft_is_int(char *str)
{
	ist_not_char(str);
	if (str[0] == '-')
	{
		if (ft_strlen(str) > 11)
			ft_error("Error\n", 1);
		if (ft_strlen(str) == 11)
		{
			if (ft_strncmp(str, "-2147483648", 11) > 0)
				ft_error("Error\n", 1);
		}
	}
	else
	{
		if (ft_strlen(str) > 10)
			ft_error("Error\n", 1);
		if (ft_strlen(str) == 10)
		{
			if (ft_strncmp(str, "2147483647", 10) > 0)
				ft_error("Error\n", 1);
		}
	}
	return (1);
}

void	free_all(t_env *env, int fd)
{
	if (fd == 0)
	{
		free(env->a);
		free(env->b);
		exit (0);
	}
	if (fd == 1)
	{
		free(env->a);
		free(env->b);
		ft_error("Error\n", 2);
	}
}
