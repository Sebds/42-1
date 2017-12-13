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

NAME			=	ft_ls

SRC				=	argv_list_dir.c		\
					argv_list_file.c	\
					ft_ls.c				\
					get.c				\
					handle_argv.c		\
					handle_option.c		\
					init.c				\
					list.c				\
					memory.c			\
					options.c			\
					path.c				\
					print_long.c		\
					print_long_info.c	\
					print_normal.c		\
					print_single.c		\
					sort_argv.c			\
					sort_list_dir.c		\
					sort_list_file.c	\
					utils.c				\

OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

LIBFTPRINTF		=	./libftprintf/libftprintf.a
LIBINC			=	-I./libftprintf/includes
LIBLINK			=	-L./libftprintf -lftprintf

SRC_PATH		=	./src/
INC_PATH		=	./includes/
OBJ_PATH		=	./obj/

all:			$(NAME)

$(NAME):		obj	libftprintf $(OBJ)
					@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
					@printf "\n=> \x1B[33mCompiling ft_ls...\x1b[37m"
					@printf "\n=> \x1B[32mft_ls done !\x1B[37m\n"

obj:
					@mkdir -p $(OBJ_PATH)

libftprintf:		$(LIBFTPRINTF)

$(LIBFTPRINTF):
					@make -C ./libftprintf
					@printf "=> \e[38;5;208mMaking ft_ls/obj dir... \x1B[37m"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
					@$(CC) $(CFLAGS) $(LIBINC) -I $(INC_PATH) -o $@ -c $<
					@printf "\e[38;5;208m▒\e[0m"

clean:
					@rm -rf $(OBJ_PATH)
					@printf "=> \x1B[31mDeleting ft_ls.obj files...\x1B[37m\n"
					@printf "=> \x1B[31mDeleting libftprintf.obj files...\x1B[37m\n"
					@printf "=> \x1B[31mDeleting libft.obj files...\x1B[37m\n"
					@make -C ./libftprintf clean

fclean:			clean
					@printf "=> \x1B[31mDeleting ft_ls...\x1B[37m\n"
					@printf "=> \x1B[31mDeleting libftprintf.a.. \x1B[37m\n"
					@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
					@rm -rf $(NAME)
					@make -C ./libftprintf fclean

re:				fclean all

norme:
					@norminette ./src/
					@norminette ./includes/
