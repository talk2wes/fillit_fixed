#include "fillit.h"

int tetris_count(t_blocks *head)
{
    t_blocks *ptr;
    int count;
    ptr = head;
    count = 0;

    while (ptr != NULL)
    {
        count += 1;
        ptr = ptr->next;
    }
    return (count);
}
int		board_size(int tetris_count)
{
	int		total_symbols;
	int		row_col;

	total_symbols = 4 * tetris_count;
	row_col = find_sqrt(total_symbols);
	while (row_col * row_col < total_symbols)
		row_col += 1;
	return (row_col);
}

int		find_sqrt(int n)
{
	int		x;
	int		y;

	x = n;
	y = 1;
	while (x > y)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}

char	**create_empty_board(int map_size)
{
	int		i;
	int		j;
	char	**map;
	char	*row;

	i = 0;
	map = malloc(sizeof(*map) * map_size);
	while (i < map_size)
	{
		j = 0;
		row = malloc(sizeof(*row) * map_size);
		while (j < map_size)
		{
			row[j] = '.';
			j++;
		}
		map[i] = row;
		i++;
	}
	return (map);
}
char	**increase_map_size(char **map, int map_size)
{
	char	**new_map;
	int		i;

	i = 0;
	free_map(map, map_size);
	new_map = create_empty_board(map_size + 1);
	return (new_map);
}

void free_map(char **map, int map_size)
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

// void	free_list(t_inputmap *head)
// {
// 	t_blocks	*tmp;
// 	t_inputmap	input;
// 	int i;

// 	i = 0;
// 	while (head != NULL)
// 	{
// 		tmp = head;
// 		i = 0;
// 		while (i < 4)
// 		{
// 			free((*tmp).str[i]);
// 			i++;
// 		}
// 		head = head->next;
// 		free(tmp);
// 	}
// }
void	print_board(char **map, int map_size)
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
