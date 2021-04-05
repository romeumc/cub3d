/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:32:44 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/05 12:46:39 by rmartins         ###   ########.fr       */
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

t_texture	get_texture_of_wall(t_game *game, t_ray *ray)
{
	if (ray->intersection == 'H')
	{
		if (get_orientation_wall('H', ray->angle) == 'N')
			return (game->t_no);
		else if (get_orientation_wall('H', ray->angle) == 'S')
			return (game->t_so);
	}
	else if (ray->intersection == 'V')
	{
		if (get_orientation_wall('V', ray->angle) == 'W')
			return (game->t_we);
		else if (get_orientation_wall('V', ray->angle) == 'E')
			return (game->t_ea);
	}
	return (game->t_no);
}

int	get_color_tex (t_texture *texture, t_ray *ray)
{
	int	color;
	// int	offset;
	// int	a;
	// int	r;
	// int	g;
	// int	b;

	// offset = (int)ray->y_tex * texture->timg.line_lenght + ray->x_tex
	// 	* (texture->timg.bits_per_pixel / 8);
	// a = texture->timg.addr[offset + 0];
	// r = texture->timg.addr[offset + 1];
	// g = texture->timg.addr[offset + 2];
	// b = texture->timg.addr[offset + 3];
	// return (b << 24 | g << 16 | r << 8 | a);
	color = texture->timg.addr[ray->y_tex * texture->height + ray->x_tex];
	return (color);
}

// int	get_bitmap_offset(t_ray *ray, int bitmap_width)
// {
// 	double	remainder;
// 	int		offset;

// 	if (ray->intersection == 'H')
// 	{
// 		remainder = (ray->grid_hit_h / 64) - floor(ray->grid_hit_h / 64);
// 		offset = bitmap_width * remainder;
// 	}
// 	else
// 	{
// 		remainder = (ray->grid_hit_v / 64) - floor(ray->grid_hit_v / 64);
// 		offset = bitmap_width * remainder;
// 	}
// 	return (offset);
// }

void	draw_wall_stripe(t_game *game, t_ray *ray)
{
	int	y;

	ray->pos_y = (game->resolution.y - ray->height) / 2;
	if (ray->intersection == 'H')
	{
		ray->x_tex = (ray->grid_hit_h) % (ray->tex.width * 1);
	}
	else if (ray->intersection == 'V')
	{
		ray->x_tex = (ray->grid_hit_v) % (ray->tex.width * 1);
	}
	//ray->x_tex = get_bitmap_offset(ray, ray->tex.width);
	//ray->x_tex = ray->pos_x % ray->tex.width;
	y = 0;
	while (y < ray->height)
	{
		ray->y_tex = 1.0 * ray->tex_step * y;
		my_mlx_pixelput(game, ray->pos_x, ray->pos_y + y,
			get_color_tex(&ray->tex, ray));
		y++;
	}
}

void	draw_wall(t_game *game)
{
	double	fisheye;
	int		pixel;
	t_ray	ray;

	pixel = 0;
	ray.angle = fix_ang(game->player.angle - FIELD_OF_VIEW / 2);
	while (pixel < game->resolution.x)
	{
		fisheye = cos(deg_to_rad(fix_ang(game->player.angle - ray.angle)));
		ray.distance = cast_ray(game, ray.angle, &ray);
		ray.height = SCALE * game->resolution.x / (ray.distance * fisheye);
		ray.tex = get_texture_of_wall(game, &ray);
		ray.tex_step = 1.0 * ray.tex.height / ray.height;
		ray.tex_offset = 0;
		if (ray.height > game->resolution.y)
		{
			ray.tex_offset = (ray.height - game->resolution.y) / 2.0;
			ray.height = game->resolution.y;
		}
		ray.pos_x = pixel;
		draw_wall_stripe(game, &ray);
		ray.angle = fix_ang(ray.angle + FIELD_OF_VIEW * 1.0
				/ game->resolution.x);
		pixel++;
	}
}
