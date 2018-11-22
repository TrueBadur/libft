/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/22 19:00:29 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	if (dst > src)
	{
		while (len--)
			((char*)dst)[len] = ((char*)src)[len];
	}
	else
	{
		i = -1;
		while ((size_t)++i < len)
			((char*)dst)[i] = ((char*)src)[i];
	}
	return (dst);
}
