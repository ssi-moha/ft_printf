/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:57:21 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/01/17 17:03:22 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lstnew;

	lstnew = (t_list*)malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	if (content == NULL)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	else
	{
		lstnew->content = malloc(content_size);
		if (lstnew->content != NULL)
		{
			ft_memcpy(lstnew->content, content, content_size);
			lstnew->content_size = content_size;
		}
	}
	lstnew->next = NULL;
	return (lstnew);
}
