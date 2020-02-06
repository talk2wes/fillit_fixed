/* ************************************************************************** *
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:33:03 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/06 10:56:01 by wjohanso         ###   ########.fr       */
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
# define MAXIMUM_LINES 129
/*Will return 0 for invalid tetriminos input, return 1 if the file is valid.
*/
void		valid_tetris(int fd)
{
	int		hashes;
	int		num_lines;
	char	*line;
	int		ret;

	hashes = 0;
	num_lines = 0;
	line = ft_strnew(0);
	//checking all of the teriminos
	while ((ret = get_next_line(fd, line)) == 1)
	{
		num_lines++;
		l_len = 0;
		//check each character in each line
		while (line[l_len] != '\n') 		
		{
			hashes = (line[l_len] == '#') ? hashes + 1 : hashes; 		
			if (line[l_len] != '.' || line[l_len] != '#') 			
				return (0) // INVALID CHARACTERS 	
			l_len++;
		}
		//check line len & tetriminos length
		if (l_len != 4 || (num_lines % 5 == 0 && *line != '\n'))
			return (0);
		if (num_lines % 5 == 0 && hashes > 4) 
			//reset the hash char count for next tetriminos
			hashes = 0;	
	}
	ft_strdel(&line);
	if (num_lines > MAXIMUM_LINES || num_lines % 5 != 4 || ret == -1)
		return (0); // TOO MANY TETRIMINOS
	return (1);
}
