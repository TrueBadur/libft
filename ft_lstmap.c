/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:30:34 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/26 17:11:53 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_delcont(void *cont, size_t size)
{
	size += 0;
	free(cont);
	cont = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *ret_c;

	if (!lst)
		return (NULL);
	if (!(ret = f(lst)))
		return (NULL);
	ret_c = ret;
	lst = lst->next;
	ret = ret->next;
	while (lst)
	{
		if (!(ret = f(lst)))
		{
			ft_lstdel(&ret_c, &ft_delcont);
			return (NULL);
		}
		lst = lst->next;
		ret = ret->next;
	}
	return (ret_c);
}
