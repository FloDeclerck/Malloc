# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 16:33:37 by fdeclerc          #+#    #+#              #
#    Updated: 2018/03/07 16:39:53 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

LFT = libft/libft.a

LIBS = -L libft/ -lft

HPATH = -I ./includes -I ./libft/

SRC = test.c\
	  show_alloc_mem.c\

SRCDIR = $(addprefix ./sources/, $(SRC))

CC = gcc -g -Wall -Wextra -Werror -fPIC

OBJ = obj

RM = rm -rf

OBJDIR = $(addprefix ./$(OBJ)/, $(SRC:.c=.o))

$(NAME):
	make -C libft/
	$(CC) -c $(SRCDIR)
	mkdir -p $(OBJ) && mv $(SRC:.c=.o) ./$(OBJ)/
	$(CC) -o $(NAME) $(OBJDIR) $(LIBS) $(HPATH)
	ln -s $(NAME) libft_malloc.so

all: $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) libft_malloc.so
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) libft_malloc.so
	make fclean -C libft

re: fclean
	make re -C libft
	make all
	make clean

.PHONY: all clean fclean
