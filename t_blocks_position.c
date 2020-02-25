/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:19:28 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/25 13:01:01 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

void	t_blocks_change_delta(t_blocks *blocks, int i, int j)
{
	int		x;

	x = 0;
	(*blocks).delta[0] = i;
	(*blocks).delta[1] = j;
	while (x < GRID_LENGTH)
	{
		(*blocks).x_position[x] = (*blocks).x_loc[x] + (*blocks).delta[0];
		(*blocks).y_position[x] = (*blocks).y_loc[x] + (*blocks).delta[1];
		x++;
	}
}


/*
void		t_blocks_update_position(t_blocks *blocks)
{
	int		i;

	i = 0;
	while (i < GRID_LENGTH)
	{
		(*blocks).x_position[i] = (*blocks).x_loc[i] + (*blocks).delta[0];
		(*blocks).y_position[i] = (*blocks).y_loc[i] + (*blocks).delta[1];
		i++;
	}
}


t_blocks_change_delta(blocks, 1, 0);
t_blocks_update_position(blocks);
*/
