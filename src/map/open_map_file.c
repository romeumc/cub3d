/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:49:07 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 22:27:33 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	open_map_file(char *filename, t_game *game)
{
	int		fd;
	int		j;
	char	*line;
	int		result;

	line = 0;
	result = 0;
	j = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno), "");
		exit (0);
	}
	while (get_next_line(fd, &line) > 0 && result == 0)
	{
		result = parse_map(line, game);
		free(line);
		j++;
	}
	free(line);
	close(fd);
	check_map_errors(game);
	return (0);
}
