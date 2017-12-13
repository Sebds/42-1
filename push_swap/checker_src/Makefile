NAME			=	checker

SRC_BASE			=	main.c	\
					instructions.c	\
					tools.c	\
					analyse.c	\
					operations.c

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

SRC_DIR			=	src/
INC_DIR			=	includes/
OBJ_DIR			=	objs/

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

LIBFT_DIR		=	../libft/
LIBFT_LIB		=	$(LIBFT_DIR)libft.a
LIBFT_INC		=	$(LIBFT_DIR)includes/

all:
					@printf "\n["
					@make -C $(LIBFT_DIR)
					@make -j $(NAME)
					@printf "]\n"
					@printf "\n=> \x1B[32mChecker ready to beat errors ! ( ͡° ͜ʖ ͡°) \x1B[37m\n"

$(NAME):			$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
					@$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(INC_DIR) -I $(LIBFT_INC) $(LIBFT_LIB)

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
					@make -C $(LIBFT_DIR) clean

fclean:				clean
					@printf "=> \x1B[31mDeleting $(NAME)...\x1B[37m\n"
					@rm -f $(NAME)
					@make -C $(LIBFT_DIR) fclean

re:					fclean all

norme:
					@norminette $(INC_DIR)/*
					@norminette $(SRC_DIR)/*

.PHONY:				all clean fclean re norme
