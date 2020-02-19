/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:00:38 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/18 17:36:23 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function will find all of the #'s from the input map and store them into
**the structure t_blocks, strarting at the terminating node.
**The input map only contains 1 tetrimino.
*/
#include "fillit.h"

void	t_blocks_store(t_inputmap input, t_blocks *blocks)
{
	int			i;
	int			index;
	char		c;
	//t_blocks	*new_block;

	//t_blocks_init(blocks);
	i = 0;
	c = 'A';
	index = 0;
	//printf("BLOCK_STORE: ENTRY\n");
	while ((*blocks).next != NULL)
	{
		printf("c = %c\n",c);
		blocks = (*blocks).next;
		c++;
	}
	(*blocks).next = &(t_blocks_newnode());
	printf("YES\n");
	
	
	blocks = (*blocks).next;
	(*blocks).letter = c;
	printf("BLOCK_STORE 2\n");
	while (i < END_INDEX)
	{
		if (input.str[i] == '#')
		{
			printf("i = %i index = %i\t(x,y) = (%i,%i)\n",i,index,i%4, i /4);
			(*blocks).x_loc[index] = i % 4;
			(*blocks).y_loc[index++] = i / 4;
		}
		i++;
	}
	
}
