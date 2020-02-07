/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:55:48 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 12:24:00 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	stupid_0(const char *hay, const char *ned, size_t h, size_t n)
{
	if (hay[h + n] == ned[n] && hay[h + n] != 0)
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *hay, const char *ned, size_t len)
{
	size_t	h;
	size_t	n;
	size_t	ned_len;
	size_t	num_same_char;

	num_same_char = 0;
	h = 0;
	n = 0;
	ned_len = ft_strlen(ned);
	if (*ned == 0)
		return ((char*)hay);
	while (hay[h] != 0 && h < len)
	{
		n = 0;
		while (stupid_0(hay, ned, h, n) && ned[n] != 0 && (n + h) < len)
		{
			num_same_char++;
			n++;
			if (num_same_char == ned_len)
				return ((char*)&hay[h]);
		}
		h++;
		num_same_char = 0;
	}
	return (NULL);
}
