/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 09:16:43 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/07 09:19:15 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_int(char *str)
{
	if (str[0] == '-')
	{
		if (ft_strlen(str) > 11)
			ft_error("Error: The number is too large\n", 1);
		if (ft_strlen(str) == 11)
		{
			if (ft_strncmp(str, "-2147483648", 11) > 0)
				ft_error("Error: MIN int exceeded!\n", 1);
		}
	}
	else
	{
		if (ft_strlen(str) > 10)
			ft_error("Error: The number is too large\n", 1);
		if (ft_strlen(str) == 10)
		{
			if (ft_strncmp(str, "2147483647", 10) > 0)
				ft_error("Error: MAX int exceeded!\n", 1);
		}
	}
	return (1);
}