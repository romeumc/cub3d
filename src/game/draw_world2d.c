/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:48:59 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/07 14:17:18 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_world2d(t_game *game, int tile_size, int i, int j)
{
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.grid[i][j] == '1')
				draw_rectangle(game, tile_size * j + MINI_MAP_OFFSET,
					tile_size * i + MINI_MAP_OFFSET, 0x22FFFF);
			else if (game->map.grid[i][j] == '2')
			{
				draw_rectangle(game, tile_size * j + MINI_MAP_OFFSET,
					tile_size * i + MINI_MAP_OFFSET, 0xFFFFFF);
				draw_s_rectangle(game, tile_size * j + MINI_MAP_OFFSET,
					tile_size * i + MINI_MAP_OFFSET, 0xFF22FF);
			}
			else if (game->map.grid[i][j] != ' ')
				draw_rectangle(game, tile_size * j + MINI_MAP_OFFSET,
					tile_size * i + MINI_MAP_OFFSET, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	draw_world2d(game, game->map.tile_size, 0, 0);
	draw_player2d(game);
	draw_rays2d(game);
}
