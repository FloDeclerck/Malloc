# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 16:33:37 by fdeclerc          #+#    #+#              #
#    Updated: 2018/03/13 17:20:09 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =		libft_malloc_$(HOSTTYPE).so

LFT =		libft/libft.a

LIBS =		-L libft/ -lft

HPATH =		-I ./includes -I ./libft/

SRC =		small.c\
			large.c\
			malloc.c\
			alloc_area.c\
			free.c\
			realloc.c\
			show_alloc_mem.c\
			tiny.c\

SRCDIR =	$(addprefix ./sources/, $(SRC))

CC =		gcc -g -Wall -Wextra -Werror -fPIC

RM =		rm -rf

OBJDIR =	$(addprefix ./obj/, $(SRC:.c=.o))

all:		$(NAME)

$(NAME):
			@make -C libft/
			@echo "\033[32m[build $(NAME)] \033[0m" | tr -d '\n'
			$(CC) -c $(SRCDIR)
			@mkdir -p obj && mv $(SRC:.c=.o) ./obj/
			@$(CC) -o $(NAME) $(OBJDIR) $(LIBS) $(HPATH)
			@rm -f libft_malloc.so
			@ln -s $(NAME) libft_malloc.so
			@echo "\033[32m[$(NAME) ready]\033[0m"

clean:
			@echo "\033[31m[Clean Sources] \033[0m" | tr -d '\n'
			$(RM) $(OBJ)
			@$(RM) libft_malloc.so
			@make clean -C libft

fclean:		clean
			@echo "\033[31m[FClean $(NAME)] \033[0m" | tr -d '\n'
			$(RM) $(NAME) libft_malloc.so
			@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean
