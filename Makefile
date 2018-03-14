# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 16:33:37 by fdeclerc          #+#    #+#              #
#    Updated: 2018/03/14 09:53:05 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =		libft_malloc_$(HOSTTYPE).so

CC = 		gcc -Wall -Wextra -Werror

LFLAGS = 	-shared -fPIC

LFT =		libft/

LIBS =		-L$(LFT) -lft

SRC =		sources/small.c\
			sources/large.c\
			sources/malloc.c\
			sources/alloc_area.c\
			sources/free.c\
			sources/realloc.c\
			sources/show_alloc_mem.c\
			sources/tiny.c\

RM =		rm -rf

OBJ =		$(SRC:.c=.o)

OBJDIR = 	obj

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LFT)
			@echo "\033[32m[BUILDING $(NAME)] \033[0m" | tr -d '\n'
			@$(CC) $(LFLAGS) -o $(NAME) $(OBJ) $(LIBS)
			mkdir -p $(OBJDIR) && mv $(OBJ) ./$(OBJDIR)/
			@rm -f libft_malloc.so
			@ln -s $(NAME) libft_malloc.so
			@echo "\033[32m[$(NAME) IS READY !]\033[0m"

%.o:		%.c
			@echo "\033[36m[COMPILING...]\033[0m" | tr -d '\n'
			$(CC) -o $@ -c $<

clean:
			@echo "\033[31m[CLEANING SOURCES] \033[0m" | tr -d '\n'
			$(RM) $(OBJDIR)
			@make clean -C libft

fclean:		clean
			@echo "\033[31m[FCLEAN $(NAME)] \033[0m" | tr -d '\n'
			$(RM) $(NAME) libft_malloc.so
			@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean
