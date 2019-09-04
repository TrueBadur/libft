/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:33:42 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/05 17:57:26 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btavl.h"

t_btavl	*ft_avlmin(t_btavl *tr)
{
	return ((tr->left) ? ft_avlmin(tr->left) : tr);
}
