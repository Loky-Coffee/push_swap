/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rotate_ra_rb_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:43:26 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/19 04:03:44 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
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
	write(1, "rr\n", 3);
}
