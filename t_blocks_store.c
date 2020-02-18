/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:00:38 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/17 16:21:24 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function will find all of the #'s from the input map and store them into
**the structure t_blocks, strarting at the terminating node.
**The input map only contains 1 tetrimino.
*/
#include "fillit.h"

void	t_blocks_store(t_inputmap input, t_blocks *blocks)
{
	t_blocks	*ptr_blocks;
	int			i;
	int			index;
	char		c;
	
	t_blocks_init(blocks);
	i = 0;
	c = 'A';
	index = 0;
	ptr_blocks = (*blocks).next;
	while (ptr_blocks.next != NULL)
	{
		ptr_blocks = ptr_blocks.next;
		c++;
	}
	(*ptr_blocks).letter = c;
	while (i < END_INDEX)
	{
		if (input[i] == '#')
		{
			(*ptr_blocks).x_loc[index] = i % 4;
			(*ptr_blocks).y_loc[index++] = i / 4;
		}
		i++;
	}
	
}
