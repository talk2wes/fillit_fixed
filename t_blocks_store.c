/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:00:38 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/20 11:02:59 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function will find all of the #'s from the input map and store them into
**the structure t_blocks, strarting at the terminating node.
**The input map only contains 1 tetrimino.
*/
#include "fillit.h"
//This function doesn't check if the linked list is too long, parent function
//should check for this.

void	t_blocks_store_xydata(t_blocks *block, t_inputmap *input)
{
	int		i;

	i = 0;
	while (i < END_INDEX)
	{
		if ((*input).str[i] == '#')
		{
			printf("i = %i\tindex = %i\t(x,y) = (%i,%i)\n",i,index,i%4, i /4);
			(*blocks).x_loc[index] = i % 4;
			(*blocks).y_loc[index++] = i / 4;
		}
		i++;
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
	if (ft_strcmp(&((*blocks).letter),"") == 0)
	{
		t_blocks_store_xydata(input, blocks);
		(*blocks).letter = c;
		return ;
	}
	//For all blocks after the first node has stored data.
	while ((*blocks).next != NULL)
	{
		//find the terminating node
		printf("c = %c\n",c);
		blocks = (*blocks).next;
		c++;
	}
	t_blocks_store_xydata(input, blocks);
	(*blocks).letter = c;
/*		
	while (i < END_INDEX)
	{
		if (input.str[i] == '#')
		{
			printf("i = %i\tindex = %i\t(x,y) = (%i,%i)\n",i,index,i%4, i /4);
			(*blocks).x_loc[index] = i % 4;
			(*blocks).y_loc[index++] = i / 4;
		}
		i++;
	}
	*/
	blocks = block_head;
}
