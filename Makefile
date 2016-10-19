# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/22 15:50:34 by jichen-m          #+#    #+#              #
#    Updated: 2016/06/03 17:42:33 by jichen-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

HEAD = ./includes/minilibx_macos/

LIB = -L ./libft/ -lft

LIB2 = -L ./includes/minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

C_FILES = main.c\
			hook.c\
			objects.c\
			lights.c\
			raytracing.c\
			init_event.c\
			light2.c

SRC = $(addprefix ./srcs/,$(C_FILES))

FLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\033[1;32m"
		@echo "Processing files..."
		@make -C libft/
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIB) $(LIB2)
		@echo "\033[1;32m"
		@echo "$(NAME) has been created! :D"

%.o: %.c
		@$(CC) $(FLAGS) -o $@ -c $< -I $(HEAD) -I ./libft/includes/ -I ./includes/

clean:
		@rm -rf $(OBJ)
		@echo "\033[1;32mObjects files have been removed successfully!"

fclean: clean
		@rm -rf $(NAME) ./libft/libft.a
		@echo "\033[1;32m$(NAME) has been removed! All clean ^^!"

re: fclean all
