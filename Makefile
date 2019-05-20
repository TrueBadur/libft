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
SL_L_N = libstd.n libmtrx.n libvector.n libavl.n liblist.n libprintf.n
SL_L_C = $(SL_L_N:.n=.clean)
SL_L_F = $(SL_L_N:.n=.fclean)
SL_L_R = $(SL_L_N:.n=.re)
STD_LIB_PATH = std_lib/
OCL_SRC = $(wildcard ft_ocl/*.c)
OCL_OBJ = $(OCL_SRC:.c=.o)
AFILES = libstd.a libavl.a liblist.a libmtrx.a libprintf.a libvec.a
AF_PATH = $(subst lib,lib/lib, $(AFILES))
CC = clang
LIBSPATH = -I ./includes
CFLAGS = -Wall -Wextra -Werror

.c.a:
	@$(CC) $(CFLAGS) $(LIBSPATH) -c $< -o $*.o
	@ar r $@ $*.o
	@rm $*.o

all: $(SL_L_N)
#	ar r lib/$(MAINLIB) $(AF_PATH)

fclean: $(SL_L_F)
	@/bin/rm -f lib/$(MAINLIB)

clean: $(SL_L_C)

re: fclean all

lib%.n:
	make -C $(STD_LIB_PATH)$(basename $@)

lib%.clean:
	make -C $(STD_LIB_PATH)$(basename $@) clean

lib%.fclean:
	make -C $(STD_LIB_PATH)$(basename $@) fclean

