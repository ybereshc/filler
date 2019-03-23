# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filler                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybereshc <ybereshc@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:35:04 by ybereshc          #+#    #+#              #
#    Updated: 2018/11/06 19:35:08 by ybereshc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ybereshc.filler
BONUS_NAME = visualize_filler
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CPPFLAGS = -O3
FILES = f_parse.c f_manhattan.c f_work.c main.c
LIB = lib/libft.a
OBJS = $(FILES:.c=.o) $(LIB_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C lib/
	@$(CC) $(CFLAGS) ./bonus/$(BONUS_NAME).c $(LIB) -o $(BONUS_NAME)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) $(LIB) -o $(NAME)
	@echo "\\033[92m$(NAME) was created!\\033[0m"

clean:
	@make clean -C lib/
	@rm -rf $(OBJS)
	@echo "\\033[91mRemove all $(NAME) objects files.\\033[0m"

fclean: clean
	@make fclean -C lib/
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo "\\033[91mRemove $(NAME)\\033[0m"

re: fclean all
