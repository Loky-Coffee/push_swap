/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_max_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:25:38 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/14 05:26:51 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int ft_is_max_nbr(int *arg)
{
	int i;
	int min;
	int length;

	i = 0;
	min = arg[0];
	if (!arg)
		return (0);
	length = 0;
	while (arg[length] != '\0')
		length++;
	while (i < length)
	{
		if (arg[i] > min)
			min = arg[i];
		i++;
	}
	return(min);
}