# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 16:44:32 by opandolf          #+#    #+#              #
#    Updated: 2017/03/03 20:09:01 by jichen-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RT
DIRSRC		=	./srcs/
DIROBJ		=	./objs/
LIBA		=	./libft/libft.a
INCLUDE		=	-I./includes/ -I./libft/includes/
SUB_MAKE	=	./libft/
GTK_FLAG	=	$$(pkg-config --cflags gtk+-3.0)
LD_FLAG		=	$$(pkg-config --libs gtk+-3.0)
SRC			=	compute_ray.c\
				get_nearest_obj.c\
				init_camera.c\
				init_test.c\
				main.c\
				matrix.c\
				normalizevec.c\
				pixelput.c\
				raytracing.c\
				sphere.c\
				plane.c\
				cylindre.c\
				inver_matrix.c\
				scale_matrix.c\
				trans_matrix.c\
				compute_normal_vec.c \
				compute_color.c \
				reflection_refraction_functions.c\
				cone.c\
				triangle.c\
				polygone.c\
				face_cuting.c\
				dist_to_figure.c\
				texture_color.c\
				gtk_options1.c\
				gtk_add_obj1.c\
				gtk_add_obj2.c\
				gtk_add_obj3.c\
				gtk_add_obj4.c\
				gtk_add_obj5.c\
				gtk_add_obj6.c\
				gtk_add_obj8.c\
				gtk_view_obj1.c\
				gtk_delete_obj1.c\
				gtk_modif_obj1.c\
				gtk_modif_obj2.c\
				gtk_choose_file.c\
				gtk_effect1.c\
				gtk_effect2.c\
				gtk_effect3.c\
				gtk_effect4.c\
				gtk_effect5.c\
				gtk_effect6.c\
				gtk_effect7.c\
				gtk_set_box.c

FLAGS		=	debug

OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(DIROBJ)%)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -pedantic -g
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

				$(CC) $(LD_FLAG) $(INCLUDE) $(CFLAGS) -o $(NAME) $(LIBA) $(OBJS)
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
				$(CC) $(INCLUDE) $(GTK_FLAG) $(CFLAGS) -o $@ -c $<
