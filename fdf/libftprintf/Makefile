#!/usr/bin/make -f
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 20:35:32 by nsampre           #+#    #+#              #
#    Updated: 2017/01/02 16:46:17 by nsampre          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a

SRCS		=	binary_b.c					\
				binary_char_hhb.c			\
				binary_long_lb.c			\
				binary_long_long_llb.c		\
				binary_short_hb.c			\
				char_c.c					\
				char_s.c					\
				percent.c					\
				short_hd.c					\
				signed_char_hhd.c			\
				wchar_t_lc.c				\
				wchar_t_ls.c				\
				hex_x.c						\
				hex_long_lx.c				\
				hex_long_long_llx.c			\
				hex_short_hx.c				\
				hex_char_hhx.c				\
				int_d_i.c					\
				long_ld.c					\
				long_long_lld.c				\
				octal_o.c					\
				octal_long_lo.c				\
				octal_long_long_llo.c		\
				octal_short_ho.c			\
				octal_char_hho.c			\
				binary_b.c					\
				binary_long_lb.c			\
				binary_long_long_llb.c		\
				binary_short_hb.c			\
				binary_char_hhb.c			\
				pointer_p.c					\
				ssize_t_zd.c				\
				uintmax_t_ju.c				\
				intmax_t_jd.c				\
				unsigned_int_u.c			\
				unsigned_long_lu.c			\
				unsigned_long_long_llu.c	\
				unsigned_short_hu.c			\
				unsigned_char_hhu.c			\
				count.c						\
				fill.c						\
				ft_printf.c					\
				get_params.c				\
				handle_arg.c				\
				handle_arg_next.c			\
				is_params.c					\
				param_int.c					\
				param_unsigned.c			\
				param_hex.c					\
				param_octal.c				\
				param_char.c				\
				no_format.c					

OBJ			=	$(addprefix $(OBJ_PATH),$(SRCS:.c=.o))

CC			=	gcc
FLAGS		=	-Werror -Wall -Wextra

LIBFT		=	./libft/libft.a
LIBINC		=	-I./libft/includes/
LIBLINK		=	-L./libft -lft

SRC_PATH	=	./src/
INC_PATH    =   ./includes/
OBJ_PATH    =   ./obj/

all			:	$(NAME)

$(NAME)		:	obj libft $(OBJ)
				@ar rc $(NAME) $(OBJ)
				@printf "\n=> \x1B[33mranlib libftprintf.a...\x1B[37m"
				@ranlib $(NAME)

				@printf "\n=> \x1B[32mlibftprintf.a done !\x1B[37m\n"

obj			:
				@mkdir -p $(OBJ_PATH)
				@printf "=> \e[38;5;208mMaking libft/obj dir... \x1B[37m"

libft		:	$(LIBFT)

$(LIBFT)	:
				@make -C ./libft/
				@printf "=> \e[38;5;208mMaking libftprintf/obj dir... \x1B[37m"
				@cp $(LIBFT) ./$(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@$(CC) $(CFLAGS) $(LIBINC) -I$(INC_PATH) -o $@ -c $<
				@printf "\e[38;5;208m▒\e[0m"

clean		:
				@make -C ./libft/ clean
				@rm -rf $(OBJ_PATH)

fclean		:   clean
				@make -C ./libft/ fclean
				@rm -f $(NAME)

re			:	fclean all

norme		:
				@norminette $(SRC_PATH)
				@norminette $(INC_PATH)
