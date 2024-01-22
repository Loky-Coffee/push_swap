/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 06:04:43 by aalatzas          #+#    #+#             */
/*   Updated: 2024/01/22 17:02:11 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
# define NEXT_NUMBER_IST_UP 1
# define NEXT_NUMBER_IST_DOWN 0
# define ERROR 1
# define ONLY_FREE 0
# define CHUNKS 3
# define GREEN "\033[92m"
# define RED "\033[91m"
# define RESET "\033[0m"

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
	char		*line;
	char		**string_arg;
	int			a_size;
	int			b_size;
	int			index;
	int			i;
	int			x;
	int			w;
	int			id;
	int			div;
	int			db;
	int			original;
	int			tails;
	int			tailsbuffer;
	int			moves;
	int			search_first_nummer_up;
	int			search_first_nummer_down;
}	t_env;

void		intex_stack_a(t_env *env);
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
int			ft_is_int(char *str);
void		free_all(t_env *env, int fd);
void		spaceing(char **argv);
int			parse_args(int argc, char **argv, t_env *env);
int			not_2_time_same_nbr(t_env *env);
int			check_array_sortet(t_env *env);
int			parse_args_array(char **argv, t_env *env);
void		print_end_msg(t_env *env);

#endif
