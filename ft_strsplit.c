/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:04:14 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/21 20:29:33 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_alloc_num_words(char const *s, char c)
{
	int		wcount;
	char	**ret;

	wcount = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			wcount++;
		s++;
	}
	if (!(ret = (char **)malloc(sizeof(char *) * (wcount + 1))))
		return (NULL);
	return (ret);
}

static void	ft_split(int wlen, char const *wstart, char ***ret)
{
	**ret = (char *)malloc(sizeof(char) * (wlen + 1));
	ft_strncpy(**ret, wstart, wlen);
	(**ret)[wlen] = '\0';
	(*ret)++;
}

char		**ft_strsplit(char const *s, char c)
{
	int			wlen;
	const char	*wstart;
	char		**ret;
	char		**ret_c;

	if (!(ret = ft_alloc_num_words(s, c)))
		return (NULL);
	ret_c = ret;
	wlen = 1;
	wstart = s;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
		{
			wstart = s + 1;
			wlen = 1;
		}
		else if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			ft_split(wlen, wstart, &ret);
		else if (*s != c)
			wlen++;
		s++;
	}
	*ret = NULL;
	return (ret_c);
}
