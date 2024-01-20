/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _swap_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:39:08 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/11 01:40:34 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_env *env)
{
	int	tmp;

	if (env->a_size > 1)
	{
		tmp = env->a[0];
		env->a[0] = env->a[1];
		env->a[1] = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_env *env)
{
	int	tmp;

	if (env->b_size > 1)
	{
		tmp = env->b[0];
		env->b[0] = env->b[1];
		env->b[1] = tmp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_env *env)
{
	int	tmp;

	if (env->a_size > 1)
	{
		tmp = env->a[0];
		env->a[0] = env->a[1];
		env->a[1] = tmp;
	}
	if (env->b_size > 1)
	{
		tmp = env->b[0];
		env->b[0] = env->b[1];
		env->b[1] = tmp;
	}
	write(1, "ss\n", 3);
}
