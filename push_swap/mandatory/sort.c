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
	int i;

	i = env->a_size;
	while(i > 0)
	{
		if (env->a[0] < env->average_big && env->a[0] > env->average_Vsmall)
			pb(env);
		else
			ra(env);
		if (env->b[0] <= env->average_small && env->b[0] > env->average_Vsmall)
			rb(env);
		i--;
	}
	i = env->a_size;
	while(i > 0)
	{
		if (env->a[0] < env->average_Vbig && env->a[0] > env->average_VVsmall)
			pb(env);
		else
			ra(env);
		if (env->b[0] < env->average_small)
			rb(env);
		i--;
	}
	i = env->a_size;
	while(i > 0)
	{
		if (env->a[0] < env->average_VVsmall)
			pb(env);
		else
			ra(env);
		if (env->b[0] < env->average_Vsmall)
			rb(env);
		i--;
	}
	i = env->a_size;
	while(i > 0)
	{
		if (env->a[0] < env->average_VVbig)
			pb(env);
		else
			ra(env);
		if (env->b[0] < env->average_Vbig)
			rb(env);
		i--;
	}

	i = env->a_size;
	while (i != 0)
	{
		pb(env);
		i--;
	}
	
}

// void	sort_a_to_b(t_env *env)
// {
// 	env->i = 0;
// 	while (env->b_size >= 0)
// 	{
// 		if (env->a[0] < env->a[1])
// 			sa(env);
// 		else if (env->a[env->a_size - 1] > env->a[0])
// 			rra(env);
// 		else if (env->a[env->a_size - 1] < env->a[0] && env->a[0] > env->a[1])
// 			ra(env);
// 		else
// 			pa(env);
// 	}
// }
// void	sort_a_to_b(t_env *env)
// {
// 	env->i = 0;
// 	while (env->a_size > 2)
// 	{
// 		if (env->a[env->a_size - 1] < env->a[0])
// 			rra(env);
// 		else if (env->a[0] > env->a[1])
// 			sa(env);
// 		else if (env->b[0] > env->a[0])
// 		{
// 			pa(env);
// 			sa(env);
// 		}
// 		else if (env->a[0] < env->a[1] && env->a[0] < env->a[env->a_size - 1])
// 			pb(env);
// 	}
// }
// void	sort_a_to_b(t_env *env)
// {
// 	env->i = 0;
// 	while (env->a_size > 2)
// 	{
// 		if (env->a[0] > env->a[1] && env->a[0] > env->a[env->a_size - 1])
// 			ra(env);
// 		else if (env->a[0] < env->a[1] && env->a[0] < env->a[env->a_size - 1])
// 		{
// 			if (env->b[0] > env->a[0])
// 			{
// 				pa(env);
// 				if (env->a[0] > env->a[1])
// 					sa(env);
// 			}
// 			else
// 				pb(env);
// 		}
// 		else if (env->a[0] < env->a[env->a_size - 1] && env->a[0] > env->a[1])
// 			sa(env);
// 		else
// 			rra(env);
// 	}
// }



void	sort_big_main(t_env *env)
{
	env->x = 0;
	sort_b_to_a(env);
	// sort_a_to_b(env);
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