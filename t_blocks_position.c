/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:19:28 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/21 12:13:46 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

void	t_blocks_change_delta(t_blocks *blocks, int i, int j)
{
	(*blocks).delta[0] = i;
	(*blocks).delta[1] = j;
}

int		**t_blocks_position(t_blocks *blocks)
{
	int		position[2][4];
	int		i;

	i = 0;
	while (i < GRID_LENGTH)
	{
		position[0][i] = (*blocks).x_loc[0][i] + (*blocks).delta[0];
		position[1][i] = (*blocks).y_loc[1][i] + (*blocks).delta[1];
		i++;
	}
	return (position);
}
