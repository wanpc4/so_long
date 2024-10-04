CC = gcc

NAME = so_long

LIBFT_A = libft.a

#CFLAGS = -Wall -Wextra -Werror -I. -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror -I. -g3

MLX_FLAGS = -L/home/wwan-ab-/Desktop/so_long/minilibx-lib -lmlx \
			-L/home/wwan-ab-/Desktop/so_long/Libft -lft -lXext -lX11

REMOVE = rm -rf

SOURCES = minilibx-lib/libmlx_Linux.a \
		  minilibx-lib/libmlx.a \
		  Libft/libft.a 

MAKE_SOURCES = srcs/so_long.c \
			   srcs/generate_map.c \
			   srcs/map_specs.c \
			   srcs/character_controls.c \
			   srcs/error_check/error_checker_1.c \
			   srcs/error_check/error_checker_2.c \
			   get_next_line/get_next_line.c \
		  	   get_next_line/get_next_line_utils.c

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