/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:15:12 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/26 23:55:49 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	input_map_store(char **line, int line_num, t_inputmap *input)
{
	int		i;

	i = 0;
	if (line_num % 5 == 0)
	{
		inputmap_reset(input);
		return ;
	}
	if (line_num > 5)
		line_num = line_num % 5;
	while (i < 4 && line_num % 5 != 0 && line_num < MAXIMUM_LINES)
	{
		(*input).str[(line_num - 1) * 4 + i] = line[0][i];
		i++;
	}
}
