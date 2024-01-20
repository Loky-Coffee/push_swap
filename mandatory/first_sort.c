/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:04:00 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 17:00:50 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort funktion active only wenn you give 3 aquments.
void	sort3(t_env *env)
{
	if (env->a[0] > env->a[1] && env->a[0] > env->a[2] && env->a[1] > env->a[2])
	{
		sa(env);
		rra(env);
	}
	else if (env->a[0] < env->a[1] && env->a[0] < env->a[2] \
	&& env->a[1] > env->a[2])
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

void	sort5(t_env *env)
{
	while (env->a_size > 3)
	{
		if (env->a[0] == env->a_size + env->b_size || \
		env->a[0] == (env->a_size + env->b_size) - 4)
			pb(env);
		else
			ra(env);
	}
	sort3(env);
	pa(env);
	if (env->a[0] == env->a_size + env->b_size)
		ra(env);
	if (env->b[0] == env->a_size + env->b_size)
	{
		pa(env);
		ra(env);
	}
	else
		pa(env);
}

void	sort_a_to_b(t_env *env)
{
	env->div = env->a_size / CHUNKS;
	env->db = env->div;
	env->x = env->a_size;
	env->i = 2;
	while (env->a_size > 5)
	{
		if (env->a[0] <= env->div && env->a[0] < ft_is_max_nbr(env->a) - 4)
		{
			pb(env);
			if (env->b[0] < (env->div - (env->db / 2)) && env->a[0] > env->div)
				rr(env);
			else if (env->b[0] < (env->div - (env->db / 2)))
				rb(env);
		}
		else
			ra(env);
		if (env->x == 0)
		{
			env->div = env->db * env->i;
			env->i++;
			env->x = env->a_size;
		}
		else
			env->x--;
	}
}

void	make_chunks_utils(t_env *env)
{
	pb(env);
	if (env->b[0] < ((env->tails + env->tailsbuffer) / 2) && \
	env->a[0] > env->tails)
	{
		rr(env);
		env->moves--;
	}
	else if (env->b[0] < ((env->tails + env->tailsbuffer) / 2))
		rb(env);
}

void	make_chunks(t_env *env)
{
	env->moves = 0;
	env->original = env->a_size;
	env->id = 2;
	env->tails = 75 % env->a_size;
	env->tailsbuffer = 2;
	while (env->a_size > 5)
	{
		env->moves = env->a_size;
		while (env->moves > 0 && env->a_size > 5)
		{
			if (env->a[0] <= env->tails && env->a[0] < \
			ft_is_max_nbr(env->a) - 4)
				make_chunks_utils(env);
			else
				ra(env);
			env->moves--;
		}
		env->id += 2;
		env->tailsbuffer = env->tails;
		env->tails = (env->original / env->id) + env->tails;
	}
}
