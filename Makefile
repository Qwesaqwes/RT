# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 16:44:32 by opandolf          #+#    #+#              #
#    Updated: 2016/11/23 16:26:47 by JimmyChen        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RT
DIRSRC		=	./srcs/
DIROBJ		=	./objs/
LIBA		=	./libft/libft.a
INCLUDE		=	-I./includes/ -I./libft/includes/ -I./minilibx_macos/
SUB_MAKE	=	./libft/
INC_LIB		=	-L./libft -lft -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -lm
SRC			=	compute_ray.c\
				get_nearest_obj.c\
				hook.c\
				init_camera.c\
				init_test.c\
				main.c\
				matrix.c\
				normalizevec.c\
				pixelput.c\
				raytracing.c\
				sphere.c\
				inver_matrix.c\
				scale_matrix.c\
				trans_matrix.c



OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(DIROBJ)%)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e

$(NAME)	:	$(OBJS)
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE))
endif

				$(CC) $(INCLUDE) $(INC_LIB) $(CFLAGS) -o $(NAME) $(LIBA) $(OBJS)
				@$(ECHO) '> Compiled'

clean	:
				@(cd $(DIROBJ) && $(RM) $(OBJ))
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) clean)
endif
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
endif
				-@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

$(DIROBJ)%.o		:		$(DIRSRC)%.c
				$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<
