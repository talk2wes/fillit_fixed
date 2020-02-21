/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:34:28 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/20 21:43:24 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define LR_SHIFT 1
#define UD_SHIFT 4
#define END_INDEX 15
#define BEG_INDEX 0

int		adjacency_counter(char *str)
{
	int i;
	int adjacency_count;

	i = 0;
	adjacency_count = 0;
	while (i <= END_INDEX)
	{
		if (str[i] == '#')
		{
			if (i + LR_SHIFT <= END_INDEX && str[i + LR_SHIFT] == '#')
				adjacency_count++;
			if (i - LR_SHIFT >= BEG_INDEX && str[i - LR_SHIFT] == '#')
				adjacency_count++;
			if (i + UD_SHIFT <= END_INDEX && str[i + UD_SHIFT] == '#')
				adjacency_count++;
			if (i - UD_SHIFT >= BEG_INDEX && str[i - UD_SHIFT] == '#')
				adjacency_count++;
		}
		i++;
	}
	return (adjacency_count);
}
