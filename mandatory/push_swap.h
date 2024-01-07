/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 06:04:43 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/07 08:44:49 by aalatzas         ###   ########.fr       */
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

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int		*arr;
	int		size;
}	t_stack;

/**
* @param sa (swap a): Swap the first 2 elements at the top of stack a.
* @param sb (swap b): Swap the first 2 elements at the top of stack b.
* @param ss : sa and sb at the same time.
* @param pa (push a): Take the first element at the top of b and put
			 it at the top of a.
* @param pb (push b): Take the first element at the top of a and put
			 it at the top of b.
* @param ra (rotate a): Shift up all elements of stack a by 1.
			The first element becomes the last one.
* @param rb (rotate b): Shift up all elements of stack b by 1.
			The first element becomes the last one.
* @param rr : ra and rb at the same time.
* @param rra (reverse rotate a): Shift down all elements of stack a by 1.
* 			The last element becomes the first one.
* @param rrb (reverse rotate b): Shift down all elements of stack b by 1.
* 			The last element becomes the first one.
* @param rrr : rra and rrb at the same time.
*/
typedef struct s_moves
{
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
}	t_moves;

typedef struct s_env
{
	int		*a;
	int		*b;
	char	**ar;
	char	**br;
	int		a_size;
	int		b_size;
	t_moves	*moves;
}	t_env;

#endif