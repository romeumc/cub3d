/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:51:30 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/24 00:25:23 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	check_collision(t_game *game, int x_new, int y_new, int tile_size, char wall)
{
	int pos_x;
	int pos_y;

	pos_x = x_new / tile_size;
	pos_y = y_new / tile_size;
	printf("new square [%2d][%2d] mod[%d][%d]\n", pos_x, pos_y, x_new%tile_size, y_new%tile_size);
	if (game->map.grid[pos_y][pos_x] != '1')
	{
		if (wall == 'W')
			game->player.pos_x -= PLAYER_STEP;
		else if (wall == 'E')
			game->player.pos_x += PLAYER_STEP;
		else if (wall == 'N')
			game->player.pos_y -= PLAYER_STEP;
		else if (wall == 'S')
			game->player.pos_y += PLAYER_STEP;
	}
	else
		printf("WALL\n");
}

void	check_wall(t_game *game, char wall)
{
	int	margin;
	int	tile_size;
	int	x_new;
	int	y_new;

	tile_size = game->map.tile_size;
	margin = tile_size / PLAYER_SIZE + PLAYER_BORDER + PLAYER_STEP;
	//printf("tile:%d / p.size:%d + p.border:%d = margin:%d ", tile_size, PLAYER_SIZE, PLAYER_BORDER, margin);
	
	x_new = game->player.pos_x;
	y_new = game->player.pos_y;
	if (wall == 'N')
		y_new -= margin;
	if (wall == 'S')
		y_new += margin;
	if (wall == 'W')
		x_new -= margin;
	if (wall == 'E')
		x_new += margin;
	check_collision(game, x_new, y_new, tile_size, wall);
}