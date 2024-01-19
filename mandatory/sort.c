/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:50:02 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/19 04:38:33 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_env *env)
{
	int	i;
	int	size;

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

//sort funktion active only wenn you give 3 aquments.
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

//sort funktion active only wenn you give 5 aquments.
void	sort5(t_env *env)
{
	pb(env);
	pb(env);
	if (env->b[0] < env->b[1])
		rb(env);
	sort3(env);
	pa(env);
	if (env->a[0] < env->a[1] && env->a[0] > env->a[2])
		rra(env);
	if (env->a[0] < env->a[1])
		ra(env);
}

//find the position from the -1 number from ctacka[0] what i need in stack b and
//and return the less position from up or from down.
static int search_position_1_nummer(t_env *env, bool fd)
{
	int	count;

	count = 0;
	if(fd == 1)
	{
		while (env->a[0] - 1 != env->b[count])
			count++;
		return(count);
	}
	count = env->b_size;
	if(fd == 0)
	{
		while (env->a[0] - 1 != env->b[count])
			count--;
		return(env->b_size - count);
	}
	return (0);
}

//find the position from the -2 number from ctacka[0] what i need in stack b and
//and return the less position from up or from down.
static int search_position_2_nummer(t_env *env, bool up_or_down)
{
	int	count;

	count = 0;
	if(up_or_down == 1)
	{
		while (env->a[0] - 2 != env->b[count])
			count++;
		return(count);
	}
	else if(up_or_down == 0)
	{
		count = env->b_size;
		while (env->a[0] - 2 != env->b[count])
			count--;
		return(env->b_size - count);
	}
	return (0);
}
void sort_up_to_a(t_env *env, bool x)
{
	if (x == 1)
	{
		while (env->b_size > 0)
		{
			if (env->a[0] - 1 == env->b[0])
			{
				pa(env);
				break ;
			}
			else
				rb(env);
		}
	}
	else
		while (x == 0  && env->b_size > 0)
		{
			if (env->a[0] - 2 == env->b[0])
			{
				pa(env);
				while (1)
				{
					if (env->search_first_nummer_up <= env->search_first_nummer_down)
					{
						if (env->a[0] + 1 == env->b[0])
						{
							pa(env);
							sa(env);
							break ;
						}
						else
							rb(env);
					}
					else if (env->search_first_nummer_up > env->search_first_nummer_down)
					{
						if (env->a[0] + 1 == env->b[0])
						{
							pa(env);
							sa(env);
							break ;
						}
						else
							rrb(env);
					}
				}
				break ;
			}
			else
				rb(env);
		}
}

void	sort_down_to_a(t_env *env, bool x)
{
	if (x == 1)
	{
		while (x == 1)
		{
			if (env->a[0] - 1 == env->b[0])
			{
				pa(env);
				break ;
			}
			else
				rrb(env);
		}
	}
	else
		while (x == 0 && env->b_size > 0)
		{
			if (env->a[0] - 2 == env->b[0])
			{
				pa(env);
				while (1)
				{
					if (env->search_first_nummer_up <= env->search_first_nummer_down)
					{
						if (env->a[0] + 1 == env->b[0])
						{
							pa(env);
							sa(env);
							break ;
						}
						else
							rb(env);
					}
					else if (env->search_first_nummer_up > env->search_first_nummer_down)
					{
						if (env->a[0] + 1 == env->b[0])
						{
							pa(env);
							sa(env);
							break ;
						}
						else
							rrb(env);
					}
				}
				break;
			}
			else
				rrb(env);
		}
}

void	sort_big_main(t_env *env)
{
	env->x = 0;
	// int i = 10;
	make_sort_array(env);
	if (env->a_size == 5)
		sort5(env);
	else if (env->a_size == 3)
		sort3(env);
	else
	{
		// sort_a_to_b(env);
		make_chunks(env);
		env->chunk_index = 2;
		while (env->b_size > 0)
		{
			env->search_first_nummer_up = search_position_1_nummer(env, 1);
			env->search_first_nummer_down = search_position_1_nummer(env, 0);
			env->search_second_nummer_up = search_position_1_nummer(env, 1);
			env->search_secont_nummer_down = search_position_2_nummer(env, 0);
			if (env->search_first_nummer_up <= env->search_first_nummer_down)
				env->search_small_result_first_nummmer = env->search_first_nummer_up;
			else
				env->search_small_result_first_nummmer = env->search_first_nummer_down;
			if (env->search_second_nummer_up <= env->search_secont_nummer_down)
				env->search_small_result_secont_nummmer = env->search_second_nummer_up;
			else
				env->search_small_result_secont_nummmer = env->search_secont_nummer_down;
			if (env->search_small_result_first_nummmer <= env->search_small_result_secont_nummmer)
			{
				if (env->search_first_nummer_up <= env->search_first_nummer_down)
					sort_up_to_a(env, 1);
				else
					sort_down_to_a(env, 1);
			}
			else if (env->search_small_result_first_nummmer > env->search_small_result_secont_nummmer)
			{
				if (env->search_second_nummer_up < env->search_secont_nummer_down)
					sort_up_to_a(env, 0);
				else
					sort_down_to_a(env, 0);
			}
		}
	}
}
