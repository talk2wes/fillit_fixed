/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:17:35 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/30 21:35:29 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putendl_fd(const char *s, int fd)
{
	char	newline;

	if (!s)
		return ;
	newline = '\n';
	while (*s)
		write(fd, s++, 1);
	write(fd, &newline, 1);
}
