/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:55:20 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/21 20:38:32 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
char	*ft_itoa(int n);
char	*ft_strncpy(char *dst, char const *src, size_t len);
char	**ft_strsplit(char const *s, char c);
int		ft_tolower(int c);
int		ft_toupper(int c);
#endif
