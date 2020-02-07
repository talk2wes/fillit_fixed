/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:48:52 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 11:43:33 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*last_c;

	last_c = NULL;
	i = 0;
	if ((char)c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char*)&s[i]);
	}
	else
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
			{
				last_c = &s[i];
			}
			i++;
		}
		return ((char*)last_c);
	}
}
