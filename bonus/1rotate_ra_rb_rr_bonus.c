/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1rotate_ra_rb_rr_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:43:26 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 20:29:22 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_env *env)
{
	int	tmp;
	int	i;

	tmp = env->a[0];
	i = 1;
	while (i <= env->a_size)
	{
		env->a[i - 1] = env->a[i];
		i++;
	}
	env->a[env->a_size - 1] = tmp;
}

void	rb(t_env *env)
{
	int	tmp;
	int	i;

	tmp = env->b[0];
	i = 1;
	while (i <= env->b_size)
	{
		env->b[i - 1] = env->b[i];
		i++;
	}
	env->b[env->b_size - 1] = tmp;
}

void	rr(t_env *env)
{
	int	tmp;
	int	i;

	tmp = env->a[0];
	i = 1;
	while (i <= env->a_size)
	{
		env->a[i - 1] = env->a[i];
		i++;
	}
	env->a[env->a_size - 1] = tmp;
	tmp = env->b[0];
	i = 1;
	while (i <= env->b_size)
	{
		env->b[i - 1] = env->b[i];
		i++;
	}
	env->b[env->b_size - 1] = tmp;
}
