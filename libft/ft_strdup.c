/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:13:56 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 11:30:40 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*s2;

	length = ft_strlen(&s1[0]);
	s2 = malloc(sizeof(char) * (length + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}
	while (length >= 0)
	{
		s2[length] = s1[length];
		length--;
	}
	return (&s2[0]);
}
