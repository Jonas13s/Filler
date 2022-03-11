NAME = joivanau.filler

SRCS = main.c board.c additional.c piece.c heat_map.c
SRCS += init.c free.c score.c

SRC_DIR = src/

OBJ = $(SRCS:.c=.o)

OBJ_DIR = obj/

INCLUDES = -I libft -I includes

LINK = -L libft -lft

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT)
	@gcc -c $(FLAGS) $(addprefix $(SRC_DIR), $(SRCS)) $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(OBJ)) -o $(NAME) $(LINK)
	@echo "Compilation done!"
$(LIBFT):
	@make -s -C libft
clean: 
	@make -s -C libft/ clean
	@rm -rf obj
	@echo ".o removed!"

fclean: clean
	@rm -rf $(NAME)
	@make -s -C libft/ fclean
	@echo "$(NAME) removed!"

re: fclean all