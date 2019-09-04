/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_err_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:56:17 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/03/19 16:56:17 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"

void	ft_ocl_err_handler(const char *message)
{
	write(1, message, ft_strlen(message));
	exit(10);
}
