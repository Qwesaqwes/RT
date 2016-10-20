#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/05 08:19:02 by opandolf          #+#    #+#              #
#    Updated: 2016/05/05 08:19:07 by opandolf         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a
DIRSRC		=	./srcs/
DIROBJ		=	./objs/
INCLUDE		=	-I./includes/
SUB_MAKE	=	
INC_LIB		=	
SRC			=	ft_atoi.c \
					ft_bzero.c \
					ft_isascii.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar.c \
					ft_putchar_fd.c \
					ft_putendl.c \
					ft_putendl_fd.c \
					ft_putnbr.c \
					ft_putnbr_fd.c \
					ft_putstr.c \
					ft_putstr_fd.c \
					ft_strcat.c \
					ft_strchr.c \
					ft_strclr.c \
					ft_strcmp.c \
					ft_strcpy.c \
					ft_strdel.c \
					ft_strdup.c \
					ft_strequ.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strncat.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strnequ.c \
					ft_strnew.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strsplit.c \
					ft_strstr.c \
					ft_strsub.c \
					ft_strtrim.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstaddafter.c \
					ft_nbcells.c \
					ft_memdup.c

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


$(NAME)	:		$(OBJ)
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE))
endif
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

clean	:
				@(cd $(DIROBJ) && $(RM) $(OBJ))
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) clean)
endif

all		:		$(NAME)

fclean	:		clean
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
endif
				-@$(RM) $(NAME)

re		:		fclean all

.PHONY	:		all clean re

%.o		:		$(DIRSRC)/%.c
				@$(CC) $(INCLUDE) $(CFLAGS) -o $(DIROBJ)/$@ -c $<
