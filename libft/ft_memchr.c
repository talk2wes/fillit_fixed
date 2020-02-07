/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:19:12 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 10:32:58 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	while (n--)
	{
		str = (unsigned char*)s;
		if (*str == (unsigned char)c)
			return ((void*)str);
		s++;
	}
	return (NULL);
}
