/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:38:17 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/09 12:57:36 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd[10];
	t_text	file_1;
	int		out;
	char	*testfile;

	testfile = ft_strnew(99);
	out = -1;
	file_1.str = NULL;
	file_1.next = NULL;

	//usage case
	//if (argc == 1)
	printf("argc == %i\n", argc);
	if (argc == 3 && ft_strcmp("testing", argv[1]) == 0)
	{
		printf("argv[2] = \"%s\"\nargv[3] = \"%s\"\n", argv[2], argv[3]);
		testfile = ft_strjoin("./testfiles/", argv[2]);	
		fd[0] = open(testfile, O_RDONLY);
		printf("testing: %s\n", testfile);
		out = valid_tetris(fd[0], file_1);
		if (out == 1)
			printf("VALID\n");
		else
			printf("INVALID %i\n", out);
	}
	close(fd[0]);	
	return (0);
}
