# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2017/03/16 23:27:55 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker
FLAGS	=	#-Wall -Wextra -Werror
CFILES	=	checker.c			\
			new_lib.c			\
			op_spr.c			\
			parse.c				\
			arr_funx.c			\
			str_funx.c			\
			helpers.c			\
			checker_support.c	\
			parse_two.c			\

			# test_mallocwrap.c	\

PSFILES =	push_swap.c			\
			new_lib.c			\
			op_spr.c			\
			parse.c				\
			arr_funx.c			\
			str_funx.c			\
			helpers.c			\
			stack_calculation.c	\
			strategies.c		\
			post_sort_funx.c	\
			ck_srt_ascend.c		\
			print_funx.c		\
			parse_two.c			\

OFILES =	push_swap.o			\
			new_lib.o			\
			op_spr.o			\
			parse.o				\
			arr_funx.o			\
			str_funx.o			\
			helpers.o			\
			stack_calculation.o	\
			strategies.o		\
			post_sort_funx.o	\
			ck_srt_ascend.o		\
			checker.o			\
			print_funx.o		\
			helpers.o			\
			get_next_line.o		\
			free_gnl.o			\
			checker_support.o	\
			parse_two.o			\

SRCDIR  =	srcs/
HDIR	=	includes/

.PHONY: all $(NAME) clean flcean re

all: $(NAME)

$(NAME): push_swap
	gcc $(FLAGS) $(addprefix $(SRCDIR), $(CFILES)) -o $@ -I $(HDIR) \
		-L. lib/libftprintf.a

push_swap: libs
	gcc $(FLAGS) $(addprefix $(SRCDIR), $(PSFILES)) -o $@ -I $(HDIR) \
		-L. lib/libftprintf.a
	
libs:
	make -C ./lib

clean:
	/bin/rm -f $(addprefix $(SRCDIR), $(OFILES))

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f push_swap
	make fclean -C ./lib

re: fclean all