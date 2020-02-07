/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:10:04 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 12:40:35 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*s;
	char	*s2;

	s = (void*)malloc(size);
	s2 = (char*)s;
	if (s)
	{
		while (size--)
		{
			*s2 = 0;
			s2++;
		}
		return (s);
	}
	return (NULL);
}
