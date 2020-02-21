/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:00:38 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/21 12:20:12 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function will find all of the #'s from the input map and store them into
**the structure t_blocks, strarting at the terminating node.
**The input map only contains 1 tetrimino.
*/
#include "fillit.h"
//This function doesn't check if the linked list is too long, parent function
//should check for this.

void	t_blocks_store_xydata(t_blocks *blocks, t_inputmap *input)
{
	int		i;
	int		index;

	index = 0;
	i = 0;
	//printf("t_blocks_store_xydata\n");
	while (i <= END_INDEX)
	{
		if ((*input).str[i] == '#')
		{
			//printf("i = %i\tindex = %i\t(x,y) = (%i,%i)\n",i,index,i%4, i /4);
			(*blocks).x_loc[index] = i % 4;
			(*blocks).y_loc[index++] = i / 4;
		}
		i++;
	}
}

int		t_blocks_find_length(t_blocks *blocks)
{
	int 		i;
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

void	t_blocks_print_data(t_blocks *blocks) // REMOVE THIS : DEBUGGING 
{
	int i = 0;
	int		block_num = 1;
	t_blocks	*temp_block;

	temp_block = blocks;	
	printf("t_blocks_print_data function\t");
	printf("blocks length = %i\n",t_blocks_find_length(blocks));
	while (1)
	{
		i = 0;
		printf("block #%i\n",block_num++);
		while (i < 4)
		{		
			printf("Char %i (x,y) = (%i,%i)\n",i,
			(*blocks).x_loc[i],(*blocks).y_loc[i]);
			i++;
		}
		printf("delta = (%i,%i)\t letter = %c\tnext = %p\n",(*blocks).delta[0],
			(*blocks).delta[1],(*blocks).letter,(*blocks).next);
		blocks = (*blocks).next;
		if (blocks == NULL)
			break ;
	}
}

void	t_blocks_store(t_inputmap input, t_blocks *blocks)
{
	int			i;
	int			index;
	char		c;
	t_blocks	*block_head;

	block_head = blocks;
	i = 0;
	c = 'A';
	index = 0;
	// For the first block, store the data
	if ((*blocks).delta[0] == -1)
	{
		t_blocks_store_xydata(blocks, &input);
		(*blocks).letter = c;
		t_blocks_change_delta(blocks,0,0);
		return ;
	}
	//For all blocks after the first node has stored data.
	while ((*blocks).next != NULL)
	{
		blocks = (*blocks).next;
		c++;
	}
	(*blocks).next = t_blocks_newnode();
	blocks = (*blocks).next;
	t_blocks_store_xydata(blocks, &input);
	t_blocks_change_delta(blocks,0,0);
	(*blocks).letter = ++c;
	//t_blocks_print_data(blocks); // remove me: debugging  
	blocks = block_head;
}
