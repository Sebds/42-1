#!/usr/bin/make -f
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsampre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 16:44:53 by nsampre           #+#    #+#              #
#    Updated: 2017/01/02 16:45:47 by nsampre          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	fdf

SRC				=	color.c	\
					draw.c	\
					draw_tools.c	\
					init_mlx.c	\
					main.c	\
					parse.c	\
					swap_tool.c	\

OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

LIBFTPRINTF		=	./libftprintf/libftprintf.a
LIBINC			=	-I./libftprintf/includes
LIBLINK			=	-L./libftprintf -lftprintf

MLX				=	./libmlx/libmlx.a
MLXINC			=	-I./libmlx/
MLXLINK			=	-L./libmlx -lmlx -framework OpenGL -framework AppKit

SRC_PATH		=	./src/
INC_PATH		=	./includes/
OBJ_PATH		=	./obj/

all:			$(NAME)

$(NAME):		obj libftprintf mlx $(OBJ)
					@$(CC) $(LIBLINK) $(MLXLINK) -o $(NAME) $(OBJ)
					@printf "\n=> \x1B[33mCompiling fdf...\x1b[37m"
					@printf "\n=> \x1B[32mfdf done !\x1B[37m\n"

obj:
					@mkdir -p $(OBJ_PATH)

libftprintf:		$(LIBFTPRINTF)

mlx:					$(MLX)

$(LIBFTPRINTF):
					@make -C ./libftprintf
					@printf "=> \e[38;5;208mMaking fdf/obj dir... \x1B[37m"

$(MLX):
					@make -C ./libmlx

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
					@$(CC) $(CFLAGS) $(LIBINC) $(MLXINC) -I $(INC_PATH) -o $@ -c $<
					@printf "\e[38;5;208m▒\e[0m"

clean:
					@rm -rf $(OBJ_PATH)
					@printf "=> \x1B[31mDeleting fdf .obj files...\x1B[37m\n"
					@printf "=> \x1B[31mDeleting libftprintf .obj files...\x1B[37m\n"
					@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"
					@printf "=> \x1B[31mDeleting libmlx .obj files...\x1B[37m\n"
					@make -C ./libftprintf clean
					@make -C ./libmlx clean

fclean:			clean
					@printf "=> \x1B[31mDeleting fdf...\x1B[37m\n"
					@printf "=> \x1B[31mDeleting libftprintf.a.. \x1B[37m\n"
					@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
					@printf "=> \x1B[31mDeleting libmlx.a.. \x1B[37m\n"
					@rm -rf $(NAME)
					@make -C ./libftprintf fclean
					@make -C ./libmlx clean

re:				fclean all

norme:
					@norminette ./src/
					@norminette ./includes/
