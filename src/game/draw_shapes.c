/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:50:01 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/23 13:11:27 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

void	draw_circle(t_game *game, t_img *img, t_shape *shape)
{
	double	angle;
	double	x1;
	double	y1;
	int		radius;

	shape->pos_x += (game->map.tile_size / 2);
	shape->pos_y += (game->map.tile_size / 2);
	radius = game->map.tile_size / 6;
	while (radius > 0)
	{
		angle = 0;
		while (angle <= 360)
		{
			x1 = sin(deg_to_rad(angle)) * radius + shape->pos_x;
			y1 = cos(deg_to_rad(angle)) * radius + shape->pos_y;
			my_mlx_pixelput(img, x1, y1, shape->color);
			angle++;
		}
		radius--;
	}
}

void	draw_small_rectangle(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	x += (game->map.tile_size / 4);
	y += (game->map.tile_size / 4);

	i = 0;
	while (i < game->map.tile_size / 2)
	{
		j = 0;
		while (j < game->map.tile_size / 2)
		{
			my_mlx_pixelput(&game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_rectangle(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.tile_size)
	{
		j = 0;
		while (j < game->map.tile_size)
		{
			my_mlx_pixelput(&game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// //Draw the line by DDA algorithm
void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		my_mlx_pixelput(&game->img, x1, y1, 0xb3b3b3);
		x1 += deltaX;
		y1 += deltaY;
	}
}