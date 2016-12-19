# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2016/12/16 17:16:37 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker
FLAGS	=	-c -Wall -Wextra -Werror
CFILES	=	checker.c		\
			new_lib.c		\
			get_next_line.c	\
			op_spr.c		\
			test_mallocwrap.c\


SRCDIR  =	srcs/
HDIR	=	includes/

.PHONY: all $(NAME) clean flcean re

all: $(NAME)

$(NAME):
	@ gcc test/test.c -I includes/libft.h -L. lib/libftprintf.a -o main
	@ gcc $(addprefix $(SRCDIR), $(CFILES)) -o $@ -I $(HDIR) -L. lib/libftprintf.a

clean:
	@ /bin/rm -f $(OFILES)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all