# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernando <fernando@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/17 21:23:10 by fernando          #+#    #+#              #
#    Updated: 2020/03/17 21:30:00 by fernando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm

NAME_LIB = libasm.a

SRCS = ft_strlen.s \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NASM = nasm

NASMFLAGS = -f macho64

OBJ = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME_LIB) $(OBJ)

execute :
	$(CC) $(CFLAGS) main.c $(NAME_LIB)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME_LIB)
	rm -f ./a.out

re : fclean all