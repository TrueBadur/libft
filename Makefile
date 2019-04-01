# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 15:05:00 by ehugh-be          #+#    #+#              #
#    Updated: 2019/04/01 21:06:56 by ehugh-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAINLIB = libft.a
OCL_NAME = libocl.a
STD_LIB = std_lib.a
SRC = $(wildcard std_lib/*/*.c) $(wildcard std_lib/ft_*.c) std_lib/get_next_line.c
OBJ = $(SRC:.c=.o)
OCL_SRC = $(wildcard ft_ocl/*.c)
OCL_OBJ = $(OCL_SRC:.c=.o)
CC = clang
LIBSPATH = -I ./std_lib/ -I ./std_lib/printf/
#CFLAGS = -Wall -Wextra -Werror

.c.a:
	@$(CC) $(CFLAGS) $(LIBSPATH) -c $< -o $*.o
	@ar r $@ $*.o
	@rm $*.o

all: libft.a($(OBJ)) libocl.a($(OCL_OBJ))

fclean: clean
	@/bin/rm -f $(MAINLIB) $(OCL_NAME)

clean:
	@/bin/rm -f $(OBJ) $(OCL_OBJ)
	@/bin/rm -f libft.h.gch

re: fclean all

