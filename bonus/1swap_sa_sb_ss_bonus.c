/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1swap_sa_sb_ss_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:39:08 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 20:29:20 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_env *env)
{
	int	tmp;

	if (env->a_size > 1)
	{
		tmp = env->a[0];
		env->a[0] = env->a[1];
		env->a[1] = tmp;
	}
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
}
