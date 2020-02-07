/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:55:03 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 11:36:50 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*org_s1;

	org_s1 = s1;
	s1 = s1 + ft_strlen(s1);
	while (*s2 && n)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = 0;
	return (org_s1);
}
