#!/usr/bin/make -f
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsampre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 16:44:53 by nsampre           #+#    #+#              #
#    Updated: 2017/03/09 22:52:24 by nsampre          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	lem-in

SRC				=	dead_ends.c	\
					get_input.c	\
					matrix.c	\
					parse.c	\
					pattern.c	\
					solve.c	\
					solve_history.c	\
					solve_tools.c	\
					print.c	\
					position.c	\
					next_room.c	\
					main.c	\
					tools.c	\

INC				=	./includes/lem_in.h

OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
#FLAGS			+=	-g -fsanitize=thread

LIBFTPRINTF		=	./libftprintf/libftprintf.a
LIBINC			=	-I./libftprintf/includes
LIBLINK			=	-L./libftprintf -lftprintf

SRC_PATH		=	./src/
INC_PATH		=	./includes/
OBJ_PATH		=	./obj/

all:			$(NAME)

$(NAME):		obj	libftprintf $(OBJ)
				@$(CC) $(FLAGS) $(LIBLINK) -o $(NAME) $(OBJ)
				@printf "\n=> \x1B[33mCompiling lem-in...\x1b[37m"
				@printf "\n=> \x1B[32mlem-in ready to le(t the)m-in ! ( ͡° ͜ʖ ͡°) \x1B[37m\n"

obj:
				@mkdir -p $(OBJ_PATH)

libftprintf:	$(LIBFTPRINTF)

$(LIBFTPRINTF):
				@make -C ./libftprintf
				@printf "=> \e[38;5;208mMaking lem-in /obj dir... \x1B[37m"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@$(CC) $(FLAGS) $(LINLINK) $(LIBINC) -I $(INC_PATH) -o $@ -c $<
				@printf "\e[38;5;208m▒\e[0m"

clean:
				@rm -rf $(OBJ_PATH)
				@printf "=> \x1B[31mDeleting lem-in .obj files...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libftprintf .obj files...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"
				@make -C ./libftprintf clean

fclean:			clean
				@printf "=> \x1B[31mDeleting lem-in...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libftprintf.a.. \x1B[37m\n"
				@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
				@rm -rf $(NAME)
				@make -C ./libftprintf fclean

re:				fclean all

norme:
				@norminette ./src/
				@norminette ./includes/

.PHONY		:	all re clean fclean
