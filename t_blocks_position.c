/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:19:28 by wjohanso          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/21 19:35:45 by wjohanso         ###   ########.fr       */
=======
/*   Updated: 2020/02/21 19:19:17 by wjohanso         ###   ########.fr       */
>>>>>>> e132ff4e691b4776759bad451a49293087a35666
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

void	t_blocks_change_delta(t_blocks *blocks, int i, int j)
{
<<<<<<< HEAD
	int		n;

	n = 0;
	(*blocks).delta[0] = i;
	(*blocks).delta[1] = j;
	while (n < GRID_LENGTH)
=======
	int		x;

	x = 0;
	(*blocks).delta[0] = i;
	(*blocks).delta[1] = j;
	while (x < GRID_LENGTH)
>>>>>>> e132ff4e691b4776759bad451a49293087a35666
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
