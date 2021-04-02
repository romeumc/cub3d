/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical_interception.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:30:33 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/02 22:46:50 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

double	get_ray_distance_vw(t_game *game, t_player *player, t_ray *ray)
{
	double	ray_x;
	double	ray_y;
	double	step_x;
	double	step_y;

	ray_x = floor(player->pos_x / game->map.tile_size) * game->map.tile_size;
	step_x = ray_x - player->pos_x;
	step_y = step_x * tan(deg_to_rad(ray->angle));
	ray_y = player->pos_y + step_y;
	if (is_wall(&game->map, ray_x - 1, ray_y) == 1)
		return (pythagorean(player->pos_x - ray_x, player->pos_y - ray_y));
	step_x = -game->map.tile_size;
	step_y = step_x * tan(deg_to_rad(ray->angle));
	while (is_wall(&game->map, ray_x - 1, ray_y) == 0)
	{
		ray_x += step_x;
		ray_y += step_y;
	}
	ray->grid_hit_v = ray_y;
	return (pythagorean(player->pos_x - ray_x, player->pos_y - ray_y));
}

double	get_ray_distance_ve(t_game *game, t_player *player, t_ray *ray)
{
	double	ray_x;
	double	ray_y;
	double	step_x;
	double	step_y;

	ray_x = ceil(player->pos_x / game->map.tile_size) * game->map.tile_size;
	step_x = ray_x - player->pos_x;
	step_y = step_x * tan(deg_to_rad(ray->angle));
	ray_y = player->pos_y + step_y;
	if (is_wall(&game->map, ray_x + 1, ray_y) == 1)
		return (pythagorean(player->pos_x - ray_x, player->pos_y - ray_y));
	step_x = game->map.tile_size;
	step_y = step_x * tan(deg_to_rad(ray->angle));
	while (is_wall(&game->map, ray_x + 1, ray_y) == 0)
	{
		ray_x += step_x;
		ray_y += step_y;
	}
	ray->grid_hit_v = ray_y;
	return (pythagorean(player->pos_x - ray_x, player->pos_y - ray_y));
}

double	get_ray_distance_v(t_game *game, t_player *player, t_ray *ray)
{
	double	distance;

	if (ray->angle > 90 && ray->angle < 270)
	{
		distance = get_ray_distance_vw(game, player, ray);
		return (distance);
	}
	else if (ray->angle > 270 || ray->angle < 90)
	{
		distance = get_ray_distance_ve(game, player, ray);
		return (distance);
	}
	else
		return (__INT_MAX__);
}
