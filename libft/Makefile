# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 14:55:31 by joivanau          #+#    #+#              #
#    Updated: 2022/03/13 22:54:27 by joivanau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_isspace.c ft_lstnew.c\
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strlcpy.c ft_lstsize.c ft_strisnumeric.c\
ft_strisprintable.c ft_isblank.c ft_strisalpha.c ft_calloc.c ft_strupdate.c get_next_line.c\
ft_free2d.c ft_str_valid.c

SRC = ft_printf.c ft_args.c ft_ischeck.c ft_conv.c ftoa.c assign_values.c
SRC += print_float.c print_char.c print_string.c print_signedinteger.c
SRC += print_hex.c print_pointer.c print_octal.c print_unsignedint.c

LIBRARY = $(FILES:.c=.o)

LIBRARY += $(SRC:.c=.o)

OBJ_DIR = obj/

FT_PRINTF_PATH = ft_printf/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(addprefix $(FT_PRINTF_PATH), $(SRC)) $(FILES) -I .
	@mkdir -p $(OBJ_DIR)
	@mv $(LIBRARY) $(OBJ_DIR)
	@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(LIBRARY))
clean:
	@rm -rf $(OBJ_DIR)
fclean: clean
	@rm -rf $(NAME)
re: fclean all
