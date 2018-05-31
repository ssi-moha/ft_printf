/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:39:55 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/12 05:01:51 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *begin_list;

	if (lst != NULL)
	{
		newlist = (f)(lst);
		begin_list = newlist;
		lst = lst->next;
	}
	while (lst != NULL)
	{
		newlist->next = (f)(lst);
		newlist = newlist->next;
		lst = lst->next;
	}
	newlist = NULL;
	return (begin_list);
}
