CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

REMOVE = rm -rf

SOURCES = srcs/so_long.c \
		  includes/so_long.h \
		  minilibx-lib/libmlx_Linux.a \
		  minilibx-lib/libmlx.a

NAME = so_long

$(NAME) :
		make all -C minilibx-lib
		$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

all: $(NAME)

fclean: clean
		$(REMOVE) $(NAME)
		make fclean -C minilibx-lib

clean:
		$(REMOVE) $(NAME)
		make clean -C minilibx-lib

re: fclean all

.PHONY: all clean fclean re