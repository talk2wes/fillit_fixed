/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:38:17 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/07 11:55:09 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd[10];
	t_text	file_1;

	file_1->str = NULL;
	file_1->next = NULL;

	fd[0] = open("./testing/g_1.txt");
	//usage case
	//if (argc == 1)

	if (argc == 2 && ft_strcmp("testing", argv[1]) == 0)
	{
		valid_tetris(fd[0], t_text);
	}
	close(fd[0]);	
	return (0);
}
