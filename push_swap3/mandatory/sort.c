/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:50:02 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/15 21:07:52 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_env *env)
{
	int i;
	int size;

	size = (env->a_size + env->b_size) - 1;
	i = 0;
	ft_putstr_fd("--------------------\n", 1);
	while (size >= 0)
	{
		ft_putstr_fd("|    ", 1);
		ft_putnbr_fd(env->a[i], 1);
		ft_putstr_fd("    |    ", 1);
		ft_putnbr_fd(env->b[i], 1);
		ft_putstr_fd("    |\n", 1);
		i++;
		size--;
		ft_putstr_fd("--------------------\n", 1);

	}
	ft_putstr_fd("--------------------\n", 1);
	ft_putstr_fd("| Stack A | Stack B |\n", 1);
	ft_putstr_fd("--------------------\n", 1);
		ft_putstr_fd("|    ", 1);
		ft_putnbr_fd(env->a_size, 1);
		ft_putstr_fd("    |    ", 1);
		ft_putnbr_fd(env->b_size, 1);
		ft_putstr_fd("    |\n", 1);
	ft_putstr_fd("--------------------\n", 1);
	ft_putstr_fd("XXXXXXXXXXXXXXXXXXXXX\n", 1);
	ft_putstr_fd("--------------------\n", 1);
}
void	sort3(t_env *env)
{
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

int search_up(t_env *env)
{
	int	count;

	count = 0;
	while (env->a[0] - 1 != env->b[count])
		count++;
	return(count);
}
int search_down(t_env *env)
{
	int	count;

	count = env->b_size;
	while (env->a[0] - 1 != env->b[count])
		count--;
	return(env->b_size - count);
}

void big_sort(t_env *env)
{
	int		search_d;
	int		search_u;
	bool	i;
	// sort3(env);
	// printf("-----------------------");
	// fflush(stdout);
	while (env->b_size > 0)
	{
		search_d = search_down(env);
		search_u = search_up(env);
		i = 0;
		// printf("search_u : %d | search_d : %d | env->b_size : %d\n", search_u, search_d, env->b_size);
		// fflush(stdout);
		if (search_u <= search_d)
		{
			while (i == 0)
			{
				if (env->a[0] - 1 == env->b[0])
				{
					pa(env);
					i = 1;
				}
				else
					rb(env);
			}
		}
		else if (search_u > search_d)
		{
			while (i == 0)
			{
				// print_stacks(env);
				if (env->a[0] - 1 == env->b[0])
				{
					pa(env);
					i = 1;
				}
				else
					rrb(env);
			}
		}
	}
}
// void	sort_b_to_a(t_env *env)
// {
// 	int		a;
// 	int		y;
// 	int		i;
// 	bool	b;

// 	a = 1;
// 	y = 0;
// 	i = 0;
// 	b = 0;
// 	while (env->b_size > 0)
// 	{
// 		if (env->a[0] - 1 == env->b[y] && env->a[0] != 1)
// 		{
// 			while (a > 1)
// 			{
// 				if (env->a[0] - 1 == env->b[0])
// 					pa(env);
// 				rb(env);
// 				a--;
// 				i++;
// 			}
// 			pa(env);
// 			y = 0;
// 			b = 1;
// 		}
// 		if (b == 0)
// 		{
// 			y++;
// 			a++;
// 		}
// 		else
// 			a = 1;
// 		b = 0;
// 		while (i > 0)
// 		{
// 			if (env->a[0] - 1 == env->b[0])
// 				pa(env);
// 			rrb(env);
// 			i--;
// 		}
// 	}
// }


void	sort_big_main(t_env *env)
{
	env->x = 0;
	// sort_a_to_b_1(env);
	make_chunks(env);
	// sort_b_to_a(env);
	// big_sort(env);
	// sort_a_to_b(env);
}
