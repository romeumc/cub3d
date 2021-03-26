/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:35:46 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/26 23:12:43 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_ray(t_game *game, t_player *line, int distance, int angle)
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
				{
					game->player.valid = 2;
					game->player.color = set_trgb(0xFF2222);
					game->player.pos_x = game->map.tile_size * j;
					game->player.pos_y = game->map.tile_size * i;
					draw_circle(game, &game->img, &game->player, 1);
					game->player.angle = get_start_direction(game->player.direction);
				}
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
		draw_ray(game, &game->player, 10, game->player.angle);
	}
}


void	draw_line2(t_player *player, t_img *img, double end_x, double end_y)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	end_x = end_x < 0 ? 0: end_x;
	end_x = end_x > (1500) ? 1500 : end_x;
	end_y = end_y < 0 ? 0: end_y;
	end_y = end_y > (1000) ? 1000 : end_y;
	
	delta_x = end_x - player->pos_x;
	delta_y = end_y - player->pos_y;
	pixels = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = player->pos_x;
	pixel_y = player->pos_y;
	while (pixels)
	{
		my_mlx_pixelput(img, pixel_x, pixel_y, 0x0000FF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}


double	get_ray_distance_v1(t_game *game, t_player *player, double angle)
{
	double	ray_x;
	double	ray_y;
	//int	grid_y;
	//int		next_vertical;
	double	step_x;
	double	step_y;
	double	distance;
	//check vertical colision
	if (angle > 90 && angle < 270)
	{
		//looking left
		ray_x = floor(player->pos_x / game->map.tile_size) * game->map.tile_size;
		step_x = ray_x - player->pos_x;
		step_y = step_x * tan(deg_to_rad(angle));
		ray_y = player->pos_y + step_y;		

		if (is_wall(&game->map, ray_x - 1, ray_y) == 1)
		{
			distance = sqrt(pow(fabs(player->pos_x - ray_x), 2) + pow(fabs(player->pos_y - ray_y), 2));
			return (distance);
		}
		step_x = -game->map.tile_size;
		step_y = step_x * tan(deg_to_rad(angle));

		while (is_wall(&game->map, ray_x - 1, ray_y) == 0)
		{
			ray_x += step_x;
			ray_y += step_y;
			//draw_line2(&game->player, &game->img, ray_x, ray_y);
		}
	}
	else if (angle > 270 || angle < 90)
	{
		// looking right
		//pixel da proxima intresecao vertical
		ray_x = ceil(player->pos_x / game->map.tile_size) * game->map.tile_size;
		step_x = ray_x - player->pos_x;
		step_y = step_x * tan(deg_to_rad(angle));
		ray_y = player->pos_y + step_y;
		
		if (is_wall(&game->map, ray_x, ray_y) == 1)
		{
			distance = sqrt(pow(fabs(player->pos_x - ray_x), 2) + pow(fabs(player->pos_y - ray_y), 2));
			return (distance);
		}
		step_x = game->map.tile_size;
		step_y = step_x * tan(deg_to_rad(angle));

		while (is_wall(&game->map, ray_x, ray_y) == 0)
		{
			ray_x += step_x;
			ray_y += step_y;
			//draw_line2(&game->player, &game->img, ray_x, ray_y);
		}
	}
	else
		return (__INT_MAX__);
	distance = sqrt(pow(fabs(player->pos_x - ray_x), 2) + pow(fabs(player->pos_y - ray_y), 2));
	return (distance);
}

double	get_ray_distance_h1(t_game *game, t_player *player, double angle)
{
	double	ray_x;
	double	ray_y;
	double	step_x;
	double	step_y;
	double	distance;
	//check horizontal colision
	if (angle > 180 && angle < 360)
	{
		//looking up
		ray_y = floor(player->pos_y / game->map.tile_size) * game->map.tile_size;
		step_y = ray_y - player->pos_y;
		step_x = step_y / tan(deg_to_rad(angle));
		ray_x = player->pos_x + step_x;		

		if (is_wall(&game->map, ray_x, ray_y - 1) == 1)
		{
			distance = sqrt(pow(fabs(player->pos_x - ray_x), 2) + pow(fabs(player->pos_y - ray_y), 2));
			return (distance);
		}
		step_y = -game->map.tile_size;
		step_x = step_y / tan(deg_to_rad(angle));

		while (is_wall(&game->map, ray_x, ray_y - 1) == 0)
		{
			ray_x += step_x;
			ray_y += step_y;
			//draw_line2(&game->player, &game->img, ray_x, ray_y);
		}
	}
	else if (angle > 0 && angle < 180)
	{
		// looking down
		//pixel da proxima intresecao vertical
		ray_y = ceil(player->pos_y / game->map.tile_size) * game->map.tile_size;
		step_y = ray_y - player->pos_y;
		step_x = step_y / tan(deg_to_rad(angle));
		ray_x = player->pos_x + step_x;
		
		if (is_wall(&game->map, ray_x, ray_y) == 1)
		{
			distance = sqrt(pow(fabs(player->pos_x - ray_x), 2) + pow(fabs(player->pos_y - ray_y), 2));
			return (distance);
		}
		step_y = game->map.tile_size;
		step_x = step_y / tan(deg_to_rad(angle));

		while (is_wall(&game->map, ray_x, ray_y) == 0)
		{
			ray_x += step_x;
			ray_y += step_y;
			//draw_line2(&game->player, &game->img, ray_x, ray_y);
		}
	}
	else
		return (__INT_MAX__);
	distance = sqrt(pow(fabs(player->pos_x - ray_x), 2) + pow(fabs(player->pos_y - ray_y), 2));
	return (distance);
}



void	draw_rays2d(t_game *game)
{
	int		rays;
	int	ray_angle;
	double	v_distance;
	double	h_distance;
	double distance;

	// ray_angle = game->player.angle - FIELD_OF_VIEW /2;
	// rays = FIELD_OF_VIEW;
	ray_angle = fix_ang(game->player.angle + 3);
	rays = 10;
	while (rays > 0)
	{
		v_distance = get_ray_distance_v(game, &game->player, ray_angle);
		h_distance = get_ray_distance_h(game, &game->player, ray_angle);

		//printf(ANSI_F_YELLOW "h_ray:%f v_ray:%f\n" ANSI_RESET, h_distance, v_distance);
		distance = v_distance;
		if (v_distance > h_distance)
			distance = h_distance;
		draw_ray(game, &game->player, distance, ray_angle);
		//ray_angle += 0.1;
		fix_ang(++ray_angle);
		rays--;
	}
}
