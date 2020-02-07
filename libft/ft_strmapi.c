/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 15:06:56 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 12:51:13 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int i, char))
{
	char	*in;
	char	*out;
	int		i;

	i = 0;
	if (f && s)
	{
		out = ft_strnew(ft_strlen(s));
		if (!out)
			return (NULL);
		in = out;
		while (s[i] != 0)
		{
			*in++ = f(i, s[i]);
			i++;
		}
		return (out);
	}
	return (NULL);
}
