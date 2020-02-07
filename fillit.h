/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:46:10 by wjohanso          #+#    #+#             */
/*   Updated: 2020/02/07 10:33:59 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
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

typedef struct	s_blocks
{
	void			*block_id;
	char			c;
	struct s_blocks *next;
}				t_blocks;

typedef struct	s_text
{
	char			*str;
	struct s_text	*next;
}

#endif
