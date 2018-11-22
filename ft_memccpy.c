/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:22:28 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/22 23:15:48 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	int i;

	i = 0;
	while ((size_t)++i <= n && ((unsigned char*)src)[i - 1] != (unsigned char)c)
		((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
	if (((unsigned char*)src)[i - 1] == (unsigned char)c)
		return (dst + i);
	return (NULL);
}
