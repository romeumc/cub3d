/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:27:21 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/07 16:10:06 by rmartins         ###   ########.fr       */
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
		my_mlx_pixelput(game, (int)pixel_x + MINI_MAP_OFFSET,
			(int)pixel_y + MINI_MAP_OFFSET, 0xFF0000);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	draw_rays2d(t_game *game)
{
	int		rays;
	double	ray_angle;
	double	distance;
	t_ray	ray;

	ray_angle = fix_ang(game->player.angle - game->map.fov / 2);
	rays = game->map.fov;
	while (rays > 0)
	{
		distance = cast_ray(game, ray_angle, &ray);
		draw_ray(game, &game->player, distance, ray_angle);
		ray_angle++;
		ray_angle = fix_ang(ray_angle);
		rays--;
	}
}

double	cast_ray(t_game *game, double ray_angle, t_ray *ray)
{
	double	v_distance;
	double	h_distance;

	ray->angle = ray_angle;
	v_distance = get_ray_distance_v(game, &game->player, ray);
	h_distance = get_ray_distance_h(game, &game->player, ray);
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
