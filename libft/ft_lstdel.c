/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:54:13 by wjohanso          #+#    #+#             */
/*   Updated: 2020/01/21 10:24:36 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;
	t_list	*tmp;

	p = *alst;
	while (p && del)
	{
		tmp = p;
		ft_lstdelone(&p, del);
		p = tmp->next;
	}
	*alst = NULL;
}
