/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:47:11 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/28 11:47:45 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
