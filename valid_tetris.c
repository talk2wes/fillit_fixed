/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:38:39 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/28 12:36:03 by wjohanso         ###   ########.fr       */
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

static int	adjacency_n_store(int num_lines, t_inputmap input,
		t_blocks *blocks)
{
	if (adjacency_counter(input.str) >= 6 && num_lines % 5 - 4 == 0)
		t_blocks_store(input, blocks);
	else if (adjacency_counter(input.str) < 6 && num_lines % 5 - 4 == 0)
		return (0);
	return (1);
}
/*
static void		helper(char **line, )
{
	int		hashes;

	
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
		if (!adjacency_n_store(num_lines, input, blocks))
			return (0);
*/
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
	int			ret;
	int			l_len;
	t_inputmap	input;

	num_lines = 0;
	line = (char**)ft_strnew(0);
	while ((ret = get_next_line(fd, line)) == 1)
	{
		helper(&num_lines, &hashes, &l_len);
		while (line[0][l_len] != '\n' && line[0][l_len] != 0)
			if (!helper2(line, &l_len, &hashes))
				return (0);
		if (!check_input_a(l_len, num_lines, hashes, line))
			return (0);
		input_map_store(line, num_lines, &input);
		if (!adjacency_n_store(num_lines, input, blocks))
			return (0);
	}
	ft_strdel(line);
	return (num_lines > MAXIMUM_LINES || num_lines % 5 != 4 || ret == -1) ?
	0 : 1;
}
