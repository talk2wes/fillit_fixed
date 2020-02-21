/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:46:10 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/21 12:28:08 by wjohanso         ###   ########.fr       */
/*   Updated: 2020/02/07 13:53:00 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//update header file 2/20 300pm 
#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdio.h> // REMOVE THIS FOR DEBUGGING 
# include <string.h> // REMOVE THIS FOR DEBUGGING 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define INVALID_FILE -1
# define SUCCESS 1
# define END_OF_FILE 0
# define MAXIMUM_LINES 129
# define LR_SHIFT 1
# define UD_SHIFT 4
# define END_INDEX 15
# define BEG_INDEX 0
# define GRID_LENGTH 4

typedef	struct		s_coords
{
	int				row;
	int				col;
}					t_coords;

typedef struct	s_blocks
{
	char			letter;
	int				x_loc[GRID_LENGTH];
	int				y_loc[GRID_LENGTH];
	int				delta[2];
	struct s_blocks *next;
}				t_blocks;
typedef struct	s_inputmap
{
	char			str[END_INDEX + 2];
}				t_inputmap;
int			valid_tetris(int fd, t_blocks *blocks);
void		input_map_store(char **line, int line_num, t_inputmap
			*input);
int			adjacency_counter(char *str);
void		t_blocks_init(t_blocks *blocks);
void		t_blocks_store(t_inputmap input, t_blocks *blocks);
void		inputmap_reset(t_inputmap *input);
t_blocks	*t_blocks_newnode();
void		t_blocks_print_data(t_blocks *blocks);
void		align(t_blocks *blocks);
void		align_blocks(t_blocks *blocks);
//void		smallest_xy_tetris(t_blocks *piece, int x, int y);
void		t_blocks_change_delta(t_blocks *blocks, int i, int y);
int			**t_blocks_poistion(t_blocks *blocks);
#endif
