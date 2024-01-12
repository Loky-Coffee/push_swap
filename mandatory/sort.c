/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:50:02 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/12 23:52:01 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_to_a(t_env *env)
{
	int i;


	//nur grun und grundhellblau
	i = env->a_size;
	while(i > 0)
	{
		if (env->a[0] < env->average_big && env->a[0] > env->average_vsmall)
			pb(env);
		else
			ra(env);
		if (env->b[0] < env->average_small && env->b[0] > env->average_vsmall && env->b[0] < env->b[1])
			rb(env);
		i--;
	}

	//yelb hellgrun obern , hellblaublau unten
	i = env->a_size;
	while(i > 0)
	{
		if (env->a[0] < env->average_vbig && env->a[0] > env->average_vvsmall)
			pb(env);
		else
			ra(env);
		if (env->b[0] < env->average_small)
			rb(env);
		i--;
	}

	//Dunkelblau
	i = env->a_size;
	while(i > 0)
	{
		if (env->a[0] <= env->average_vvsmall && env->a[0] < env->average_vsmall)
			pb(env);
		else
			ra(env);
		if (env->b[0] <= env->average_vsmall && env->b[env->b_size] <= env->average_vsmall)
			rb(env);
		i--;
	}

	// printf("LALALALLA");
	// fflush(stdout);
	i = env->a_size;
	while(i > 0)
	{
		if (env->a[0] <= env->average_vvbig)
			pb(env);
		else
			ra(env);
		if (env->b[0] < env->average_small && env->b[0] > env->average_big)
			rb(env);
		i--;
	}

	//ROT
	i = env->a_size;
	while (i > 2)
	{
		pb(env);
		// if (env->b[0] < env->b[1])
		// 	rb(env);
		i--;
	}

	if (env->a[0] > env->a[1])
		sa(env);

	i = env->b_size;
	// int x = 0;
	while(env->a_size != env->a_size + env->b_size)
	{
		if (env->a[0] > env->b[0])
		{
			pa(env);
			ra(env);
		}
		if (env->a[0] < env->b[0])
		{
			rb(env);
		}
		if (env->b[0] == env->a[0] - 1)
			rra(env);
		else
			pa(env);
	}
	i = 0;
	while (i <= env->a_size)
	{
		if (env->a[i] > env->a[i+1])
			sort_b_to_a(env);
		if (i == env->a_size - 1)
			exit (0);
		i++;
	}

}




		// if ((env->b[0] - 1) == env->b[1] || (env->b[0] - 1) == env->b[2] || (env->b[0] - 1) == env->b[3] \
		// || (env->b[0] - 1) == env->b[4])
		// {
		// 	if ((env->b[0] - 1) == env->b[2] || (env->b[0] - 1) == env->b[3] || (env->b[0] - 1) == env->b[4])
		// 	{
		// 		if ((env->b[0] - 1) == env->b[3] || (env->b[0] - 1) == env->b[4])
		// 		{
		// 			if ((env->b[0] - 1) == env->b[4])
		// 				sb(env);
		// 			sb(env);
		// 		}
		// 		sb(env);
		// 	}
		// 	else
		// 		sb(env);
		// }
		// if ((env->a[0]) > env->a[1] || (env->a[0]) > env->a[2] || (env->a[0]) > env->a[3] \
		// || (env->a[0]) > env->a[4])
		// {
		// 	if ((env->a[0]) > env->a[2] || (env->a[0]) > env->a[3] || (env->a[0]) > env->a[4])
		// 	{
		// 		if ((env->a[0]) > env->a[3] || (env->a[0]) > env->a[4])
		// 		{
		// 			if ((env->a[0]) > env->a[4])
		// 				sa(env);
		// 			sa(env);
		// 		}
		// 		sa(env);
		// 	}
		// 	else
		// 		sa(env);
		// }


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