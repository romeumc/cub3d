/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:50:01 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/07 14:22:06 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_circle(t_game *game, t_player *shape, int center)
{
	double	angle;
	double	x1;
	double	y1;
	int		radius;

	if (center == 1)
	{
		shape->pos_x += (game->map.tile_size / 2);
		shape->pos_y += (game->map.tile_size / 2);
	}
	radius = game->map.tile_size / PLAYER_SIZE;
	while (radius > 0)
	{
		angle = 0;
		while (angle <= 360)
		{
			x1 = sin(deg_to_rad(angle)) * radius + shape->pos_x;
			y1 = cos(deg_to_rad(angle)) * radius + shape->pos_y;
			my_mlx_pixelput(game, x1 + MINI_MAP_OFFSET,
				y1 + MINI_MAP_OFFSET, create_trgb(shape->color));
			angle++;
		}
		radius--;
	}
}

void	draw_s_rectangle(t_game *game, int x, int y, int color)
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
			my_mlx_pixelput(game, x + i, y + j, color);
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
			my_mlx_pixelput(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// void	draw_line2(t_player *player, t_img *img, double end_x, double end_y)
// {
// 	double	delta_x;
// 	double	delta_y;
// 	int		pixels;
// 	double	pixel_x;
// 	double	pixel_y;

// 	end_x = end_x < 0 ? 0: end_x;
// 	end_x = end_x > (1500) ? 1500 : end_x;
// 	end_y = end_y < 0 ? 0: end_y;
// 	end_y = end_y > (1000) ? 1000 : end_y;
// 	delta_x = end_x - player->pos_x;
// 	delta_y = end_y - player->pos_y;
// 	pixels = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
// 	delta_x /= pixels;
// 	delta_y /= pixels;
// 	pixel_x = player->pos_x;
// 	pixel_y = player->pos_y;
// 	while (pixels)
// 	{
// 		my_mlx_pixelput(img, pixel_x, pixel_y, 0x0000FF);
// 		pixel_x += delta_x;
// 		pixel_y += delta_y;
// 		pixels--;
// 	}
// }

// //Draw the line by DDA algorithm
// void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
// {
// 	double	deltaX;
// 	double	deltaY;
// 	double	step;

// 	deltaX = x2 - x1;
// 	deltaY = y2 - y1;
// 	if (fabs(deltaX) > fabs(deltaY))
// 		step = fabs(deltaX);
// 	else
// 		step = fabs(deltaY);
// 	deltaX /= step;
// 	deltaY /= step;
// 	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
// 	{
// 		my_mlx_pixelput(&game->img, x1, y1, 0xb3b3b3);
// 		x1 += deltaX;
// 		y1 += deltaY;
// 	}
// }
