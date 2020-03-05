/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputmap_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:05:04 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/26 23:23:37 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		inputmap_reset(t_inputmap *input)
{
	ft_memset(&((*input).str), 0, END_INDEX + 1);
}
