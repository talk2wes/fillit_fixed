/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 15:22:14 by wjohanso          #+#    #+#             */
/*   Updated: 2020/01/21 10:27:59 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*newlink;

	newlink = (t_list*)malloc(sizeof(t_list));
	if (!newlink)
		return (NULL);
	if (!content)
	{
		newlink->content_size = 0;
		newlink->content = NULL;
	}
	else
	{
		newlink->content = (void*)malloc(sizeof(size_t) * content_size);
		if (!newlink->content)
			return (NULL);
		newlink->content_size = content_size;
		ft_memcpy(newlink->content, content, content_size);
	}
	newlink->next = NULL;
	return (newlink);
}
