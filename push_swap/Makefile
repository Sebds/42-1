#!/usr/bin/make -f

all:
	@make -s -C ./libft/
	@make -s -C ./checker_src/
	@make -s -C ./push_swap_src/
	@mv ./checker_src/checker ./checker
	@mv ./push_swap_src/push_swap ./push_swap

clean:
	@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"
	@make clean -s -C ./libft/
	@make clean -s -C ./checker_src/
	@make clean -s -C ./push_swap_src/

fclean:
	@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
	@make fclean -s -C ./libft/
	@make fclean -s -C ./checker_src/
	@make fclean -s -C ./push_swap_src/
	@rm -rf checker
	@rm -rf push_swap

norme:
	@make norme -s -C ./push_swap_src/
	@make norme -s -C ./checker_src/

re: fclean all
