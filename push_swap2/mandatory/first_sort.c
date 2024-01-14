/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:04:00 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/14 12:39:25 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_to_b_3(t_env *env)
{
	env->i = env->a_size;
	int a = ft_is_max_nbr(env->a);
	while (env->i > 1)
	{
		if (env->a[0] < a)
		{
			pb(env);
			env->i--;
		}
		else
			ra(env);
	}
	if (env->a[0] > env->a[1] && env->a[0] > env->a[2] && env->a[1] > env->a[2])
	{
		sa(env);
		rra(env);
	}
	else if (env->a[0] < env->a[1] && env->a[0] < env->a[2] && env->a[1] > env->a[2])
	{
		rra(env);
		sa(env);
	}
	else if (env->a[0] < env->a[1] && env->a[0] > env->a[2])
		rra(env);
	else if (env->a[0] > env->a[1] && env->a[0] < env->a[2])
		sa(env);
	else if (env->a[0] > env->a[1] && env->a[0] > env->a[2])
		ra(env);
}
void	sort_a_to_b_2(t_env *env)
{
	env->i = env->a_size;
	while(env->i > 0)
	{
		if (env->a[0] <= env->average_vvsmall && env->a[0] < env->average_vsmall)
			pb(env);
		else
			ra(env);
		if (env->b[0] <= env->average_vsmall)
			rb(env);
		env->i--;
	}
	env->i = env->a_size;
	while(env->i > 0)
	{
		if (env->a[0] <= env->average_vvbig)
			pb(env);
		else
			ra(env);
		if (env->b[0] < env->average_small)
			rb(env);
		env->i--;
	}
	sort_a_to_b_3(env);
}
void	sort_a_to_b_1(t_env *env)
{
	env->i = env->a_size;
	while(env->i > 0)
	{
		if (env->a[0] < env->average_big && env->a[0] > env->average_vsmall)
			pb(env);
		else
			ra(env);
		if (env->b[0] < env->average_small)
			rb(env);
		env->i--;
	}
	env->i = env->a_size;
	while(env->i > 0)
	{
		if (env->a[0] < env->average_vbig && env->a[0] > env->average_vvsmall)
			pb(env);
		else
			ra(env);
		if (env->b[0] < env->average_small)
			rb(env);
		env->i--;
	}
	sort_a_to_b_2(env);
}
