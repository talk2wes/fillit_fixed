/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:38:44 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 10:16:05 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_bzero(void *b, size_t len)
{
	size_t		index;
	char		*s1;

	s1 = b;
	index = 0;
	while (index < len)
	{
		s1[index] = '\0';
		index++;
	}
	return (b);
}
