/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:36:43 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 22:53:03 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	init_texture(t_texture *texture)
{
	texture->path = ft_strdup("");
	texture->valid = -1;
}

static void	init_color(t_color *color)
{
	color->red = -1;
	color->green = -1;
	color->blue = -1;
	color->valid = -1;
}

static void	init_resolution(t_resolution *resolution)
{
	resolution->x = 0;
	resolution->y = 0;
	resolution->valid = -1;
}

void	init_structures(t_game *game)
{
	game->player = '0';
	init_resolution(&game->resolution);
	init_texture(&game->t_no);
	init_texture(&game->t_so);
	init_texture(&game->t_we);
	init_texture(&game->t_ea);
	init_texture(&game->t_sprite);
	init_color(&game->floor);
	init_color(&game->ceilling);
	game->valid_map = -1;
	game->other_error = 0;
}
