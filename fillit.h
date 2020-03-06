/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:17:17 by wjohanso          #+#    #+#             */
/*   Updated: 2020/03/06 13:03:48 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
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
# define INITIAL_XY -1
# define INITIAL_LETTER " "
# define INITIAL_DELTA -1
# define INITIAL_POSITION -1

typedef	struct	s_coords
{
	int				row;
	int				col;
}				t_coords;

typedef struct	s_blocks
{
	char			letter;
	int				x_loc[GRID_LENGTH];
	int				y_loc[GRID_LENGTH];
	int				x_position[GRID_LENGTH];
	int				y_position[GRID_LENGTH];
	int				delta[2];
	struct s_blocks *next;
}				t_blocks;

typedef struct	s_inputmap
{
	char		str[END_INDEX + 2];
}				t_inputmap;

int				valid_tetris(int fd, t_blocks *blocks);
void			input_map_store(char **line, int line_num, t_inputmap *input);
int				adjacency_counter(char *str);
void			t_blocks_init(t_blocks *blocks);
void			t_blocks_store(t_inputmap input, t_blocks *blocks);
void			inputmap_reset(t_inputmap *input);
t_blocks		*t_blocks_newnode();
void			t_blocks_print_data(t_blocks *blocks);
void			align(t_blocks *blocks);
void			align_blocks(t_blocks *blocks);
void			smallest_xy_tetris(t_blocks *piece, int x, int y);
void			t_blocks_change_delta(t_blocks *blocks, int i, int y);
int				tetris_count(t_blocks *head);
int				board_size(int tetris_count);
int				find_sqrt(int n);
char			**create_empty_board(int map_size);
void			free_map(char **map, int map_size);
char			**increase_map_size(char **map, int map_size);
char			**remove_tetris(char **map, t_blocks *piece, int map_size);
void			place(char **map, t_blocks *piece, char letter);
char			**backtrack(char **tetris_map, t_blocks *piece, int map_size);
void			solve(t_blocks *piece, char **map, int map_size);
void			print_board(char **map, int b_size);
#endif
