/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1push_pa_pb_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:47:54 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 20:29:30 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_env *env)
{
	int	i;

	i = env->a_size - 1;
	if (env->b_size > 0)
	{
		while (i >= 0)
		{
			env->a[i + 1] = env->a[i];
			i--;
		}
		env->a[0] = env->b[0];
		i = 0;
		while (i <= env->b_size - 1)
		{
			env->b[i] = env->b[i + 1];
			i++;
		}
		env->b_size--;
		env->a_size++;
	}
}

void	pb(t_env *env)
{
	int	i;

	i = env->b_size - 1;
	if (env->a_size > 0)
	{
		while (i >= 0)
		{
			env->b[i + 1] = env->b[i];
			i--;
		}
		env->b[0] = env->a[0];
		i = 0;
		while (i <= env->a_size - 1)
		{
			env->a[i] = env->a[i + 1];
			i++;
		}
		env->b_size++;
		env->a_size--;
	}
}
