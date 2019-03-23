# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybereshc <ybereshc@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:35:04 by ybereshc          #+#    #+#              #
#    Updated: 2018/11/06 19:35:08 by ybereshc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CPPFLAGS = -O3
FILES = ft_print_memory.c ft_int_len.c ft_int_to_str.c ft_memcpy.c ft_memset.c \
        ft_pow.c ft_math.c ft_str_to_int.c ft_strcase.c ft_strchr.c \
        ft_strdup.c ft_strjoin.c ft_strlen.c ft_strsub.c ft_bzero.c \
        ft_unicode.c ft_malloc.c ft_list.c ft_strcat.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\\033[92m$(NAME) was created!\\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo "\\033[91mRemove all $(NAME) objects files.\\033[0m"

fclean:
	@rm -rf $(OBJS) $(NAME)
	@echo "\\033[91mRemove all $(NAME) files.\\033[0m"

re: fclean all
