/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minmapsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:25:32 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/27 00:35:06 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Find the minmum size of the nxn coordinate map needed to find the smallest
**square.
*/

#include "fillit.h"

int			find_minmapsize(t_blocks blocks)
{
	int		size;
	int		i;

	i = 1;
	while (blocks.next != NULL)
	{
		blocks = *(blocks.next);
		i++;
	}
	i *= 4;
	size = 1;
	while (1)
	{
		if (size * size >= i)
			break ;
		size++;
	}
	return (size);
}
