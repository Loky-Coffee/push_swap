/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:50:02 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/20 18:54:05 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stacks(t_env *env)
// {
// 	int	i;
// 	int	size;

// 	size = (env->a_size + env->b_size) - 1;
// 	i = 0;
// 	ft_putstr_fd("--------------------\n", 1);
// 	while (size >= 0)
// 	{
// 		ft_putstr_fd("|    ", 1);
// 		ft_putnbr_fd(env->a[i], 1);
// 		ft_putstr_fd("    |    ", 1);
// 		ft_putnbr_fd(env->b[i], 1);
// 		ft_putstr_fd("    |\n", 1);
// 		i++;
// 		size--;
// 		ft_putstr_fd("--------------------\n", 1);
// 	}
// 	ft_putstr_fd("--------------------\n", 1);
// 	ft_putstr_fd("| Stack A | Stack B |\n", 1);
// 	ft_putstr_fd("--------------------\n", 1);
// 	ft_putstr_fd("|    ", 1);
// 	ft_putnbr_fd(env->a_size, 1);
// 	ft_putstr_fd("    |    ", 1);
// 	ft_putnbr_fd(env->b_size, 1);
// 	ft_putstr_fd("    |\n", 1);
// 	ft_putstr_fd("--------------------\n", 1);
// 	ft_putstr_fd("XXXXXXXXXXXXXXXXXXXXX\n", 1);
// 	ft_putstr_fd("--------------------\n", 1);
// }
void	rotate_a(t_env *env)
{
	while ((env->b[0] > (env->a[0] - 50)) && (env->b[0] < \
	(env->a[0] - 2)) && env->a[env->a_size - 1] == env->a_size + env->b_size)
	{
		pa(env);
		ra(env);
	}
	while (env->b[0] > env->a[env->a_size - 1] && (env->b[0] > \
	(env->a[0] - 50)) && (env->b[0] < (env->a[0] - 1)))
	{
		pa(env);
		ra(env);
	}
}

int	search_nummer_position(t_env *env, bool up_or_down)
{
	int	count;

	count = 0;
	if (up_or_down == NEXT_NUMBER_IST_UP)
	{
		while (env->a[0] - 1 != env->b[count])
			count++;
		return (count);
	}
	count = env->b_size - 1;
	if (up_or_down == NEXT_NUMBER_IST_DOWN)
	{
		while (env->a[0] - 1 != env->b[count])
			count--;
		return (env->b_size - count);
	}
	return (0);
}

void	sort_up_to_a_start(t_env *env, bool up_or_down)
{
	while (env->b_size > 0)
	{
		rotate_a(env);
		if (env->a[0] - 1 == env->b[0])
		{
			pa(env);
			break ;
		}
		if (up_or_down == NEXT_NUMBER_IST_UP)
			rb(env);
		else if (up_or_down == NEXT_NUMBER_IST_DOWN)
			rrb(env);
	}
}

void	search_less_cost(t_env *env)
{
	while ((env->a[env->a_size - 1] + 1) == env->a[0])
		rra(env);
	env->search_first_nummer_up = \
	search_nummer_position(env, NEXT_NUMBER_IST_UP);
	env->search_first_nummer_down = \
	search_nummer_position(env, NEXT_NUMBER_IST_DOWN);
	if (env->search_first_nummer_up <= env->search_first_nummer_down)
		sort_up_to_a_start(env, NEXT_NUMBER_IST_UP);
	else
		sort_up_to_a_start(env, NEXT_NUMBER_IST_DOWN);
}
