/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:15:12 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/18 13:16:59 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		input_map_store(char **line, int line_num, t_inputmap *input)
{
	int		i;
	i = 0;
	while (i < 4 && line_num % 5 != 0 && line_num < MAXIMUM_LINES)
	{	
		(*input).str[(line_num/5) + i] = line[0][i];
		i++;
	}
	printf("line = \t\t%s\ninput = \t%s\n\n",*line,(*input).str);
}
