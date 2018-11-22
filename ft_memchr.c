/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:20:04 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/23 00:03:42 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	while (*(unsigned char *)s != (unsigned char)c && --n)
		s++;
	if (n == 0)
		return (NULL);
	return (void *)(s);
}
