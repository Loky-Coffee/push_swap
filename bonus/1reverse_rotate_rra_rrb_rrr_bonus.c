/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1reverse_rotate_rra_rrb_rrr_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:44:11 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 20:29:26 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}
