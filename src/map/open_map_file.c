/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:49:07 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 01:23:51 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

static void	debug___________________________game(t_game *game)
{
	printf("res_X:%d - res_Y:%d\n", game->resolution_x, game->resolution_y);
	printf("texture_no:[%s]\n", game->texture_no);
	printf("texture_so:[%s]\n", game->texture_so);
	printf("texture_we:[%s]\n", game->texture_we);
	printf("texture_ea:[%s]\n", game->texture_ea);
	printf("texture_sprite:[%s]\n", game->texture_sprite);
	printf("floor:[%d][%d][%d]\n", game->floor.red,
		game->floor.green, game->floor.blue);
	printf("ceilling:[%d][%d][%d]\n", game->ceilling.red,
		game->ceilling.green, game->ceilling.blue);
	printf("invalid map resolution: %d\n", game->invalid_map_resolution);
	printf("invalid map texture_no: %d\n", game->invalid_map_texture_no);
	printf("invalid map texture_so: %d\n", game->invalid_map_texture_so);
	printf("invalid map texture_we: %d\n", game->invalid_map_texture_we);
	printf("invalid map texture_ea: %d\n", game->invalid_map_texture_ea);
	printf("invalid map texture_sprite: %d\n", game->invalid_map_texture_sprite);
	printf("invalid map floor: %d\n", game->invalid_map_floor);
	printf("invalid map ceilling: %d\n", game->invalid_map_ceilling);
}

int	open_map_file(char *filename, t_game *game)
{
	int		fd;
	int		j;
	char	*line;

	line = 0;
	j = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("\nError in open - %s\n", strerror(errno));
		exit (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		parse_map(line, game);
		free(line);
		j++;
	}
	debug___________________________game(game);
	free(line);
	close(fd);
	return (0);
}
