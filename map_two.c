/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:26:29 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/28 11:37:31 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**increase_map_size(char **map, int map_size)
{
	char	**new_map;
	int		i;

	i = 0;
	free_map(map, map_size);
	new_map = create_empty_board(map_size + 1);
	return (new_map);
}

void		free_map(char **map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void		print_board(char **map, int map_size)
{
	int i;
	int j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			write(1, &map[j][i], 1);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
