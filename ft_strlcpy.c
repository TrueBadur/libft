/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:54:24 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/10/23 23:15:37 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char *src_c;

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
