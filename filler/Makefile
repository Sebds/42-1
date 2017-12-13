#!/usr/bin/make -f
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsampre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 16:44:53 by nsampre           #+#    #+#              #
#    Updated: 2017/02/07 10:43:53 by nsampre          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	nsampre.filler

SRC				=	errors.c	\
					evil_strategy.c \
					get_input.c \
					is.c \
					main.c \
					memory.c \
					place_tools.c \
					visualizer.c \
					visualizer_init.c

INC				=	./includes/filler.h

OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

LIBFTPRINTF		=	./libftprintf/libftprintf.a
LIBINC			=	-I./libftprintf/includes
LIBLINK			=	-L./libftprintf -lftprintf

LIBMLX			=	./libmlx/libmlx.a
MLXINC			=	-I./libmlx/
MLXLINK			=	-L./libmlx -lmlx

SRC_PATH		=	./src/
INC_PATH		=	./includes/
OBJ_PATH		=	./obj/

all:			$(NAME)

$(NAME):		obj	libftprintf libmlx $(OBJ)
				@$(CC) $(LIBLINK) $(MLXLINK) -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)
				@printf "\n=> \x1B[33mCompiling nsampre.filler...\x1b[37m"
				@printf "\n=> \x1B[32mnsampre.filler ready to compete ! ( ͡° ͜ʖ ͡°) \x1B[37m\n"

obj:
				@mkdir -p $(OBJ_PATH)

libftprintf:	$(LIBFTPRINTF)

libmlx:			$(LIBMLX)

$(LIBFTPRINTF):
				@make -C ./libftprintf
				@printf "=> \e[38;5;208mMaking nsampre.filler /obj dir... \x1B[37m"

$(LIBMLX):
				@make -C ./libmlx

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@$(CC) $(CFLAGS) $(LIBINC) $(MLXINC) -I $(INC_PATH) -o $@ -c $<
				@printf "\e[38;5;208m▒\e[0m"

clean:
				@rm -rf $(OBJ_PATH)
				@printf "=> \x1B[31mDeleting nsampre.filler .obj files...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libftprintf .obj files...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"
				@make -C ./libftprintf clean
				@make -C ./libmlx clean

fclean:			clean
				@printf "=> \x1B[31mDeleting nsampre.filler...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libftprintf.a.. \x1B[37m\n"
				@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
				@rm -rf $(NAME)
				@make -C ./libftprintf fclean

re:				fclean all

norme:
				@norminette ./src/
				@norminette ./includes/
				@make norme -C libftprintf
