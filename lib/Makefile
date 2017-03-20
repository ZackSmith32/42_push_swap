# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 16:32:25 by zsmith            #+#    #+#              #
#    Updated: 2017/03/20 11:19:56 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FLAGS	=	-c -Wall -Wextra -Werror
CFILES	=	ft_printf.c			\
			funx__flag.c		\
			funx__help.c		\
			funx__list.c		\
			funx__pop.c			\
			funx__pop2.c		\
			funx__wide.c		\
			funx_d.c			\
			funx_b.c			\
			funx_o.c			\
			funx_pi.c			\
			funx_s.c			\
			funx_c.c			\
			funx_u.c			\
			funx_x.c			\
			glob.c				\

SRCDIR  =	srcs/
HDIR	=	includes/
OFILES	=	$(CFILES:.c=.o)

.PHONY: all $(NAME) main complib clean flcean re

all: $(NAME)

$(NAME): comp_printf
	make re -C ./includes/libft 
	libtool -static -o $@ libfunc.a ./includes/libft/libft.a

comp_printf:
	gcc $(FLAGS) $(addprefix $(SRCDIR),$(CFILES))
	ar rc libfunc.a $(OFILES)

clean:
	/bin/rm -f $(OFILES)
	rm -f libfunc.a

fclean: clean
	@ /bin/rm -f $(NAME)
	make fclean -C ./includes/libft

re: fclean all