/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:35:46 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/30 01:52:16 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_ray(t_game *game, t_player *line, double distance, double angle)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = cos(deg_to_rad(angle)) * distance;
	delta_y = sin(deg_to_rad(angle)) * distance;
	pixels = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = line->pos_x;
	pixel_y = line->pos_y;
	while (pixels)
	{
		my_mlx_pixelput(&game->img, (int)pixel_x, (int)pixel_y, 0xFF0000);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	setup_initial_player(t_game *game, int i, int j)
{
	game->player.valid = 2;
	game->player.color = set_trgb(0xFF2222);
	game->player.pos_x = game->map.tile_size * j;
	game->player.pos_y = game->map.tile_size * i;
	draw_circle(game, &game->img, &game->player, 1);
	game->player.angle = get_start_direction(game->player.direction);
}

void	draw_player2d(t_game *game)
{
	int		i;
	int		j;

	if (game->player.valid == 1)
	{
		i = 0;
		while (i < game->map.rows)
		{
			j = 0;
			while (j < game->map.cols)
			{
				if (ft_strchr("NSWE", game->map.grid[i][j]))
					setup_initial_player(game, i, j);
				j++;
			}
			i++;
		}
	}
	else if (game->player.valid == 2)
	{
		draw_circle(game, &game->img, &game->player, 0);
		game->player.delta_x = cos(deg_to_rad(game->player.angle));
		game->player.delta_y = sin(deg_to_rad(game->player.angle));
		//draw_ray(game, &game->player, 10, game->player.angle);
	}
}

double	cast_ray(t_game *game, double ray_angle, t_ray *ray)
{
	double	v_distance;
	double	h_distance;

	v_distance = get_ray_distance_v(game, &game->player, ray_angle);
	h_distance = get_ray_distance_h(game, &game->player, ray_angle);
	if (v_distance > h_distance)
	{
		ray->intersection = 'H';
		ray->distance = h_distance;
	}
	else
	{
		ray->intersection = 'V';
		ray->distance = v_distance;
	}
	return (ray->distance);
}

void	draw_rays2d(t_game *game)
{
	int		rays;
	double	ray_angle;
	double	distance;
	t_ray	ray;

	ray_angle = fix_ang(game->player.angle - FIELD_OF_VIEW / 2);
	rays = FIELD_OF_VIEW;
	while (rays > 0)
	{
		distance = cast_ray(game, ray_angle, &ray);
		draw_ray(game, &game->player, distance, ray_angle);
		ray_angle++;
		ray_angle = fix_ang(ray_angle);
		rays--;
	}
}
