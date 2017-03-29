# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2017/03/22 13:10:23 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CHECKER	=	checker
FLAGS	=	-Wall -Wextra -Werror
FSAN	=	#-fsanitize=address -g

KFILES	=	checker.o			\
			new_lib.o			\
			op_spr.o			\
			arr_funx.o			\
			str_funx.o			\
			helpers.o			\
			checker_support.o	\
			parse_two.o			\
			globals.o			\


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
			test_mallocwrap.c	\
			globals.c			\

LIBS	=	libft/libft.a				
LIBS	+=	libftprintf.a

SRCDIR  =	srcs/
OBJDIR	=	obj/
HDIR	=	includes/
LIBDIR	=	libdir/
LIBFILES=	$(addprefix $(LIBDIR), $(LIBS))
OFILES	=	$(addprefix $(OBJDIR), $(CFILES:.c=.o))

.PHONY: all $(NAME) clean flcean re

all: $(NAME) $(CHECKER) 

$(OBJDIR)%.o : $(SRCDIR)%.c
	gcc $(FLAGS) -I $(HDIR) -c $< -o $@ $(FSAN)

$(NAME): $(OFILES) 
	make -C ./libdir
	make -C ./libdir/libft
	gcc  $(FSAN) -I $(HDIR) -L. $(LIBFILES) \
		$(addprefix $(OBJDIR), $(PSFILES)) -o $@

$(CHECKER): $(OFILES)
	make -C ./libdir
	make -C ./libdir/libft
	gcc $(FSAN) $(addprefix $(OBJDIR), $(KFILES)) \
		-I $(HDIR) -L. $(LIBFILES) -o $@
	
clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f checker

re: fclean all


























