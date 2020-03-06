/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:38:39 by wjohanso          #+#    #+#             */
/*   Updated: 2020/03/06 13:06:03 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_input_a(int l_len, int num_lines, int hashes, char **line)
{
	if ((num_lines % 5 == 0 && **line != '\0') ||
		(num_lines % 5 != 0 && l_len != 4))
		return (0);
	if (num_lines % 5 == 4 && hashes != 4)
		return (0);
	return (1);
}

static int	adjacency_n_store(int num_lines, t_inputmap input,
		t_blocks *blocks)
{
	if (adjacency_counter(input.str) >= 6 && num_lines % 5 - 4 == 0)
		t_blocks_store(input, blocks);
	else if (adjacency_counter(input.str) < 6 && num_lines % 5 - 4 == 0)
		return (0);
	return (1);
}

void		helper(int *num_lines, int *hashes, int *l_len)
{
	*hashes = (*num_lines % 5 == 0) ? 0 : *hashes;
	(*num_lines)++;
	*l_len = 0;
}

int			helper2(char **line, int *l_len, int *hashes)
{
	(*hashes) = (line[0][(*l_len)] == '#') ? (*hashes) + 1 : (*hashes);
	if (line[0][(*l_len)] != '.' && line[0][(*l_len)] != '#')
		return (0);
	(*l_len)++;
	return (1);
}

int			valid_tetris(int fd, t_blocks *blocks)
{
	int			hashes;
	int			num_lines;
	char		**line;
	t_inputmap	input;
	int			ret_len[2];

	num_lines = 0;
	line = (char**)malloc(sizeof(char**) * 10);
	while ((ret_len[0] = get_next_line(fd, line)) == 1)
	{
		helper(&num_lines, &hashes, &ret_len[1]);
		while (line[0][ret_len[1]] != '\n' && line[0][ret_len[1]] != 0)
			if (!helper2(line, &ret_len[1], &hashes))
				return (0);
		if (!check_input_a(ret_len[1], num_lines, hashes, line))
			return (0);
		input_map_store(line, num_lines, &input);
		if (!adjacency_n_store(num_lines, input, blocks))
			return (0);
	}
	free(line);
	return (num_lines > MAXIMUM_LINES || num_lines % 5 != 4 || ret_len[0] == -1)
	? 0 : 1;
}
