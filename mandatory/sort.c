/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:50:02 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/11 15:56:25 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_to_a(t_env *env)
{
	// if (env->b[0] < env->b[1] && env->a[0] > env->a[1] && env->a[0] < env->a[env->a_size - 1] && env->a[0] < env->a[1] / 2)
	// 	ss(env);
	// else if (env->b[0] > env->b[env->b_size] && env->b[1] < env->b[env->b_size] && env->a[0] > env->a[env->a_size] && env->a[env->a_size] < env->a[1])
	// 	rrr(env);
	// else if (env->b[0] > env->a[1] && env->a[0] > env->a[env->a_size - 1] && env->a[0] > env->a[1] && env->a[0] > env->a[env->a_size] * 2)
	// 	rr(env);
	if (env->a_size == 0)
	{
		pa(env);
		pa(env);
	}

	if (env->a[0] > env->a[1] && env->a[0] / 2 < env->a[1])
	{
		// printf("1\n");
		// fflush(stdout);
		if (env->a[1] > env->a[2])
		{
			ra(env);
			sa(env);
			rra(env);
		}
		else
			sa(env);
	}
	else if ((env->a[0] > env->a[2] && env->a[0] > env->a[env->a_size - 2]) || (env->a[0] * 2 > env->a[1] && env->a[0] > env->a[2]))
	{
		// printf("2\n");
		// fflush(stdout);
		if (env->a[0] > env->a[env->a_size - 2])
		{
			rra(env);
			sa(env);
			ra(env);
			ra(env);
		}
		else
			ra(env);
	}
	else if (env->a[0] > env->a[1])
	{
		// printf("3\n");
		// fflush(stdout);
		sa(env);
		if (env->a[1] > env->a[2])
		{
			ra(env);
			sa(env);
			rra(env);
		}
	}
	else if (env->a[env->a_size - 1] < env->a[env->a_size - 2] && env->a_size > 2 )
	{
		// printf("4\n");
		// fflush(stdout);
		rra(env);
		rra(env);
		sa(env);
		ra(env);
		ra(env);
	}
	if (env->a[0] > env->a[1] && env->a[0] > env->a[env->a_size - 2])
	{
		// printf("5\n");
		// fflush(stdout);
		ra(env);
	}
	int i;

	i = 0;
	// while (env->b[0] > env->a[0])
	// {
	// 	ra(env);
	// 	i++;
	// }
	pa(env);
	// if (i != 0)
	// 	while (i >= 0)
	// 	{
	// 		rra(env);
	// 		i--;
	// 	}

}

void	sort_a_to_b(t_env *env)
{
	env->i = 0;
	while (env->i <= env->a_size)
	{
		if (env->a[env->i] < env->average_big)
			env->x = 1;
		env->i++;
	}
	// if (env->b[0] > env->average_big && env->x == 1)
	// {
	// 	pa(env);
	// 	sa(env);
	// }
	if (env->a[0] > env->average_big && env->b[0] < env->average_small)
		rr(env);
	else if (env->b[0] < env->average_small && env->x != 1)
		rb(env);
	else if (env->a[0] > env->average_big)
		ra(env);
	else if (env->a[0] < env->average_big)
		pb(env);
}
void	sort_big_main(t_env *env)
{
	env->x = 0;
	while (env->a_size > 2)
		sort_a_to_b(env);
	// while (env->b_size > 0)
	// {
	// 	sort_b_to_a(env);
	// }
}

// void	sort_small_main(t_env *env)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	printf("env->a[env->a_size + 1] %d\n", env->a[env->a_size + 1]);
// 	printf("env->a[env->a_size] %d\n", env->a[env->a_size - 1]);
// 	printf("env->a[0] %d\n", env->a[0]);
// 	while (i < env->a_size)
// 	{
// 		if (env->a[0] > env->a[1])
// 			sa(env);
// 		else
// 			rra(env);
// 		i++;
// 	}
// }


// void	print_stacks(t_env *env)
// {
// 	int i;
// 	int size;

// 	size = (env->a_size + env->b_size) - 1;
// 	i = 0;

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
// 		ft_putstr_fd("|    ", 1);
// 		ft_putnbr_fd(env->a_size, 1);
// 		ft_putstr_fd("    |    ", 1);
// 		ft_putnbr_fd(env->b_size, 1);
// 		ft_putstr_fd("    |\n", 1);
// 	ft_putstr_fd("--------------------\n", 1);
// }

// void	sort_big_main(t_env *env)
// {
// 	int i;

// 	i = 0;

// 	while (i >= 0)
// 	{
// 		if (env->b_size == 0)
// 		{
// 			ft_putstr_fd("\n--------START--------\n", 1);
// 			print_stacks(env);
// 		}
// 		ft_putstr_fd("\n\n|-------------------|\n       1 ", 1);
// 		pb(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n       2 ", 1);
// 		pb(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n       3 ", 1);
// 		pb(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n       4 ", 1);
// 		sa(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n       5 ", 1);
// 		sb(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n       6 ", 1);
// 		ss(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n       7 ", 1);
// 		ra(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n       8 ", 1);
// 		rb(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n       9 ", 1);
// 		rr(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n      10 ", 1);
// 		rra(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n      11 ", 1);
// 		rrb(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n      12 ", 1);
// 		rrr(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);

// 		ft_putstr_fd("\n\n|-------------------|\n      13 ", 1);
// 		pa(env);
// 		ft_putstr_fd("|-------------------|\n", 1);
// 		print_stacks(env);
// 		i--;
// 	}
// }