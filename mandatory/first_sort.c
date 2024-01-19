/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:04:00 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/19 04:38:16 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_to_b(t_env *env)
{
	int divideby;
	int dividebak;
	int x;
	int i;
	int	backup;

	divideby = env->a_size / CHUNKS;
	dividebak = divideby;
	x = env->a_size;
	i = 2;
	while (env->a_size != 1)
	{
		backup = divideby;
		if (env->a[0] <= divideby && env->a[0] != ft_is_max_nbr(env->a))
		{
			pb(env);
			if (env->b[0] < (divideby - (dividebak / 2)) && env->a[0] > divideby)
				rr(env);
			else if (env->b[0] < (divideby - (dividebak / 2)))
				rb(env);
		}
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

void	make_chunks(t_env *env)
{
	int		moves;

	env->original = env->a_size;
	env->id = 2;
	env->tails = 75;
	env->tailsbuffer = 3;
	while (env->a_size > 3)
	{
		moves = env->a_size;
		while (moves > 0 && env->a_size > 3)
		{
			if (env->a[0] <= env->tails && env->a[0] != ft_is_max_nbr(env->a) && env->a[0] != ft_is_max_nbr(env->a) - 1 && env->a[0] != ft_is_max_nbr(env->a) - 2)
			{
				pb(env);
				if (env->b[0] < ((env->tails + env->tailsbuffer) / 2) && env->a[0] > env->tails)
				{
					rr(env);
					moves--;
				}
				else if (env->b[0] < ((env->tails + env->tailsbuffer) / 2))
					rb(env);
			}
			else
				ra(env);
			moves--;
		}
		env->id += 2;
		env->tailsbuffer = env->tails;
		env->tails = (env->original / env->id) + env->tails;
	}
	// print_stacks(env);
	// fflush(stdout);
	sort3(env);
}
