#include "fillit.h"

void smallest_xy_tetris(t_blocks *piece)
{
	int i;
	int smallest_pos_x = (*piece).x_loc[0];
	int smallest_pos_y = (*piece).y_loc[0];
	i = 1;
	while (i < 4)
	{
		if ((*piece).x_loc[i] < smallest_pos_x)
		{
			smallest_pos_x = (*piece).x_loc[i];
		}
		if ((*piece).y_loc[i] < smallest_pos_y)
		{
			smallest_pos_y = (*piece).y_loc[i];
		}
		i++;
	}
}
