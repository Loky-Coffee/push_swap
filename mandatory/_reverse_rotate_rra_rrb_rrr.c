/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _reverse_rotate_rra_rrb_rrr.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:44:11 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/11 06:08:24 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_env *env)
{
	int	tmp;
	int	i;

	i = env->a_size - 1;
	tmp = env->a[env->a_size - 1];
	while (i > 0)
	{
		env->a[i] = env->a[i - 1];
		i--;
	}
	env->a[0] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_env *env)
{
	int	tmp;
	int	i;

	i = env->b_size - 1;
	tmp = env->b[env->b_size - 1];
	while (i > 0)
	{
		env->b[i] = env->b[i - 1];
		i--;
	}
	env->b[0] = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_env *env)
{
	int	tmp;
	int	i;

	i = env->a_size - 1;
	tmp = env->a[env->a_size - 1];
	while (i > 0)
	{
		env->a[i] = env->a[i - 1];
		i--;
	}
	env->a[0] = tmp;
	i = env->b_size - 1;
	tmp = env->b[env->b_size - 1];
	while (i > 0)
	{
		env->b[i] = env->b[i - 1];
		i--;
	}
	env->b[0] = tmp;
	write(1, "rrr\n", 4);
}