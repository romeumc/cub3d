/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:32:44 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/30 02:13:55 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	get_orientation_wall(char intersection, double angle)
{
	if (intersection == 'V')
	{
		if (angle > 90 && angle < 270)
			return ('W');
		else if (angle > 270 || angle < 90)
			return ('E');
	}
	else if (intersection == 'H')
	{
		if (angle > 180 && angle < 360)
			return ('N');
		else if (angle > 0 && angle < 180)
			return ('S');
	}
	return (0);
}

void	draw_wall_ray(t_img img, t_ray ray, double ray_angle)
{
	int	y;

	//int	color;
	//color = create_trgb(ray.color);
	y = 0;
	while (y < ray.height)
	{
		if (ray.intersection == 'H')
		{
			if (get_orientation_wall('H', ray_angle) == 'N')
				my_mlx_pixelput(&img, ray.pos_x, ray.pos_y + y, 0x68FF86);
			else if (get_orientation_wall('H', ray_angle) == 'S')
				my_mlx_pixelput(&img, ray.pos_x, ray.pos_y + y, 0x541386);
		}
		else if (ray.intersection == 'V')
		{
			if (get_orientation_wall('V', ray_angle) == 'W')
				my_mlx_pixelput(&img, ray.pos_x, ray.pos_y + y, 0x157913);
			else if (get_orientation_wall('V', ray_angle) == 'E')
				my_mlx_pixelput(&img, ray.pos_x, ray.pos_y + y, 0x247854);
		}
		y++;
	}
}

void	draw_wall(t_game *game)
{
	double	fisheye;
	double	distance;
	double	ray_ang;
	int		pixel;
	t_ray	ray;

	pixel = 0;
	ray_ang = fix_ang(game->player.angle - FIELD_OF_VIEW / 2);
	while (pixel < game->resolution.x)
	{
		fisheye = cos(deg_to_rad(fix_ang(game->player.angle - ray_ang)));
		distance = cast_ray(game, ray_ang, &ray);
		ray.height = SCALE * game->resolution.x / (distance * fisheye);
		if (ray.height > game->resolution.y)
			ray.height = game->resolution.y;
		ray.pos_x = pixel;
		ray.pos_y = (game->resolution.y - ray.height) / 2;
		draw_wall_ray(game->img, ray, ray_ang);
		ray_ang = fix_ang(ray_ang + FIELD_OF_VIEW * 1.0 / game->resolution.x);
		pixel++;
	}
}
