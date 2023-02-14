/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:57:15 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/14 17:07:22 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	buf[BUFFER_SIZE];
	int			i;

	tmp = NULL;
	i = ft_check_end_line(buf, &tmp);
	if (i)
		return (tmp);
	else if (i == -1)
		return (NULL);
	while (!i)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		i = read(fd, buf, BUFFER_SIZE);
		if (i == 0)
			return (tmp);
		else if (i == -1)
			return (free(tmp), tmp = NULL, NULL);
		i = ft_check_end_line(buf, &tmp);
		if (i == -1)
			return (free(tmp), tmp = NULL, NULL);
	}
	return (tmp);
}
