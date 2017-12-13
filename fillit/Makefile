#!/usr/bin/make

NAME			=	fillit

SRC				=	main.c				\
					check_and_list.c	\
					read_and_split.c	\
					up_and_left.c		\
					map.c				\
					solve.c

OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

LIBFT			=	./libft/libft.a
LIBINC			=	-I./libft
LIBLINK			=	-L./libft -lft

SRC_PATH		=	./src/
INC_PATH		=	./includes/
OBJ_PATH		=	./obj/

all:			$(NAME)

$(NAME):		obj libft $(OBJ)
					@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
					@printf "\n=> \x1B[32mfillit done !\x1B[37m\n"

obj:
					@mkdir -p $(OBJ_PATH)
					@printf "=> \e[38;5;208mMaking fillit/obj dir... \x1B[37m"

libft:			$(LIBFT)

$(LIBFT):
					@make -C ./libft
					@printf "=> \e[38;5;208mMaking fillit/obj dir... \x1B[37m"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
					@$(CC) $(CFLAGS) $(LIBINC) -I $(INC_PATH) -o $@ -c $<
					@printf "\e[38;5;208m▒\e[0m"

clean:
					@rm -rf $(OBJ_PATH)
					@echo "=> \x1B[31mDeleting fillit .obj files...\x1B[37m"
					@make -C ./libft clean


fclean:			clean
					@rm -rf $(NAME)
					@echo "=> \x1B[31mDeleting fillit...\x1B[37m"
					@make -C ./libft fclean

re:				fclean all

norme:
					@norminette ./src/
					@norminette ./includes/
