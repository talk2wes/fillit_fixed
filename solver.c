#include "fillit.h"


int		check_tetris(char **map, t_piece *piece, int map_size)
{
	int i;
	int y;
	int x;

	i = 0;
	x = 0;
	while (x < map_size)
	{
		y = 0;
		while (y < map_size)
		{
			if (piece->tetris_coords[i].x < map_size && piece->tetris_coords[i].y < map_size
				&& map[piece->tetris_coords[i].x][piece->tetris_coords[i].y] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}



void	solve(t_piece *piece, char **map, int map_size)
{
	while (!algo(map, piece, map_size))
	{
		map = resize_map(map, map_size);
		//map_size++;
	}
	print_board(map, map_size);
	free_map(map, map_size);
	free_list(piece);
}
