/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:38:17 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/26 23:21:56 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			out;
	t_blocks	*blocks;

	t_blocks_init((blocks = t_blocks_newnode()));
	fd = 0;
	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) >= 0 &&
			(out = valid_tetris(fd, blocks) == 1))
	{
		align_blocks(blocks);
		if (out == 1)
			solve(blocks, create_empty_board(board_size(tetris_count(blocks))),
				board_size(tetris_count(blocks)));
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "error\n", 6);
	close(fd);
	return (0);
}
