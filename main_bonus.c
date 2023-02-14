/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:14:14 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/14 16:40:17 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		i;
	char	*line;
	char	*line2;

	fd = open("bible.txt", O_RDONLY);
	fd2 = open("bible.txt", O_RDONLY);
	line = "";
	i = 1;
	while (line || line2)
	{
		line = get_next_line(fd);
		printf("l%d. %s", i, line);
		free (line);
		line2 = get_next_line(fd2);
		printf("l%d. %s", i, line2);
		free (line2);
		i++;
	}
	close(fd);
	close(fd2);
	return (0);
}
