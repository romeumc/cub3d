/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:00:49 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/12 14:54:39 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	my_mlx_pixelput(t_game *game, int x, int y, int color)
{
	game->img.addr[(int)y * (int)game->resolution.x + (int)x] = color;
}

void	set_tile_size(t_game *game, int percentage)
{
	int	tile_x;
	int	tile_y;

	tile_x = game->resolution.x / game->map.cols;
	tile_y = game->resolution.y / game->map.rows;
	if (tile_x > tile_y)
		game->map.tile_size = tile_y * percentage / 100;
	else
		game->map.tile_size = tile_x * percentage / 100;
}

int	create_trgb(t_color color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = color.transparency;
	r = color.red;
	g = color.green;
	b = color.blue;
	return (t << 24 | r << 16 | g << 8 | b);
}

t_color	set_trgb(int temp_color)
{
	t_color	color;

	color.transparency = (temp_color >> 24) & 0xFF;
	color.red = (temp_color >> 16) & 0xFF;
	color.green = (temp_color >> 8) & 0xFF;
	color.blue = temp_color & 0xFF;
	return (color);
}

void	check_max_resolution(t_game *game)
{
	if (game->resolution.x > 1920)
		game->resolution.x = 1920;
	if (game->resolution.y > 1080)
		game->resolution.y = 1080;
}
