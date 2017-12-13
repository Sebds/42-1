#!/usr/bin/make -f

NAME		=	libft.a

SRC_BASE	=	ft_atoi.c \
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
				ft_strndup.c \
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
				ft_xtoa.c	\
				get_next_line.c	\
				binary_b.c					\
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

SRC_DIR		=	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				@make -j $(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
				@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR)
				@printf "\e[38;5;208m▒\e[0m"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(dir $(OBJS))

clean:
				@rm -rf $(OBJ_DIR)

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
