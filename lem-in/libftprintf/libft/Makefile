#!/usr/bin/make -f
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 20:35:32 by nsampre           #+#    #+#              #
#    Updated: 2017/02/07 10:42:09 by nsampre          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a

SRCS		=	ft_atoi.c \
				ft_atoll.c	\
                ft_bzero.c \
                ft_isalnum.c \
                ft_isalpha.c \
                ft_isascii.c \
                ft_isdigit.c \
                ft_isprint.c \
                ft_itoa.c \
                ft_lstadd.c \
                ft_lstdel.c \
                ft_lstdelone.c \
                ft_lstiter.c \
                ft_lstmap.c \
                ft_lstnew.c \
                ft_memalloc.c \
                ft_memccpy.c \
                ft_memchr.c \
                ft_memcmp.c \
                ft_memcpy.c \
                ft_memdel.c \
                ft_memmove.c \
                ft_memset.c \
                ft_putchar.c \
                ft_putchar_fd.c \
                ft_putendl.c \
                ft_putendl_fd.c \
                ft_putnbr.c \
                ft_putnbr_fd.c \
                ft_putstr.c \
                ft_putstr_fd.c \
                ft_strcat.c \
                ft_strchr.c \
                ft_strclr.c \
                ft_strcmp.c \
                ft_strcpy.c \
                ft_strdel.c \
                ft_strdup.c \
                ft_strequ.c \
                ft_striter.c \
                ft_striteri.c \
                ft_strjoin.c \
                ft_strlcat.c \
                ft_strlen.c \
                ft_strmap.c \
                ft_strmapi.c \
                ft_strncat.c \
                ft_strncmp.c \
                ft_strncpy.c \
                ft_strnequ.c \
                ft_strnew.c \
				ft_strnjoin.c \
                ft_strnstr.c \
                ft_strrchr.c \
                ft_strsplit.c \
                ft_strstr.c \
                ft_strsub.c \
                ft_strtrim.c \
                ft_tolower.c \
                ft_toupper.c \
				ft_pow.c \
				ft_factorial.c \
				ft_isprime.c \
				ft_strupcase.c \
				ft_strlowcase.c \
				ft_strcapitalize.c \
				ft_swap.c	\
				get_next_line.c

INC			=	./includes/libft.h

OBJ			=	$(addprefix $(OBJ_PATH),$(SRCS:.c=.o))

CC			=	gcc
FLAGS		=	-Werror -Wall -Wextra -O3

SRC_PATH	=	./
INC_PATH    =   ./includes/
OBJ_PATH    =   ./obj/

all			:	$(NAME)

$(NAME)		:	obj $(OBJ)
				@ar rc $(NAME) $(OBJ)
				@printf "\n=> \x1B[33mranlib libft.a...\x1B[37m"
				@ranlib $(NAME)
				@printf "\n=> \x1B[32mlibft.a done !\x1B[37m\n"

obj			:
				@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@$(CC) $(FLAGS) -o $@ -c $<
				@printf "\e[38;5;208m▒\e[0m"

clean		:
				@rm -rf $(OBJ_PATH)

fclean		:   clean
				@rm -f $(NAME)

re			:	fclean all

.PHONY		:	re clean fclean

norme		:
				@norminette $(SRCS)
				@norminette $(INC_PATH)
