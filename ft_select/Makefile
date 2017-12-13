#!/usr/bin/make -f

NAME			=	ft_select
PUNCHLINE		=	select

SRC_BASE		=	main.c	\
					init_env.c	\
					display/display.c	\
					keys/key.c	\
					keys/key_type_arrow.c	\
					keys/key_type_other.c	\
					selection/file_mode.c	\
					selection/move_selection.c	\
					selection/delete_selection.c	\
					selection/handle_selection.c	\
					signal/signal.c	\
					terminal/terminal_info.c	\
					terminal/terminal_mode.c \

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

SRC_DIR			=	src/
INC_DIR			=	includes/
OBJ_DIR			=	objs/

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

LIBFT_DIR		=	libft/
LIBFT_LIB		=	$(LIBFT_DIR)libft.a
LIBFT_INC		=	$(LIBFT_DIR)includes/

all:
					@printf "\n["
					@make -s -C $(LIBFT_DIR)
					@make -j $(NAME)
					@printf "]\n"
					@printf "\n=> \x1B[32m$(NAME) ready to $(PUNCHINE) ! ( ͡° ͜ʖ ͡°) \x1B[37m\n"

$(NAME):			$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
					@$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(INC_DIR) -I $(LIBFT_INC) $(LIBFT_LIB)  -ltermcap

$(LIBFT_LIB):
					make -C $(LIBFT_DIR)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c | $(OBJ_DIR) $(INC_DIR)
					@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)
					@printf "\x1B[32m▒\e[0m"

clean:
					@printf "=> \x1B[31mDeleting $(NAME) .obj files...\x1B[37m\n"
					@rm -rf $(OBJ_DIR)
					@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"
					@make -C $(LIBFT_DIR) clean

fclean:				clean
					@printf "=> \x1B[31mDeleting $(NAME)...\x1B[37m\n"
					@rm -f $(NAME)
					@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
					@make -C $(LIBFT_DIR) fclean

re:					fclean all

norme:
					@norminette $(INC_DIR)/*
					@norminette $(SRC_DIR)/*

.PHONY:				all clean fclean re norme
