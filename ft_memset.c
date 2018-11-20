/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:06:41 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/20 17:29:18 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_m;
	size_t			i;

	b_m = (unsigned char *)b;
	i = 0;
	while (i < len)
		b_m[i++] = (unsigned char)c;
	return (b);
}
