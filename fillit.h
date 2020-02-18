/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:46:10 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/18 13:17:11 by wjohanso         ###   ########.fr       */
/*   Updated: 2020/02/07 13:53:00 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdio.h> // REMOVE THIS FOR DEBUGGING 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
/*
# define I_BLOCK (int[8]) {0, 0, 0, 1, 0, 2, 0, 3}
# define IR_BLOCK (int[8]) {0, 0, 1, 0, 2, 0, 3, 0}
# define O_BLOCK (int[8]) {0, 0, 1, 0, 0, 1, 1, 1}
# define T_BLOCK (int[8]) {1, 0, 0, 1, 1, 1, 2, 1}
# define TR_BLOCK (int[8]) {0, 0, 0, 1, 1, 1, 0, 2}
# define TD_BLOCK (int[8]) {0, 0, 1, 0, 2, 0, 1, 1}
# define TL_BLOCK (int[8]) {1, 0, 0, 1, 1, 1, 1, 2}
# define L_BLOCK (int[8]) {0, 0, 0, 1, 0, 2, 1, 2}
# define LR_BLOCK (int[8]) {0, 0, 1, 0, 2, 0, 0, 1}
# define LD_BLOCK (int[8]) {0, 0, 1, 0, 1, 1, 1, 2}
# define LL_BLOCK (int[8]) {2, 0, 0, 1, 1, 1, 2, 1}
# define J_BLOCK (int[8]) {1, 0, 1, 1, 1, 2, 0, 2}
# define JR_BLOCK (int[8]) {0, 0, 0, 1, 1, 1, 2, 1}
# define JD_BLOCK (int[8]) {0, 0, 1, 0, 0, 1, 0, 2}
# define JL_BLOCK (int[8]) {0, 0, 1, 0, 0, 1, 0, 2}
# define Z_BLOCK (int[8]) {0, 0, 1, 0, 1, 1, 2, 1}
# define ZR_BLOCK (int[8]) {1, 0, 0, 1, 1, 1, 0, 2}
*/
# define INVALID_FILE -1
# define SUCCESS 1
# define END_OF_FILE 0
# define MAXIMUM_LINES 129
# define LR_SHIFT 1
# define UD_SHIFT 4
# define END_INDEX 15
# define BEG_INDEX 0
# define GRID_LENGTH 4
typedef struct	s_blocks
{
	//void			*block_id;
	char			letter;
//	int				loc[4][2];
	int				x_loc[GRID_LENGTH];
	int				y_loc[GRID_LENGTH];
	int				delta[2];
	struct s_blocks *next;
}				t_blocks;
/*
typedef struct	s_map
{
	char			**map;
}				t_map;
*/
typedef struct	s_inputmap
{
	char			str[END_INDEX];
}				t_inputmap;
/*
typedef struct	s_text
{
	char			*str;
	struct s_text	*next;
}				t_text;

typedef	struct		s_coords
{
	int				row;
	int				col;
}					t_coords;

typedef	struct		s_piece
{
	char			*buff[4]; char			name;
	struct s_coords	x_locs[4];
	struct s_piece	*next;
}					t_piece;
*/
int			valid_tetris(int fd);
void		input_map_store(char **line, int line_num, t_inputmap
			*input);
int			adjacency_counter(char *str);
void		t_blocks_init(t_blocks *blocks);
void		t_blocks_store(t_inputmap input, t_blocks *blocks);
#endif
