/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:58:34 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/23 22:36:14 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;

	if (!s)
		return (NULL);
	start = 0;
	while (*(s + start) == ' ' || *(s + start) == '\n' || *(s + start) == '\t')
		start++;
	len = ft_strlen(s);
	while (*(s + len) == ' ' || *(s + len) == '\n' || *(s + len) == '\t')
		len--;
	return (ft_strsub(s, start, len));
}
