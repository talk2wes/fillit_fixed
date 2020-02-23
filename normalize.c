/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:24:48 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/20 21:34:17 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
 * What does this function do? 
 * -Wes
 */


void smallest_xy_tetris(t_blocks *piece, int x, int y)
{
	int i;
	
	int smallest_pos_x = (*piece).x_loc[0];
	int smallest_pos_y = (*piece).y_loc[0];
	i = 1;
	while (i < 4)
	{
		if ((*piece).x_loc[i] < smallest_pos_x)
		{
			smallest_pos_x = (*piece).x_loc[i];
		}
		if ((*piece).y_loc[i] < smallest_pos_y)
		{
			smallest_pos_y = (*piece).y_loc[i];
		}
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*piece).x_loc[i] = (*piece).x_loc[i] - smallest_pos_x + x;
		(*piece).y_loc[i] = (*piece).y_loc[i] - smallest_pos_y + y;
		--i;
	}
}


void	align_blocks(t_blocks *blocks)
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

void align(t_blocks *blocks)
{
	int	smallest_x; 
	int smallest_y;
	int i;
	
	i = 1;
	smallest_x = (*blocks).x_loc[0];
	smallest_y = (*blocks).y_loc[0];
	while (i < 4)
	{
		if ((*blocks).x_loc[i] < (*blocks).x_loc[i - 1])
			smallest_x = (*blocks).x_loc[i]; 
		if ((*blocks).y_loc[i] < (*blocks).y_loc[i - 1])
			smallest_y = (*blocks).y_loc[i];
		i++;
	}
	i = 0;
	printf("Smallest x & y values found are (x,y) = (%i,%i)\n",
			smallest_x,smallest_y);
	while (i < 4)
	{
		(*blocks).x_loc[i] -= smallest_x;
		(*blocks).y_loc[i] -= smallest_y;	
		i++;
	}
}
