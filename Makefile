# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkalia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 14:12:11 by jkalia            #+#    #+#              #
#*   Updated: 2017/05/14 14:40:36 by jkalia           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		:= hash
CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I includes

FILES		:= db_murmurhash db_hash db_hash_delete db_hash_test \
				ft_memalloc ft_strcmp ft_strdup ft_strlen ft_bzero ft_strnew \
SRC			:= $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ			:= $(SRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\033[32mCreated Hash\033[0m"
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mRemoved Hash\033[0m"

re: fclean all
