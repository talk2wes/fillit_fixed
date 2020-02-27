/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:38:39 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/27 01:16:47 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_input_a(int l_len, int num_lines, int hashes, char **line)
{
	if ((l_len != 0 && l_len != 4) || (num_lines % 5 == 0 && **line != '\0'))
		return (0);
	if (num_lines % 5 == 4 && hashes != 4)
		return (0);
	return (1);
}

int			valid_tetris(int fd, t_blocks *blocks)
{
	int			hashes;
	int			num_lines;
	char		**line;
	int			ret;
	int			l_len;
	t_inputmap	input;

	num_lines = 0;
	line = (char**)ft_strnew(0);
	while ((ret = get_next_line(fd, line)) == 1)
	{
		hashes = (num_lines % 5 == 0) ? 0 : hashes;
		num_lines++;
		l_len = 0;
		while (line[0][l_len] != '\n' && line[0][l_len] != 0)
		{
			hashes = (line[0][l_len] == '#') ? hashes + 1 : hashes;
			if (line[0][l_len] != '.' && line[0][l_len] != '#')
				return (0);
			l_len++;
		}
		if (!check_input_a(l_len, num_lines, hashes, line))
			return (0);
		input_map_store(line, num_lines, &input);
		if (adjacency_counter(input.str) >= 6 && num_lines % 5 - 4 == 0)
			t_blocks_store(input, blocks);
		else if (adjacency_counter(input.str) < 6 && num_lines % 5 - 4 == 0)
			return (0);
	}
	ft_strdel(line);
	if (num_lines > MAXIMUM_LINES || num_lines % 5 != 4 || ret == -1)
		return (0);
	return (1);
}
