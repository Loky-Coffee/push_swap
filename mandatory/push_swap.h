/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 06:04:43 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/19 01:58:16 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define CHUNKS 8

/**
 * ----------------------------------------------------------------------
* @param sa (swap a): Swap the first 2 elements at the top of stack a.
* @param sb (swap b): Swap the first 2 elements at the top of stack b.
* @param ss : sa and sb at the same time.
-------------------------------------------------------------------------
* @param pa (push a): Take the first element at the top of b and put
			 it at the top of a.
* @param pb (push b): Take the first element at the top of a and put
			 it at the top of b.
-------------------------------------------------------------------------
* @param ra (rotate a): Shift up all elements of stack a by 1.
			Te.
* @param rb (rotate b): Shift up all elements of stack b by 1.
			The first element becomes the last one.
* @param rr : ra and rb at the same time.
-------------------------------------------------------------------------
* @param rra (reverse rotate a): Shift down all elements of stack a by 1.
* 			The last element becomes the first one.
* @param rrb (reverse rotate b): Shift down all elements of stack b by 1.
* 			The last element becomes the first one.
* @param rrr : rra and rrb at the same time.
-------------------------------------------------------------------------
*/
typedef struct s_env
{
	int			*a;
	int			*b;
	int			*sort;
	int			a_size;
	int			b_size;
	int			min;
	int			max;
	int			index;
	int			i;
	int			x;
	int			chunk_index;
	int			w;
	int			id;
	int			original;
	int			tails;
	int			tailsbuffer;
	int			search_first_nummer_up;
	int			search_first_nummer_down;
	int			search_small_result_first_nummmer;
	int			search_second_nummer_up;
	int			search_secont_nummer_down;
	int			search_small_result_secont_nummmer;
}	t_env;

void		sort_big_main(t_env *env);
void		sort_a_to_b(t_env *env);
void		print_stacks(t_env *env);
void		sort3(t_env *env);
void		make_chunks(t_env *env);
void		intex_stack_a(t_env *env);
void		make_sort_array(t_env *env);
void		sa(t_env *env);
void		sb(t_env *env);
void		ss(t_env *env);
void		pa(t_env *env);
void		pb(t_env *env);
void		ra(t_env *env);
void		rb(t_env *env);
void		rr(t_env *env);
void		rra(t_env *env);
void		rrb(t_env *env);
void		rrr(t_env *env);
void		sort_down_to_a(t_env *env, bool x);

#endif
