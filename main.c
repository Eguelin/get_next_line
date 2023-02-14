/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:14:14 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/14 16:40:03 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("bible.txt", O_RDONLY);
	line = "";
	i = 1;
	while (line)
	{
		line = get_next_line(fd);
		printf("l%d. %s", i, line);
		free (line);
		i++;
	}
	close(fd);
	return (0);
}
