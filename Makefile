NAME = minishell

DIR_H = ./includes/

DIR_C = ./src/

DIR_O = ./objs/

FILE_C = main.c\
	path.c\
	env.c\
	env_action.c\
	set_var.c\
	tab_list.c\
	ft_cd.c\
	env_i.c\
	env_param.c\
	env_param2.c\
	str_arg.c\
	cd_old_new.c\
	echo.c\
	echo_param.c\

FILE_O = $(FILE_C:.c=.o)

SRC_C := $(addprefix $(DIR_C), $(FILE_C))

SRC_O := $(addprefix $(DIR_O), $(FILE_O))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	@clang $(FLAGS) -o $(NAME) $(SRC_O) libft/libft.a
	@echo "\033[32mminishell	Compiled"
	   
$(SRC_O): $(SRC_C)
	@make -C libft/
	@clang $(FLAGS) -c $(SRC_C) -I $(DIR_H)
	@echo "\033[32mminishell .o	Compiled"
	@mkdir -p $(DIR_O)
	@mv $(FILE_O) $(DIR_O)

clean:
	@/bin/rm -rf $(DIR_O)
	@echo "\033[31mminishell clean		ok"
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mminishell fclean	ok"
	@make fclean -C libft/

re: fclean all

.PHONY: clean fclean all re
