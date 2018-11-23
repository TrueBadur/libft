/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 06:26:47 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/23 06:39:17 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ret;
	char *ret_c;

	if (!(ret = malloc(ft_strlen(s) + 1)))
		return (NULL);
	ret_c = ret;
	while (*s)
	{
		*ret++ = f(*s++);
	}
	*ret = '\0';
	return (ret_c);
}
