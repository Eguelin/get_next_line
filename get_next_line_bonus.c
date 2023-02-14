/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:57:15 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/14 17:08:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	buf[FOPEN_MAX][BUFFER_SIZE];
	int			i;

	if (fd < 0)
		return (NULL);
	tmp = NULL;
	i = ft_check_end_line(buf[fd], &tmp);
	if (i)
		return (tmp);
	else if (i == -1)
		return (NULL);
	while (!i)
	{
		ft_memset(buf[fd], 0, BUFFER_SIZE);
		i = read(fd, buf[fd], BUFFER_SIZE);
		if (i == 0)
			return (tmp);
		else if (i == -1)
			return (free(tmp), tmp = NULL, NULL);
		i = ft_check_end_line(buf[fd], &tmp);
		if (i == -1)
			return (free(tmp), tmp = NULL, NULL);
	}
	return (tmp);
}
