/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:44:49 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/26 21:49:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	side_walk(t_player *player, int angle)
{
	player->delta_x = cos(deg_to_rad(player->angle + angle));
	player->delta_y = sin(deg_to_rad(player->angle + angle));
	player->pos_x += player->delta_x * PLAYER_STEP;
	player->pos_y += player->delta_y * PLAYER_STEP;
}

int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook:%3d ", keycode);
	printf("x:%4f y%4f ", game->player.pos_x, game->player.pos_y);
	printf("tile:%d [%2d][%2d] ", game->map.tile_size, (int)(game->player.pos_x / game->map.tile_size), (int)(game->player.pos_y / game->map.tile_size));
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_A)
	{
		side_walk(&game->player, -90);
		//check_wall(game, 'W');
	}
	else if (keycode == KEY_D)
	{
		side_walk(&game->player, 90);
		//check_wall(game, 'E');
	}
	else if (keycode == KEY_W)
	{
		game->player.pos_x += game->player.delta_x * PLAYER_STEP;
		game->player.pos_y += game->player.delta_y * PLAYER_STEP;
		//check_wall(game, 'N');
	}
	else if (keycode == KEY_S)
	{
		game->player.pos_x -= game->player.delta_x * PLAYER_STEP;
		game->player.pos_y -= game->player.delta_y * PLAYER_STEP;
		//check_wall(game, 'S');
	}
	else if (keycode == RIGHT_ARROW)
		rotate_player(&game->player, ROTATION_STEP * 1);
	else if (keycode == LEFT_ARROW)
		rotate_player(&game->player, ROTATION_STEP * -1);
	return (1);
}

// int		hook_key_released(int keycode, t_game *game)
// {
// 	(void)game;
// 	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
// 		{}
// 		//game->player.walk_direction = 0;
// 	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
// 		{}
// 		//game->player.turn_direction = 0;
// 	return (1);
// }

int	mouse_hook(int button, int x, int y, t_game *game)
{
	printf("button:%d x:%d y:%d\n", button, x, y);
	(void)game;
	//printf("%p", game->mlx);
	return (1);
}
