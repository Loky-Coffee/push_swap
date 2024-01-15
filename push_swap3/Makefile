# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 06:04:33 by aalatzas          #+#    #+#              #
#    Updated: 2024/01/14 06:42:40 by aalatzas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = #-Wall -Werror -Wextra -g

################################################################################
####		 	 PUSH_SWAP_MANDATORY_PART_RULES			   #####
################################################################################

NAME = push_swap
OBJ_DIR = mandatory/obj/
SRC_DIR = mandatory/

SRC = \
			$(SRC_DIR)$(NAME).c \
			$(SRC_DIR)sort.c \
			$(SRC_DIR)_push_pa_pb.c \
			$(SRC_DIR)_swap_sa_sb_ss.c \
			$(SRC_DIR)_rotate_ra_rb_rr.c \
			$(SRC_DIR)_reverse_rotate_rra_rrb_rrr.c \
			$(SRC_DIR)first_sort.c \

OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(NAME)
$(NAME): libft $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT1)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

t1: $(NAME)
		./$(NAME) 2 1 3 6 5 8 7 4 9 0
t2: $(NAME)
		./$(NAME) -52 -43 -20 -1 0 1 2 3 4 5 6 7 8 9 10 11 12 13 \
			14 25 30 200 850 5000 10000 100000 1000000 10000000 \
			100000000 1000002

t: $(NAME)
		push_swap_visualizer/build/bin/./visualizer

re: fclean all

install_test:
	git clone https://github.com/o-reo/push_swap_visualizer.git
	cd push_swap_visualizer
	mkdir build
	cd build
	cmake ..
	make
################################################################################
####			 PUSH_SWAP_BONUS_PART_RULES 			   #####
################################################################################
# NAME_BONUS = push_swap_bonus
# OBJ_DIR_BONUS = bonus/obj/
# SRC_DIR_BONUS = bonus/

# SRC_BONUS = \
# 			$(SRC_DIR_BONUS)$(NAME_BONUS).c \

# OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(notdir $(SRC_BONUS:.c=.o)))

# bonus: $(NAME_BONUS)
# $(NAME_BONUS): libft $(OBJ_BONUS)
# 	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT1)

# $(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
# 	@mkdir -p $(OBJ_DIR_BONUS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean_bonus:
# 	@rm -f $(OBJ_BONUS)

# fclean_bonus: clean_bonus
# 	@rm -f $(NAME_BONUS)


# t1: $(NAME)
# 		./$(NAME) 2 1 3 6 5 8 7 4 9 0
# t2: $(NAME)
# 		./$(NAME) -52 -43 -20 -1 0 1 2 3 4 5 6 7 8 9 10 11 12 13 \
			14 25 30 200 850 5000 10000 100000 1000000 10000000 \
			100000000 1000000000

# re_bonus: fclean all

# testb: all
# 	tb1 tb2

################################################################################
####				   LIBFT_RULES 				   #####
################################################################################

LIBFT1 = ./libft/libft.a
LIBFT_OBJ_DIR = libft/obj/
LIBFT_SRC_DIR = libft/src/

$(LIBFT_OBJ_DIR)%.o: $(LIBFT_SRC_DIR)%.c
	@mkdir -p $(LIBFT_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
libft:
	@cd libft && make
re_libft:
	@cd libft && make re
clean_libft:
	@cd libft && make clean
fclean_libft: clean_libft
	@cd libft && make fclean

################################################################################
####				  EXTRA_RULES 				   #####
################################################################################

.PHONY: all clean fclean re start test libft re_libft clean_libft fclean_libft \
		mlx clean_mlx tb t re_bonus all_bonus clean_bonus fclean_bonus \
		re_bonus test_bonus
fcleanall: fclean fclean_libft
		rm -f libft.a
		rm -f libft.h
