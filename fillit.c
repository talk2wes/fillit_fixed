/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:38:17 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/20 22:17:03 by wjohanso         ###   ########.fr       */
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
	//usage case
	//if (argc == 1)
	//printf("argc == %i\n", argc);
	if (argc == 3 && ft_strcmp("testing", argv[1]) == 0)
	{
		//printf("argv[2] = \"%s\"\n", argv[2]);
		testfile = ft_strjoin("./testfiles/", argv[2]);	
		fd = open(testfile, O_RDONLY);
		if (fd == -1)
		{
			printf("invalid file, abort\n");
			return (0);
		}
		printf("testing: %s\n", testfile);

		out = valid_tetris(fd, blocks);
		
		t_blocks_print_data(blocks);
		printf("align_blocks\n");
		align_blocks(blocks);
		t_blocks_print_data(blocks);
		if (out == 1)
			printf("VALID\n");
			num_piece = tetris_count(blocks);
			map_size = board_size(num_piece);
			map = create_empty_board(map_size);
			//print_board(map, map_size);
			solve(blocks, map, map_size);

		else
			printf("INVALID %i\n", out);
		//align_blocks(blocks);
		//printf("ALIGN BLOCKS\n");
		//t_blocks_print_data(blocks);
	}
	close(fd);	
	return (0);
}
