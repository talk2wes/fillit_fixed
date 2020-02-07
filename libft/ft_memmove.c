/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:15:59 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 10:31:20 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str_d;
	const char	*str_s;

	str_d = (char*)dst;
	str_s = (char*)src;
	if (str_d > str_s)
	{
		while (len--)
		{
			str_d[len] = str_s[len];
		}
	}
	else
	{
		ft_memcpy(str_d, str_s, len);
	}
	return (dst);
}
