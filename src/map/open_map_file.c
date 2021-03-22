/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:49:07 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 01:09:43 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	open_map_file(char *filename, t_game *game)
{
	int		fd;
	int		j;
	char	*line;
	int		result;

	line = 0;
	result = EXIT_SUCCESS;
	j = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno), "");
		exit (0);
	}
	while (get_next_line(fd, &line) > 0 && result == EXIT_SUCCESS)
	{
		result = parse_map(line, game);
		free(line);
		j++;
	}
	if (result == EXIT_SUCCESS)
		free(line);
	close(fd);
}
