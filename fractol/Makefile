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

NAME			=	fractol

SRC				=	main.c	\
					init_env.c	\
					init_mlx.c	\
					init_kernel.c	\
					build_kernel.c	\
					run_kernel.c	\
					key_events.c	\
					mouse_events.c	\
					box_info.c	\

OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -O3

INC				=	./includes/fractol.h

LIBFTPRINTF		=	./libftprintf/libftprintf.a
LIBINC			=	-I./libftprintf/includes
LIBLINK			=	-L./libftprintf -lftprintf

MLX				=	./libmlx/libmlx.a
MLXINC			=	-I./libmlx/
MLXLINK			=	-L./libmlx -lmlx -framework OpenGL -framework AppKit -framework OpenCL

SRC_PATH		=	./src/
INC_PATH		=	./includes/
OBJ_PATH		=	./obj/

all:			$(NAME)

$(NAME):		libftprintf libmlx obj $(OBJ)
				@printf "\n=> \x1B[33mCompiling fractol...\x1b[37m"
				@$(CC) $(FLAGS) $(LIBLINK) $(MLXLINK) -o $(NAME) $(OBJ)
				@printf "\n=> \x1B[32mfractol ready to take a trip ! ( ͡° ͜ʖ ͡°) \x1B[37m\n"

obj:
				@mkdir -p $(OBJ_PATH)
				@printf "=> \e[38;5;208mMaking fractol /obj dir... \x1B[37m"

mlx:			$(MLX)

libftprintf:	$(LIBFTPRINTF)

$(MLX):
				@make -C ./libmlx

$(LIBFTPRINTF):
				@make -C ./libftprintf


$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@$(CC) $(FLAGS) $(LIBINC) $(MLXINC) -I $(INC_PATH) -o $@ -c $<
				@printf "\e[38;5;208m▒\e[0m"

clean:
				@rm -rf $(OBJ_PATH)
				@printf "=> \x1B[31mDeleting fractol .obj files...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libftprintf .obj files...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"
				@make -C ./libftprintf clean

fclean:			clean
				@printf "=> \x1B[31mDeleting fractol...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libftprintf.a.. \x1B[37m\n"
				@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
				@rm -rf $(NAME)
				@make -C ./libftprintf fclean
				@make -C ./libmlx clean

re:				fclean all

norme:
				@norminette ./src/
				@norminette ./includes/

.PHONY		:	all re clean fclean
