/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:34:28 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/17 10:50:40 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define LR_SHIFT 1
#define UD_SHIFT 5

int		adjacency_counter(char *str)
{
	int i;
	int adjacency_count;

	i = 0;
	adjacency_count = 0;
	while (i < 19)
	{
		if (str[i] == '#')
		{
			if (i + LR_SHIFT <= 18 && str[i + LR_SHIFT] == '#')
				adjacency_count++;
			if (i - LR_SHIFT >= 0 && str[i - LR_SHIFT] == '#')
				adjacency_count++;
			if (i + UD_SHIFT <= 18 && str[i + UD_SHIFT] == '#')
				adjacency_count++;
			if (i - UD_SHIFT >= 0 && str[i - UD_SHIFT] == '#')
				adjacency_count++;
		}
		i++;
	}
	return (adjacency_count);
}
