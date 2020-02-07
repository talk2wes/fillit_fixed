/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_magnitude.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:10:27 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/30 21:50:24 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_magnitude(int num)
{
	int				mag;
	unsigned int	n;

	n = 0;
	if (num == -2147483648)
		return (9);
	if (num < 0)
		n = (unsigned int)-1 * num;
	else if (num > 0)
		n = num;
	mag = -1;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		n /= 10;
		mag++;
	}
	return (mag);
}
