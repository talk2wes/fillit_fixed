/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:14:24 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 10:26:03 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*str_d;
	const char	*str_s;
	size_t		i;

	str_d = dst;
	str_s = src;
	i = 0;
	while (i < n && (dst || src))
	{
		str_d[i] = str_s[i];
		i++;
	}
	return (dst);
}
