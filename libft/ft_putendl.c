/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:43:25 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/30 21:36:18 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putendl(const char *s)
{
	char	newline;

	if (!s)
		return ;
	newline = '\n';
	while (*s)
		write(1, s++, 1);
	write(1, &newline, 1);
}
