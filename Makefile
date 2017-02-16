# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2017/02/15 14:46:43 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	2checker
FLAGS	=	-c -Wall -Wextra -Werror
CFILES	=	checker.c			\
			new_lib.c			\
			op_spr.c			\
			parse.c				\
			arr_funx.c			\
			str_funx.c			\
			helpers.c			\
			test_mallocwrap.c	


SRCDIR  =	srcs/
HDIR	=	includes/

.PHONY: all $(NAME) clean flcean re

all: $(NAME)

$(NAME):
	gcc test/test.c -I $(HDIR) -L. lib/libftprintf.a -o 3main
	gcc $(addprefix $(SRCDIR), $(CFILES)) -o $@ -I $(HDIR) -L. lib/libftprintf.a

ps:
	gcc srcs/push_swap.c $(addprefix $(SRCDIR), 	\
		new_lib.c			\
		op_spr.c			\
		parse.c				\
		arr_funx.c			\
		str_funx.c			\
		helpers.c			\
		stack_calculation.c	\
		strategies.c		\
		post_sort_funx.c)	\
		-o 1push_swap -I $(HDIR) -L. lib/libftprintf.a

lib:
	make re -C ~/printf/submission_dir/
	cp ~/printf/submission_dir/libftprintf.a ./lib
	make fclean -C ~/printf/submission_dir/


clean:
	@ /bin/rm -f $(OFILES)


fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all