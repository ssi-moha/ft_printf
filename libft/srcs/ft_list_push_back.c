/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:24:03 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/01/29 14:53:53 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *content)
{
	t_list *list;

	list = *begin_list;
	while (list->next != NULL)
		list = list->next;
	list->next = ft_lstnew(content, sizeof(content));
}
