/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:33:03 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/13 13:42:51 by wjohanso         ###   ########.fr       */
/*   Updated: 2020/02/17 12:12:41 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Valid input
1 Tetriminos = 4x4 char array # of Tertiminos range = {1, 26} 
Valid Chars = {'.', '#'} All lines end in '\n' 
All Tetriminos 4x4 matricies must be seperated by a '\n'
Tetriminos Must resemble classic tetris pieces.

Each block ('#') must touch at least one other block on any of it's 4 sides.
*/
// 26 * 5 - 1 = 129 (5 LINES PER TETRIMINOS = 4X4 ARRAY + NEWLINE)
// MINUS 1 because the last tetriminos does not have a newline
/*Will return 0 for invalid tetriminos input, return 1 if the file is valid.
*/
#include "fillit.h"

int			valid_tetris(int fd)
{
	int			hashes;
	int			num_lines;
	char		**line;
	int			ret;
	int			l_len;
	t_inputmap	input;

	hashes = 0;
	num_lines = 0;
	line = NULL;
	line = (char**) ft_strnew(0);
	while ((ret = get_next_line(fd, line)) == 1)
	{
		num_lines++;
		l_len = 0;
		while (line[0][l_len] != '\n' && line[0][l_len] != 0)
		{
			hashes = (line[0][l_len] == '#') ? hashes + 1 : hashes;
			if (line[0][l_len] != '.' && line[0][l_len] != '#')
			{
				printf("VALID_TETRIS: Invalid Characters, ");
				printf("char = '%c' ascii = %i Loc (%i,%i)\n",line[0][l_len],
						line[0][l_len],num_lines,l_len + 1);
				return (0); 
			}
			l_len++;
		}
		printf("%s\n",*line);
		if ((l_len != 0 || l_len != 4) && num_lines % 5 == 0 && **line != '\0')
		{
			printf("VALID_TETRIS: Invalid line len OR Tetriminos LEN\n");
			printf("l_len = %i\t num_lines = %i\t **line = '%c'\n",
					l_len,num_lines,**line);
			return (0);
		}
		if (num_lines % 5 == 0 && hashes != 4)
		{
			printf("VALID_TETRIS: Invalid number of hashes = %i\n",hashes);
			return (0);
		}
		if (num_lines % 5 == 0) 
			hashes = 0;
		input_map_store(fd, line, num_lines, &input)
		if (adjacency_counter(&input) >= 6) 
		{
			
			//store into t_blocks
		}
		else
		{
			printf("VALID_TETRIS: ADJACENCY FAIL");
			return (0);
		}
	}
	ft_strdel(line);
	if (num_lines > MAXIMUM_LINES || num_lines % 5 != 4 || ret == -1)
	{
		printf("VALID_TETRIS: Too many tetriminos\n");
		printf("num_lines = %i\n",num_lines);
		return (0);
	}
	return (1);
}
