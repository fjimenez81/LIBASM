# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/17 21:23:10 by fernando          #+#    #+#              #
#    Updated: 2020/09/01 13:45:07 by fjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm

NAME_LIB = libasm.a

OS			=	$(shell uname)

ifeq ($(OS), Linux)
	NASMFLAGS	= -f elf64
	PATCH		= -no-pie
	SRC_DIR		= srcs_linux/
endif
ifeq ($(OS), Darwin)
	NASMFLAGS	= -f macho64
	PATCH		= -I./ -L./ -lasm
	SRC_DIR		= srcs_darwin/
endif

SRC_FILES =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

CC = gcc

RM = rm -rf

SRC	= $(addprefix $(SRC_DIR), $(SRC_FILES))

NASM = nasm

OBJ = $(SRC:.s=.o)

%.o : %.s
	@$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME_LIB) $(OBJ)
	@echo ======DONE======

execute :
	@$(CC) $(PATCH) main.c $(NAME_LIB) -o $(NAME) && ./$(NAME)

valgrind : execute
	@valgrind --leak-check=full ./$(NAME)

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME_LIB)
	@$(RM) $(NAME)
	@echo ======REMOVED======

re : fclean all