/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal_interception.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:30:33 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/27 19:25:50 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

double	get_ray_distance_hn(t_game *game, t_player *player, double angle)
{
	double	ray_x;
	double	ray_y;
	double	step_x;
	double	step_y;

	ray_y = floor(player->pos_y / game->map.tile_size) * game->map.tile_size;
	step_y = ray_y - player->pos_y;
	step_x = step_y / tan(deg_to_rad(angle));
	ray_x = player->pos_x + step_x;
	if (is_wall(&game->map, ray_x, ray_y - 1) == 1)
		return (pythagorean(player->pos_x - ray_x, player->pos_y - ray_y));
	step_y = -game->map.tile_size;
	step_x = step_y / tan(deg_to_rad(angle));
	while (is_wall(&game->map, ray_x, ray_y - 1) == 0)
	{
		ray_x += step_x;
		ray_y += step_y;
	}
	return (pythagorean(player->pos_x - ray_x, player->pos_y - ray_y));
}

double	get_ray_distance_hs(t_game *game, t_player *player, double angle)
{
	double	ray_x;
	double	ray_y;
	double	step_x;
	double	step_y;

	ray_y = ceil(player->pos_y / game->map.tile_size) * game->map.tile_size;
	step_y = ray_y - player->pos_y;
	step_x = step_y / tan(deg_to_rad(angle));
	ray_x = player->pos_x + step_x;
	if (is_wall(&game->map, ray_x, ray_y + 1) == 1)
		return (pythagorean(player->pos_x - ray_x, player->pos_y - ray_y));
	step_y = game->map.tile_size;
	step_x = step_y / tan(deg_to_rad(angle));
	while (is_wall(&game->map, ray_x, ray_y + 1) == 0)
	{
		ray_x += step_x;
		ray_y += step_y;
	}
	return (pythagorean(player->pos_x - ray_x, player->pos_y - ray_y));
}

double	get_ray_distance_h(t_game *game, t_player *player, double angle)
{
	double	distance;

	if (angle > 180 && angle < 360)
	{
		distance = get_ray_distance_hn(game, player, angle);
		return (distance);
	}
	else if (angle > 0 && angle < 180)
	{
		distance = get_ray_distance_hs(game, player, angle);
		return (distance);
	}
	else
		return (__INT_MAX__);
}
