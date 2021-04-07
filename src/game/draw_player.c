/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:35:46 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/07 15:28:43 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	setup_initial_player(t_game *game, int i, int j)
{
	game->player.valid = 2;
	game->player.color = set_trgb(0xFF2222);
	game->player.pos_x = game->map.tile_size * j;
	game->player.pos_y = game->map.tile_size * i;
	draw_circle(game, &game->player, 1);
	game->player.angle = get_start_direction(game->player.direction);
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
					setup_initial_player(game, i, j);
				j++;
			}
			i++;
		}
	}
	else if (game->player.valid == 2)
	{
		draw_circle(game, &game->player, 0);
		game->player.delta_x = cos(deg_to_rad(game->player.angle));
		game->player.delta_y = sin(deg_to_rad(game->player.angle));
	}
}
