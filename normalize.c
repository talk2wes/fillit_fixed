#include "fillit.h"

void smallest_xy_tetris(t_blocks *piece, int x, int y)
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
	i--;
	while (i >= 0)
	{
		(*piece).x_loc[i] = (*piece).x_loc[i] - smallest_pos_x + (*piece).delta[x];
		(*piece).y_loc[i] = (*piece).y_loc[i] - smallest_pos_y + (*piece).delta[y];
		--i;
	}
}
void align(t_block *blocks)
{
	int lowest_y;
	int lowest_x;
	int i;
	i = 1;
	lowest_x = (*blocks).x_loc[0];
	lowest_y = (*blocks).y_loc[0];
	while (i < 4)
	{
		if (x_loc[i].row < lowest_x)
		{
			lowest_x = x_loc[i].row;
		}
		if (y_loc[i].col < lowest_y)
		{
			lowest_y = y_loc[i].col;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		x_loc[i].row -= lowest_x;
		y_loc[i].col -= lowest_y;
		i++;
	}
}
/*
void align(t_coords *x_loc, t_coords *y_loc)
{
	int lowest_y;
	int lowest_x;
	int i;
	i = 1;
	lowest_x = x_loc[0].row;
	lowest_y = y_loc[0].col;
	while (i < 4)
	{
		if (x_loc[i].row < lowest_x)
		{
			lowest_x = x_loc[i].row;
		}
		if (y_loc[i].col < lowest_y)
		{
			lowest_y = y_loc[i].col;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		x_loc[i].row -= lowest_x;
		y_loc[i].col -= lowest_y;
		i++;
	}
}
