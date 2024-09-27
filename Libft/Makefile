# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 12:31:41 by wwan-ab-          #+#    #+#              #
#    Updated: 2024/06/25 22:36:43 by wwan-ab-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

REMOVE = rm -f

CFLAGS = -Wall -Wextra -Werror -I.

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SOURCES_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c
			
OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

NAME = libft.a

LIBC = ar rcs

$(NAME) : $(OBJECTS)
		$(LIBC) $(NAME) $(OBJECTS)

all: $(NAME)

clean:
		$(REMOVE) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
		$(REMOVE) $(NAME)

re: fclean $(NAME)

bonus: $(OBJECTS) $(OBJECTS_BONUS)
					$(LIBC) $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

.PHONY: all clean fclean re bonus