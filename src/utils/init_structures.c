/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:36:43 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 09:48:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	init_texture(t_texture *texture)
{
	texture->path = ft_strdup("");
	texture->valid = 0;
}

static void	init_color(t_color *color)
{
	color->valid = 0;
}

static void	init_resolution(t_resolution *resolution)
{
	resolution->x = 0;
	resolution->y = 0;
	resolution->valid = 0;
}

static void	init_map(t_map *map)
{
	map->lines = 0;
	map->cols = 0;
	map->valid = 0;
	map->grid = malloc(sizeof(char *) * 200);
	if (map->grid == NULL)
		exit (0);
}

void	init_structures(t_game *game)
{
	game->player.valid = 0;
	init_resolution(&game->resolution);
	init_texture(&game->t_no);
	init_texture(&game->t_so);
	init_texture(&game->t_we);
	init_texture(&game->t_ea);
	init_texture(&game->t_sprite);
	init_color(&game->floor);
	init_color(&game->ceilling);
	init_map(&game->map);
	game->other_error = 0;
}
