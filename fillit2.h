#ifndef FILLIT_H
# define FILLIT_H

/*
**	Header files and libraries to include
*/
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/*
**	MACROS
*/
# define INVALID_FILE -1
# define SUCCESS 1
# define END_OF_FILE 0

/*
**	Structs
*/
typedef	struct		s_coords
{
	int				row;
	int				col;
}					t_coords;

typedef	struct		s_piece
{
	char			*buff[4];
	char			name;
	struct s_coords	x_locs[4];
	struct s_piece	*next;
}					t_piece;
