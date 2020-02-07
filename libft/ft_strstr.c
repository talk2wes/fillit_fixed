/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:53:34 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 11:44:57 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		n;
	int		h;

	h = 0;
	if (!haystack && !needle)
		return (NULL);
	if (!*needle)
		return ((char*)haystack);
	while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n] && haystack[h + n] != '\0')
			n++;
		if (n == (int)ft_strlen(needle))
			return ((char*)&haystack[h]);
		h++;
	}
	return (NULL);
}
