/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:55:16 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/17 16:21:46 by wjohanso         ###   ########.fr       */
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
			blocks.delta[i] = 0;
		blocks.x_loc[i] = 0;
		blocks.y_loc[i++] = 0;
	}
	blocks.letter = "";
	blocks.next = NULL;
}
