/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:04:14 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/26 17:49:23 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_alloc_num_words(char const *s, char c, char ***ret,
		char ***ret_c)
{
	int		wcount;

	wcount = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			wcount++;
		s++;
	}
	if (!(*ret = (char **)malloc(sizeof(char *) * (wcount + 1))))
		return (0);
	*ret_c = *ret;
	return (1);
}

static char	*ft_split(int wlen, char const *wstart)
{
	char *ret;

	if (!(ret = (char *)malloc(sizeof(char) * (wlen + 1))))
		return (NULL);
	ft_strncpy(ret, wstart, wlen);
	ret[wlen] = '\0';
	return (ret);
}

static void	ft_newword(const char **wstart, int *wlen, const char *s)
{
	*wstart = s + 1;
	*wlen = 1;
}

static void	*ft_ubivator(char ***ret_c)
{
	char **ret;

	ret = *ret_c;
	while (*ret)
		free(*ret++);
	free(*ret_c);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int			wlen;
	const char	*wstart;
	char		**ret;
	char		**ret_c;

	if (!(wlen = ft_alloc_num_words(s, c, &ret, &ret_c)))
		return (NULL);
	wstart = s;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			ft_newword(&wstart, &wlen, s);
		else if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			if (!(*ret++ = ft_split(wlen, wstart)))
				return (ft_ubivator(&ret));
		}
		else if (*s != c)
			wlen++;
		s++;
	}
	*ret = NULL;
	return (ret_c);
}
