/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 08:38:21 by wjohanso          #+#    #+#             */
/*   Updated: 2020/01/26 18:01:31 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		buf_to_str(const int fd, char **s)
{
	int		bytes;
	char	*buf;
	char	*temp;

	buf = ft_strnew(BUFF_SIZE);
	bytes = read(fd, buf, BUFF_SIZE);
	if (bytes < 0)
		return (-1);
	if (bytes > 0 && fd >= 0)
	{
		temp = ft_strjoin(*s, buf);
		if (temp == NULL)
			return (-1);
		ft_strdel(s);
		*s = ft_strnew(ft_strlen(temp));
		ft_strcpy(*s, temp);
		ft_strdel(&temp);
	}
	ft_strdel(&buf);
	return (bytes);
}

static void		mv_line(char **line, char **s)
{
	char	*ptr;
	char	*temp;
	int		p_len;
	int		s_len;

	if ((ptr = ft_strchr(*s, '\n')) == NULL)
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	else
	{
		s_len = ft_strlen(*s);
		p_len = s_len - ft_strlen(ptr);
		*line = ft_strnew(p_len);
		*line = ft_strncpy(*line, *s, p_len);
		temp = ft_strnew(ft_strlen(++ptr));
		temp = ft_strcpy(temp, ptr);
		ft_strdel(s);
		*s = ft_strdup(temp);
		ft_strdel(&temp);
	}
}

int				get_next_line(const int fd, char **line)
{
	int				bytes;
	int				eof;
	static char		*s[MAX_FD];

	if (line && fd >= 0 && fd < MAX_FD && BUFF_SIZE > 0)
	{
		while (1)
		{
			s[fd] = (s[fd] == NULL) ? ft_strnew(1) : s[fd];
			bytes = buf_to_str(fd, &s[fd]);
			if (bytes == -1)
				return (-1);
			eof = (bytes < BUFF_SIZE) ? 1 : 0;
			if (ft_strchr(s[fd], '\n') != NULL || eof == 1)
				break ;
		}
		mv_line(line, &s[fd]);
		if (eof == 1 && s[fd] == NULL && ft_strcmp(*line, "") == 0)
			return (0);
		else
			return (1);
	}
	return (-1);
}
