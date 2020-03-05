/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:38:17 by wjohanso          #+#    #+#             */
/*   Updated: 2020/03/05 14:30:16 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_blocks(t_blocks *blocks)
{
	t_blocks	*next_block;

	while (blocks != NULL)
	{
		next_block = (*blocks).next;
		free(blocks);
		blocks = next_block;
	}
}

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
	else if (argc != 2)
		write(1, "usage: ./fillit source_file\n", 29);
	else
		write(1, "error\n", 6);
	free_blocks(blocks);
	close(fd);
	return (0);
}
