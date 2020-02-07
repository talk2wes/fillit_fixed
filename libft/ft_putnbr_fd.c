/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:08:17 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/31 16:38:15 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbr_fd(int num, int fd)
{
	char			c;

	c = '0';
	if (num == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num >= 10)
	{
		c = num % 10 + '0';
		ft_putnbr_fd(num / 10, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = num % 10 + '0';
		write(fd, &c, 1);
	}
}
