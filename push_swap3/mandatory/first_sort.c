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

void	sort_a_to_b_1(t_env *env)
{
	int divideby;
	int dividebak;
	int x;
	int i;

	divideby = env->a_size / THREADS;
	dividebak = divideby;
	x = env->a_size;
	i = 2;
	while (env->a_size != 1)
	{
		if (env->a[0] <= divideby && env->a[0] != ft_is_max_nbr(env->a))
			pb(env);
			
		else
			ra(env);
		if (x == 0)
		{
			divideby = dividebak * i;
			i++;
			x = env->a_size;
		}
		else
			x--;
	}
}
