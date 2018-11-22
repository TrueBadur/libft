/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:48:55 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/22 14:33:04 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int answer;
	int pos;

	answer = 0;
	pos = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n' || *str
			== '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		pos = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		answer = answer * 10 + (*str - '0');
		str++;
	}
	return (answer * pos);
}
