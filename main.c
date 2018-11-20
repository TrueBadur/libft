/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:10:14 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/20 23:02:18 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TEST_SIZE 15
#include "libft.h"
#include <stdio.h>

int test_str(void *exa, void *sol, size_t len, unsigned int tnum)
{
	if (len)
	{
		for(size_t i = 0; i < len; i++)
		{
			if(((char*)exa)[i] != ((char*)sol)[i])
			{
				printf("++++++++++++Error++++++++++\n	Test #%d\n", tnum);
				printf("Error on %lu symbol of array: %c != %c\n", i, ((char*)exa)[i], ((char*)sol)[i]);
				printf("++++++++++++++++++++++\n");
				return 1;
			}
		}
	}
	else
	{
		for(size_t i = 0; ((char*)exa)[i]; i++)
		{
			if(((char*)exa)[i] != ((char*)sol)[i])
			{
				printf("++++++++++++Error++++++++++\n	Test #%d\n", tnum);
				printf("Error on %lu symbol of array: %c != %c\n", i, ((char*)exa)[i], ((char*)sol)[i]);
				printf("++++++++++++++++++++++\n");
				return 1;
			}
		}

	}
	return 0;
}

void opipe(int (*op)[2], int fd)
{
	
	if( pipe(*op) != 0 ) {          /* make a pipe */
		exit(1);
	}
	
	dup2((*op)[1], fd);   /* redirect stdout to the pipe */
	close((*op)[1]);
}

int cpipe(int (*op)[2],char *sol, int len, unsigned int *tnum, int so, FILE *fd)
{
	static char buffer[100] = {0};
	fflush(fd);
	read((*op)[0], buffer, 100); /* read from pipe into buffer */
	dup2(so, fileno(fd));  /* reconnect stdout for testing */
	return (test_str(sol, buffer, len, *tnum++));
}

int test_putnbr_fd(int n, char *sol, int len, unsigned int *tnum, FILE *fd)
{
	int out_pipe[2];
	int saved_stdout;
	saved_stdout = dup(fileno(fd));  /* save stdout for display later */
	
	opipe(&out_pipe, fileno(fd));
	ft_putnbr_fd(n, fileno(fd));
	return cpipe(&out_pipe, sol, len, tnum, saved_stdout, fd);
}

int main(int argc, char **argv)
{
	argc += 0;
	argv += 0;
	unsigned int errn = 0;
	unsigned int tnum = 0;
	void *exa = malloc(sizeof(int) * TEST_SIZE);
	void *sol = malloc(sizeof(int) * TEST_SIZE);


	// ft_memset test
	errn += test_str(memset(exa, 'e', TEST_SIZE), ft_memset(sol, 'e', TEST_SIZE), TEST_SIZE, tnum++); //0
	errn += test_str(memset(exa, 20, TEST_SIZE), ft_memset(sol, 20, TEST_SIZE), TEST_SIZE, tnum++); 
	errn += test_str(memset(exa, 20, 20), ft_memset(sol, 20, 20), 20, tnum++); //2
	errn += test_str(memset(exa, 900, TEST_SIZE), ft_memset(sol, 900, TEST_SIZE), TEST_SIZE, tnum++); 
	errn += test_str(memset(exa, 20, 0), ft_memset(sol, 20, 0), 1, tnum++); //4
	printf("--------ft_memset sucess-------------\n");
	
	// ft_putnbr_fd
	errn += test_putnbr_fd(0, "0", 1, &tnum, stdout);
	errn += test_putnbr_fd(-1, "-1", 2, &tnum, stdout);
	errn += test_putnbr_fd(1, "1", 1, &tnum, stdout);
	errn += test_putnbr_fd(-2147483648, "-2147483648", 11, &tnum, stdout);
	errn += test_putnbr_fd(2147483647, "2147483647", 10, &tnum, stdout);
	errn += test_putnbr_fd(0, "0", 1, &tnum, stderr);
	errn += test_putnbr_fd(-1, "-1", 2, &tnum, stderr);
	errn += test_putnbr_fd(1, "1", 1, &tnum, stderr);
	errn += test_putnbr_fd(-2147483648, "-2147483648", 11, &tnum, stderr);
	errn += test_putnbr_fd(2147483647, "2147483647", 10, &tnum, stderr);
	FILE *f = tmpfile();
	errn += test_putnbr_fd(0, "0", 1, &tnum, f);
	errn += test_putnbr_fd(-1, "-1", 2, &tnum, f);
	errn += test_putnbr_fd(1, "1", 1, &tnum, f);
	errn += test_putnbr_fd(-2147483648, "-2147483648", 11, &tnum, f);
	errn += test_putnbr_fd(2147483647, "2147483647", 10, &tnum, f);
	printf("--------ft_putnbr_fd sucess----------\n");

	// ft_putnbr
	errn += test_putnbr_fd(0, "0", 1, &tnum, stdout);
	errn += test_putnbr_fd(-1, "-1", 2, &tnum, stdout);
	errn += test_putnbr_fd(1, "1", 1, &tnum, stdout);
	errn += test_putnbr_fd(-2147483648, "-2147483648", 11, &tnum, stdout);
	errn += test_putnbr_fd(2147483647, "2147483647", 10, &tnum, stdout);
	printf("--------ft_putnbr sucess-------------\n");

	if (!errn)
		printf("\n***************SUCCESS***************\n");
	free(exa);
	free(sol);
}
