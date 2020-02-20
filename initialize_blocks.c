/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_blocks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 12:55:02 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/16 14:53:56 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/libft/libft.h"

void		initialize_blocks(t_blocks blocks)
{
	blocks.letter = "";
	blocks.next = NULL;
}
