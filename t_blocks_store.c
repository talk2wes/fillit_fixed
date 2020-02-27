/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:00:38 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/26 23:45:58 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This function will find all of the #'s from the input map and store them into
**the structure t_blocks, strarting at the terminating node.
**The input map only contains 1 tetrimino.
*/

#include "fillit.h"

void	t_blocks_store_xydata(t_blocks *blocks, t_inputmap *input)
{
	int		i;
	int		index;

	index = 0;
	i = 0;
	while (i <= END_INDEX)
	{
		if ((*input).str[i] == '#')
		{
			(*blocks).x_loc[index] = i % 4;
			(*blocks).y_loc[index++] = i / 4;
		}
		i++;
	}
}

int		t_blocks_find_length(t_blocks *blocks)
{
	int			i;
	t_blocks	*temp_blocks;

	temp_blocks = blocks;
	i = 0;
	while ((*temp_blocks).next != NULL)
	{
		temp_blocks = (*temp_blocks).next;
		i++;
	}
	return (++i);
}

void	t_blocks_store(t_inputmap input, t_blocks *block_head)
{
	int			i;
	int			index;
	char		c;
	t_blocks	*blocks;

	i = 0;
	c = 'A';
	index = 0;
	if ((*(blocks = block_head)).delta[0] == -1)
	{
		t_blocks_store_xydata(blocks, &input);
		(*blocks).letter = c;
		t_blocks_change_delta(blocks, 0, 0);
		return ;
	}
	while ((*blocks).next != NULL)
	{
		blocks = (*blocks).next;
		c++;
	}
	(*blocks).next = t_blocks_newnode();
	blocks = (*blocks).next;
	t_blocks_store_xydata(blocks, &input);
	t_blocks_change_delta(blocks, 0, 0);
	(*blocks).letter = ++c;
}
