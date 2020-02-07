/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 10:50:59 by wjohanso          #+#    #+#             */
/*   Updated: 2019/12/25 11:32:11 by wjohanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int		index;

	index = 0;
	if (src[index] == '\0')
	{
		dst[index] = src[index];
	}
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
		if (src[index] == '\0')
		{
			dst[index] = src[index];
			break ;
		}
	}
	return (dst);
}
