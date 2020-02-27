/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:55:16 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/26 23:57:12 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		t_blocks_init(t_blocks *blocks)
{
	int		i;

	i = 0;
	while (i < GRID_LENGTH)
	{
		if (i < 2)
			(*blocks).delta[i] = INITIAL_DELTA;
		(*blocks).x_loc[i] = INITIAL_XY;
		(*blocks).y_loc[i++] = INITIAL_XY;
		(*blocks).x_position[i] = INITIAL_POSITION;
		(*blocks).y_position[i] = INITIAL_POSITION;
	}
	(*blocks).letter = (char)INITIAL_LETTER;
	(*blocks).next = NULL;
}
