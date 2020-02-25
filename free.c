#include "fillit.h"

void	free_map(char **map, int map_size)
{
	int	i;

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

// 	i = 0;
// 	while (head != NULL)
// 	{
// 		tmp = head;
// 		i = 0;
// 		while (i < 4)
// 		{
// 			free(tmp->str[i]);
// 			i++;
// 		}
// 		head = head->next;
// 		free(tmp);
// 	}
// }