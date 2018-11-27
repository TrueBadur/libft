/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:54:24 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/27 19:35:25 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char *src_c;

	src_c = src;
	while (*src && size)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	if (!size)
		*(dest - 1) = 0;
	return (ft_strlen(src_c));
}
