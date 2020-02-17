/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:38:17 by wjohanso          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/16 14:53:50 by wjohanso         ###   ########.fr       */
=======
/*   Updated: 2020/02/17 11:15:32 by wjohanso         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_text	file_1;
	int		out;
	char	*testfile;
	t_blocks	blocks;
	
	initialize_blocks(blocks);

	testfile = ft_strnew(99);
	out = -1;
	file_1.str = NULL;
	file_1.next = NULL;

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
		out = valid_tetris(fd[0], file_1);
		if (out == 1)
			printf("VALID\n");
		else
			printf("INVALID %i\n", out);
	}
	close(fd);	
	return (0);
}
