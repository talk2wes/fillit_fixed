/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 11:53:19 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 13:05:17 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	stupid_f1(const char *s, int l_ind)
{
	if ((s[l_ind] == ' ' || s[l_ind] == '\n' || s[l_ind] == '\t')
			&& (s[l_ind] != 0))
	{
		return (1);
	}
	return (0);
}

static int	stupid_f2(const char *s, int r_ind)
{
	if ((s[r_ind] == ' ' || s[r_ind] == '\n' || s[r_ind] == '\t')
			&& (s[r_ind] != 0))
	{
		return (1);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int				l_ind;
	int				r_ind;
	char			*str;
	char			*out;

	if (s == NULL)
		return (NULL);
	l_ind = 0;
	r_ind = ft_strlen(s) - 1;
	while (stupid_f1(s, l_ind))
		l_ind++;
	while (stupid_f2(s, r_ind))
		r_ind--;
	if (l_ind >= r_ind)
		return (ft_strdup(""));
	str = ft_strnew(r_ind - l_ind + 1);
	if (str)
	{
		out = str;
		while (s[l_ind] != 0 && l_ind <= r_ind)
			*str++ = s[l_ind++];
		return (out);
	}
	else
		return (NULL);
}
