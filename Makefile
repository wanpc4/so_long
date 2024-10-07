CC = gcc

NAME = so_long

LIBFT_A = libft.a

CFLAGS = -Wall -Wextra -Werror -I. -g3

MLX_FLAGS = -L ./Libft -lft -L ./minilibx-lib -lmlx -lXext -lX11

REMOVE = rm -rf

SOURCES = minilibx-lib/libmlx_Linux.a \
		  minilibx-lib/libmlx.a \
		  Libft/libft.a 

MAKE_SOURCES = srcs/main/so_long.c \
			   srcs/configuration/*.c \
			   srcs/error_check/*.c \
			   get_next_line/*.c \

$(NAME) :
		make all -C minilibx-lib
		make all -C Libft
		$(CC) $(CFLAGS) $(MAKE_SOURCES) -o $(NAME) \
		$(MLX_FLAGS)

all: $(NAME)

fclean: clean
		$(REMOVE) $(NAME)
		$(REMOVE) $(LIBFT_A)
		make fclean -C Libft

clean:
		$(REMOVE) $(NAME)
		make clean -C minilibx-lib
		make clean -C Libft

re: fclean all

.PHONY: all clean fclean re