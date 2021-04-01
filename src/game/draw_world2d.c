/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:48:59 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/01 20:24:08 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

// void 	draw_lines(t_game *game, int cols, int rows, int tile_size)
// {
// 	int		i;
// 	int		j;
// 	int		height;
// 	int		width;

// 	height = rows * tile_size;
// 	width = cols * tile_size;
// 	i = 0;
// 	while (i < cols)
// 	{
// 		draw_line(game, i * tile_size, 0, i * tile_size, height);
// 		i++;
// 	}
// 	draw_line(game, cols * tile_size - 1, 0, cols * tile_size - 1, height);
// 	j = 0;
// 	while (j < rows)
// 	{
// 		draw_line(game, 0, j * tile_size, width, j * tile_size);
// 		j++;
// 	}
// 	draw_line(game, 0, rows * tile_size - 1, width, rows * tile_size - 1);
// }

void	draw_world2d(t_game *game, int tile_size)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.grid[i][j] == '1')
				draw_rectangle(game, tile_size * j, tile_size * i, 0x22FFFF);
			else if (game->map.grid[i][j] == '2')
			{
				draw_rectangle(game, tile_size * j, tile_size * i, 0xFFFFFF);
				draw_s_rectangle(game, tile_size * j, tile_size * i, 0xFF22FF);
			}
			else if (game->map.grid[i][j] != ' ')
				draw_rectangle(game, tile_size * j, tile_size * i, 0xFFFFFF);
			j++;
		}
		i++;
	}
	//draw_lines(game, game->map.cols, game->map.rows, tile_size);
}
