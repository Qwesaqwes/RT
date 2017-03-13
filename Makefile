# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 16:44:32 by opandolf          #+#    #+#              #
#    Updated: 2017/03/13 20:44:31 by jichen-m         ###   ########.fr        #
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
				inver_matrix.c\
				scale_matrix.c\
				trans_matrix.c\
				compute_normal_vec.c \
				compute_color.c \
				compute_color1.c \
				reflection_refraction_functions.c\
				dist_to_figure.c\
				treat_colors.c\
				treat_colors1.c\
				treat_vector.c\
				treat_vector1.c\
				texture/texture_color.c\
				texture/bump_mapping.c\
				texture/bump_mapping1.c\
				texture/bump_mapping2.c\
				texture/procedural_mapping.c\
				texture/texture_mapping.c\
				texture/texture_mapping1.c\
				texture/checker.c\
				texture/perlin.c\
				object/sphere.c\
				object/plane.c\
				object/cylindre.c\
				object/cone.c\
				object/triangle.c\
				object/face_cuting.c\
				object/polygone.c\
				gtk/gtk_options1.c\
				gtk/gtk_add_obj1.c\
				gtk/gtk_add_obj2.c\
				gtk/gtk_add_obj3.c\
				gtk/gtk_add_obj4.c\
				gtk/gtk_add_obj5.c\
				gtk/gtk_add_obj6.c\
				gtk/gtk_add_obj7.c\
				gtk/gtk_add_obj8.c\
				gtk/gtk_view_obj1.c\
				gtk/gtk_delete_obj1.c\
				gtk/gtk_modif_obj1.c\
				gtk/gtk_modif_obj2.c\
				gtk/gtk_modif_obj3.c\
				gtk/gtk_choose_file.c\
				gtk/gtk_effect1.c\
				gtk/gtk_effect2.c\
				gtk/gtk_effect3.c\
				gtk/gtk_effect4.c\
				gtk/gtk_effect5.c\
				gtk/gtk_effect6.c\
				gtk/gtk_effect6.1.c\
				gtk/gtk_effect7.c\
				gtk/gtk_set_box.c\
				gtk/gtk_set_box2.c


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
