# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2017/03/21 15:39:42 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
FLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g
KFILES	=	checker.o			\
			new_lib.o			\
			op_spr.o			\
			arr_funx.o			\
			str_funx.o			\
			helpers.o			\
			checker_support.o	\
			parse_two.o			\
			globals.o			\

			# test_mallocwrap.c	\

PSFILES =	push_swap.o			\
			new_lib.o			\
			op_spr.o			\
			arr_funx.o			\
			str_funx.o			\
			helpers.o			\
			stack_calculation.o	\
			strategies.o		\
			post_sort_funx.o	\
			ck_srt_ascend.o		\
			print_funx.o		\
			parse_two.o			\
			globals.o			\

CFILES =	push_swap.c			\
			new_lib.c			\
			op_spr.c			\
			arr_funx.c			\
			str_funx.c			\
			helpers.c			\
			stack_calculation.c	\
			strategies.c		\
			post_sort_funx.c	\
			ck_srt_ascend.c		\
			checker.c			\
			print_funx.c		\
			helpers.c			\
			checker_support.c	\
			parse_two.c			\
			globals.c			\

SRCDIR  =	srcs/
OBJDIR	=	obj/
HDIR	=	includes/
OFILES	=	$(addprefix $(OBJDIR), $(CFILES:.c=.o))

.PHONY: all $(NAME) clean flcean re

all: $(NAME) checker

$(OBJDIR)%.o : $(SRCDIR)%.c 
	gcc $(FLAGS) -I $(HDIR) -c $< -o $@ 

$(NAME): $(OFILES)
	gcc $(addprefix $(OBJDIR), $(PSFILES)) -I $(HDIR) -L. lib/libftprintf.a -o $@

checker: $(OFILES)
	gcc $(addprefix $(OBJDIR), $(KFILES)) -I $(HDIR) -L. lib/libftprintf.a -o $@
	
libs:
	make -C ./lib

clean:
	/bin/rm -f $(OBJFILES)
	make clean -C ./lib

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f checker
	make fclean -C ./lib

re: fclean all


























