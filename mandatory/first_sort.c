/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:04:00 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/15 21:20:13 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_a_to_b_1(t_env *env)
// {
// 	int divideby;
// 	int dividebak;
// 	int x;
// 	int i;

// 	divideby = env->a_size / 2;
// 	dividebak = divideby;
// 	x = env->a_size;
// 	i = 2;
// 	while (env->a_size > 3)
// 	{
// 		while (divideby < env->a_size)
// 		{
// 			if (env->a[0] <= divideby && env->a[0] != ft_is_max_nbr(env->a))
// 				pb(env);
// 			else
// 				ra(env);
// 			if (x == 0)
// 			{
// 				divideby = dividebak * i;
// 				i *= 2;
// 				x = env->a_size;
// 			}
// 			else
// 				x--;
// 		}
// 	}
// }

void	make_chunks(t_env *env)
{
	int	original;
	int	tails;
	int	moved;
	int total;
	int	id;
	int	stuck;

	id = 2;
	total = 0;
	original = env->a_size;
	stuck = env->a_size;
	int i = 0;
	make_sort_array(env);
	while(env->a_size >= 1)
	{
		tails = original / id;
		moved = 0;
		total = 0;
		while (moved <= tails  && stuck > 0)
		{
			print_stacks(env);
			if (env->a[0] < tails)
			{
				pb(env);
				moved++;
				total++;
			}
			else
				ra(env);
			stuck--;
		}
		stuck = env->a_size;
		printf("id : %d\n", id);
		fflush(stdout);
		id += 2;
	}
}
