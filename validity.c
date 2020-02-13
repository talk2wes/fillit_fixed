/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaodum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:53:29 by jaodum            #+#    #+#             */
/*   Updated: 2020/02/13 10:32:02 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//check for adjacency if the pieces are touching, left, right, up, down.
//return success if the adjacency s greater than 6
//x_locs is the struct to store the row and column of the read file
int				check_adjacency(char **buff, t_coords *x_locs)
{
	int			i;
	int			adjacency_count;

	i = 0;
	adjacency_count = 0;
	while (i < 4)
	{
		if (x_locs[i].row != 0 && buff[x_locs[i].row - 1][x_locs[i].col] == '#')
			adjacency_count++;
		if (x_locs[i].row != 3 && buff[x_locs[i].row + 1][x_locs[i].col] == '#')
			adjacency_count++;
		if (x_locs[i].col != 3 && buff[x_locs[i].row][x_locs[i].col + 1] == '#')
			adjacency_count++;
		if (x_locs[i].col != 0 && buff[x_locs[i].row][x_locs[i].col - 1] == '#')
			adjacency_count++;
		i++;
	}
	if (adjacency_count >= 6)
		return (SUCCESS);
	return (INVALID_FILE);
}

int				record_tetris_locations(t_piece *piece, int row,
				int *col, int *count_hash)
{
	while ((*piece).buff[row][*col] != '\0')
	{
		if ((*piece).buff[row][*col] == '#')
		{
			(*piece).x_locs[*count_hash] = (t_coords){row, *col};
			(*count_hash)++;
		}
		else if ((*piece).buff[row][*col] != '.')
			return (INVALID_FILE);
		(*col)++;
	}
	return (SUCCESS);
}
