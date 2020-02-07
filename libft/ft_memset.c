/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:36:08 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 10:24:24 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;
	char	*s1;

	s1 = b;
	index = 0;
	if (c < 0)
		c = c * (-1);
	while (index < len)
	{
		s1[index] = c;
		index++;
	}
	return (b);
}
