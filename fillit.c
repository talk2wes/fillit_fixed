/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:38:17 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/26 22:22:21 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		out;
	char	*testfile;
	t_blocks	*blocks;
	int num_piece;
	char **map;
	int map_size;

	blocks = t_blocks_newnode();
	t_blocks_init(blocks);
	testfile = ft_strnew(99);
	out = -1;
	fd = 0;
	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) >= 0)
	{
			out = valid_tetris(fd, blocks);
			align_blocks(blocks);
			if (out == 1)
			{
				num_piece = tetris_count(blocks);
				map_size = board_size(num_piece);
				map = create_empty_board(map_size);
				solve(blocks, map, map_size);
			}
			else
				write(1, "error\n", 6);
	}
	else
		write(1, "error\n", 6);
	close(fd);	
	return (0);
}
