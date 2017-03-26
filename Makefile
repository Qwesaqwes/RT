# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 16:44:32 by opandolf          #+#    #+#              #
#    Updated: 2017/03/25 23:47:19 by dsusheno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RT
DIRSRC		=	./srcs/
DIROBJ		=	./objs/
DIROBJECT	=	./objs/object/
DIRGTK		=	./objs/gtk/
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
				reflection_refraction_functions.c\
				dist_to_figure.c\
				texture_color.c\
				bump_mapping.c\
				transp_mapping.c\
				object/sphere.c\
				object/plane.c\
				object/cylindre.c\
				object/cone.c\
				object/triangle.c\
				object/face_cuting.c\
				object/polygone.c\
				object/circle.c\
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
				gtk/gtk_set_box2.c\
				gtk/gtk_cam_movement.c\
				gtk/gtk_cam_movement1.c\
				gtk/gtk_cam_rot.c\
				../parseur/object/ft_fill_info_object.c\
				../parseur/lum/ft_parsing_lum.c\
				../parseur/object/ft_parsing_object.c\
				../parseur/camera/ft_parsing_camera.c\
				../parseur/scene/ft_parsing_scene.c\
				../parseur/ft_parsing.c\
				../parseur/reader/ft_read_parsing.c\
				../parseur/source/source_search.c\
				../parseur/parseur.c\
				free.c

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
				$(CC) $(INCLUDE) $(GTK_FLAG) $(CFLAGS) -o $@ -c $<
