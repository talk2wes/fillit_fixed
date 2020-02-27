/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:24:48 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/26 23:31:24 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		align_blocks(t_blocks *blocks)
{
	t_blocks	*block_head;

	block_head = blocks;
	while (1)
	{
		align(blocks);
		blocks = (*blocks).next;
		if (blocks == NULL)
			break ;
	}
	blocks = block_head;
}

void		align(t_blocks *blocks)
{
	int			smallest_x;
	int			smallest_y;
	int			i;

	i = 1;
	smallest_x = (*blocks).x_loc[0];
	smallest_y = (*blocks).y_loc[0];
	while (i < 4)
	{
		if ((*blocks).x_loc[i] < smallest_x)
			smallest_x = (*blocks).x_loc[i];
		if ((*blocks).y_loc[i] < smallest_y)
			smallest_y = (*blocks).y_loc[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*blocks).x_loc[i] -= smallest_x;
		(*blocks).y_loc[i++] -= smallest_y;
	}
}
