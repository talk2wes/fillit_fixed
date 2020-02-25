#include "fillit.h"


int		check_Overlap(char **map, t_blocks *piece, int map_size)
{
	int i;
	int col;
	int row;

	i = 0;
	row = 0;
	while (row < map_size)
	{
		col = 0;
		while (col < map_size)
		{
			if ((*piece).x_position[i] < map_size && (*piece).y_position[i] < map_size
				&& map[(*piece).x_position[i]][(*piece).y_position[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			col++;
		}
		row++;
	}
		return (0);
}
char **remove_tetris(char **map, t_blocks *piece, int map_size)
{
	printf("remove_tetris map size = %i\n", map_size);
	int x;
	int y;
	x = 0;


	while (x < map_size)
	{
		y = 0;
		while (y < map_size)
		{
			if (map[x][y] == piece->letter)
				map[x][y] = '.';
			y++;
		}
		x++;
	}
	//prtinf("mapsize RETURN\n");
	return (map);
}

void place(char **map, t_blocks *piece, char letter)
{
	int x;
	int y;
	int i;
	i = 0;
	printf("place function\n");
	while (i < 4)
	{
		x = piece->x_position[i];
		y = piece->y_position[i];
		map[x][y] = letter;
		// printf("%d %d", x, y);
		// printf("printing inside the place function");
		// print_board(map, map_size);
		// printf("\n");
		i++;
	}
	//return (map);
}


char **backtrack(char **tetris_map, t_blocks *piece, int map_size)
{
	int row;
	int col;
	row = -1;
	char **map;
	
	if (piece == NULL)
	{
		return tetris_map;
	}
	map = NULL;
	while (++row < map_size)
	{
		col = 0;
		while (col < map_size)
		{
			t_blocks_change_delta(piece, col++, row);
			if (check_Overlap(tetris_map, piece, map_size))
			{
				printf("backtrack letter %c\n",(*piece).letter);
				//print_board(tetris_map, map_size);
				// printf("\n");
				place(tetris_map, piece,piece->letter);
				map = (backtrack(tetris_map, piece->next, map_size));
				
				
			}
			if (map)
			{
				return (map);
			}
			tetris_map = remove_tetris(tetris_map, piece, map_size);
		}
	}
	return NULL;	

}

void	solve(t_blocks *piece, char **map, int map_size)
{
	while (!backtrack(map, piece, map_size))
	{

		map = increase_map_size(map, map_size);
		map_size++;
	}
	print_board(map, map_size);
	free_map(map, map_size);
	//free_list(*piece);
}
