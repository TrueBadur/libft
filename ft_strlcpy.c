/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:54:24 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/28 13:34:21 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char	*src_c;

	if (!dest)
		return (ft_strlen(src));
	else if (!src || !size)
		return (0);
	src_c = src;
	while (size && *src)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	if (!size)
		*(dest - 1) = 0;
	else
		*dest = 0;
	return (ft_strlen(src_c));
}
