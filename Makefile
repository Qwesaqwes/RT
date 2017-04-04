# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 16:44:32 by opandolf          #+#    #+#              #
#    Updated: 2017/04/03 18:51:21 by jichen-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RT
DIRSRC		=	./srcs/
DIROBJ		=	./objs/
DIROBJECT	=	./objs/object/
DIRGTK		=	./objs/gtk/
DIRTEXTURE	=	./objs/texture
DIRMATRIX	=	./objs/matrix
DIRRAYTRAC	=	./objs/raytracing
DIRFREE		=	./objs/free
DIRCAM		=	./objs/camera
DIRMISC		=	./objs/misc

LIBA		=	./libft/libft.a
INCLUDE		=	-I./includes/ -I./libft/includes/
SUB_MAKE	=	./libft/
GTK_FLAG	=	$$(pkg-config --cflags gtk+-3.0)
LD_FLAG		=	$$(pkg-config --libs gtk+-3.0)
SRC			=	main.c\
				init_test.c\
				camera/init_camera.c\
				raytracing/reflection_refraction_functions.c\
				raytracing/pixelput.c\
				raytracing/normalizevec.c\
				raytracing/dist_to_figure.c\
				raytracing/get_nearest_obj.c\
				raytracing/compute_ray.c\
				raytracing/compute_normal_vec.c \
				raytracing/compute_color.c \
				raytracing/raytracing.c\
				raytracing/ft_lstdelfirst.c\
				raytracing/multi_thread.c\
				raytracing/set_cam_ray.c\
				misc/color.c\
				misc/color1.c\
				misc/vector.c\
				misc/vector1.c\
				matrix/trans_matrix.c\
				matrix/inver_matrix.c\
				matrix/scale_matrix.c\
				matrix/matrix.c\
				texture/texture_color.c\
				texture/transp_mapping.c\
				texture/bump_mapping.c\
				texture/map_values.c\
				texture/grey_scale_bump_map.c\
				texture/checker.c\
				texture/texture_mapping.c\
				texture/euler_angles.c\
				texture/perlin_deriv.c\
				texture/perlin_coef.c\
				object/sphere.c\
				object/plane.c\
				object/cylindre.c\
				object/cone.c\
				object/triangle.c\
				object/face_cuting.c\
				object/polygone.c\
				object/circle.c\
				object/quadrics.c\
				gtk/gtk_options1.c\
				gtk/gtk_add_obj1.c\
				gtk/gtk_add_obj1a.c\
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
				gtk/gtk_set_box2.c\
				gtk/gtk_cam_movement.c\
				gtk/gtk_cam_movement1.c\
				gtk/gtk_cam_rot.c\
				gtk/gtk_add_obj_limit.c\
				gtk/gtk_add_obj_limit1.c\
				gtk/gtk_modif_obj_limit.c\
				../parseur/object/ft_fill_info_object.c\
				../parseur/lum/ft_fill_lum.c\
				../parseur/faces/face.c\
				../parseur/lum/ft_parsing_lum.c\
				../parseur/object/ft_parsing_object.c\
				../parseur/camera/ft_parsing_camera.c\
				../parseur/scene/ft_parsing_scene.c\
				../parseur/ft_parsing.c\
				../parseur/reader/ft_read_parsing.c\
				../parseur/source/source_search.c\
				../parseur/parseur.c\
				free/free.c

FLAGS		=	debug

OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(DIROBJ)%)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -pedantic -g -ofast
	endif
else
CFLAGS		=	-Wall -Wextra -Werror -ofast
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e
MKDIR		=	mkdir -p

$(NAME)	: $(OBJS)
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
				@if [ ! -d $(DIROBJ) ]; then $(MKDIR) $(DIROBJ); fi
				@if [ ! -d $(DIROBJECT) ]; then $(MKDIR) $(DIROBJECT); fi
				@if [ ! -d $(DIRGTK) ]; then $(MKDIR) $(DIRGTK); fi
				@if [ ! -d $(DIRTEXTURE) ]; then $(MKDIR) $(DIRTEXTURE); fi
				@if [ ! -d $(DIRMATRIX) ]; then $(MKDIR) $(DIRMATRIX); fi
				@if [ ! -d $(DIRRAYTRAC) ]; then $(MKDIR) $(DIRRAYTRAC); fi
				@if [ ! -d $(DIRFREE) ]; then $(MKDIR) $(DIRFREE); fi
				@if [ ! -d $(DIRCAM) ]; then $(MKDIR) $(DIRCAM); fi
				@if [ ! -d $(DIRMISC) ]; then $(MKDIR) $(DIRMISC); fi
				$(CC) $(INCLUDE) $(GTK_FLAG) $(CFLAGS) -o $@ -c $<
