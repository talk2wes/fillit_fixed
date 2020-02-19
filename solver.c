#include "fillit.h"


int		check_Overlap(char **map, t_blocks *piece, int map_size)
{
	int i;
	int y;
	int x;

	i = 0;
	x = 0;
	y = 0;
	x = (*piece).x_loc[i];
	y = (*piece).y_loc[i];
	while (i <= 4 && x < map_size && y < map_size && map[y][x] == '.')
	{
		i++;
		x = (*piece).x_loc[i];
		y = (*piece).y_loc[i];
		if (i == 4)
			return (1);

	}
	return (0);
}
char ** remove_tetris(t_blocks *piece, int map_size, char **map)
{
	int i;
	int x;
	int y;
	x = 0;
	y = 0;

	while (i < 4)
	{
		x = (*piece).x_loc[i];
		y = (*piece).y_loc[i];
		map[x][y] = '.';
		i += 1;
	}
}

char **place(char **map, t_blocks *piece, int map_size)
{
	int y;
	int x;
	int i;
	i = 0;
	x = 0;
	while (x < map_size)
	{
		y = 0;
		while (y < map_size)
		{
			if ((*piece).x_loc[i] == x && (*piece).y_loc[i] == y)
			{
				map[x][y] == piece->letter;
				i++;
			}
			y++;
		}
		x++;
	}
	return (map);
}

char **backtrack(char **tetris_map, t_blocks *piece, int map_size)
{
	int row;
	int col;
	row = 0;
	char **map;
	if (piece == NULL)
	{
		return map;
	}
	while (row < map_size)
	{
		col = 0;
		while (col < map_size)
		{
			smallest_xy_tetris(piece, row, col);
			if (check_Overlap(map, piece, map_size))
			{
				map = (backtrack(place(tetris_map, piece, map_size), piece->next, map_size));
			}
			if (map)
			{
				return (map);
			}
			tetris_map = remove_tetris(tetris_map, piece, map_size);
		}
	}	

}

void	solve(t_blocks **piece, char **map, int map_size)
{
	while (!backtrack(map, *piece, map_size))
	{
		map = resize_map(map, map_size);
		map_size++;
	}
	print_board(map, map_size);
	// free_map(map, map_size);
	// free_list(*piece);
}
