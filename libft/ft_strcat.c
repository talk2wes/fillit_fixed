/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:17:33 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 11:35:44 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	int		s1_ind;
	int		s2_ind;
	int		length;

	s1_ind = 0;
	s2_ind = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	while (s1[s1_ind] != '\0')
	{
		s1_ind++;
	}
	while (s2[s2_ind] != '\0')
	{
		s1[s1_ind] = s2[s2_ind];
		s1_ind++;
		s2_ind++;
	}
	s1[s1_ind] = '\0';
	return (s1);
}
