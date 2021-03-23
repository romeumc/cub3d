/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:48:59 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/23 13:14:44 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void 	draw_lines(t_game *game, int cols, int rows)
{
	int		i;
	int		j;
	int		height;
	int		width;

	height = rows * game->map.tile_size;
	width = cols * game->map.tile_size;
	i = 0;
	while (i < cols)
	{
		draw_line(game, i * game->map.tile_size, 0, i * game->map.tile_size, height);
		i++;
	}
	draw_line(game, cols * game->map.tile_size - 1, 0, cols * game->map.tile_size - 1, height);
	j = 0;
	while (j < rows)
	{
		draw_line(game, 0, j * game->map.tile_size, width, j * game->map.tile_size);
		j++;
	}
	draw_line(game, 0, rows * game->map.tile_size - 1, width, rows * game->map.tile_size - 1);
}

void	draw_world2d(t_game *game)
{
	int		i;
	int		j;
	int		color;
	t_shape	player;
	
	color = 0x22FFFF;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.grid[i][j] == '1')
				draw_rectangle(game, game->map.tile_size * j, game->map.tile_size * i, color);
			else if (game->map.grid[i][j] == '2')
				draw_small_rectangle(game, game->map.tile_size * j, game->map.tile_size * i, 0xFF22FF);
			else if (ft_strchr("NSWE", game->map.grid[i][j]))
			{
				player.color = 0xFF2222;
				player.pos_x = game->map.tile_size * j;
				player.pos_y = game->map.tile_size * i;
				draw_circle(game, &game->img, &player);
			}
			j++;
		}
		i++;
	}
	draw_lines(game, game->map.cols, game->map.rows);
}
