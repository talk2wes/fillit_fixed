/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_blocks_newnode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:02:40 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/26 23:47:02 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_blocks	*t_blocks_newnode(void)
{
	t_blocks	*new_block;

	new_block = malloc(sizeof(t_blocks));
	t_blocks_init(new_block);
	return (new_block);
}
