# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2016/12/15 15:27:44 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker
FLAGS	=	-c -Wall -Wextra -Werror
CFILES	=	checker.c		\
			new_lib.c		\


SRCDIR  =	srcs/
HDIR	=	includes/

.PHONY: all $(NAME) main complib clean flcean re

all: $(NAME)

$(NAME):
	@ gcc $(addprefix $(SRCDIR), $(CFILES)) -o $@ -I $(HDIR) -L. lib/libftprintf.a

clean:
	@ /bin/rm -f $(OFILES)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all