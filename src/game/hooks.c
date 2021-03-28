/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:44:49 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/28 23:39:26 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	side_walk(t_game *game, t_player *player, int angle)
{
	angle = fix_ang(player->angle + angle);
	if (cast_ray(game, angle) > DISTANCE_TO_WALL)
	{
		player->delta_x = cos(deg_to_rad(angle));
		player->delta_y = sin(deg_to_rad(angle));
		player->pos_x += player->delta_x * PLAYER_STEP;
		player->pos_y += player->delta_y * PLAYER_STEP;
	}
}

static void walk(t_game *game, t_player *player, char keycode)
{
	int angle;

	if (keycode == 'W')
	{
		angle = fix_ang(player->angle);
		if (cast_ray(game, angle) > DISTANCE_TO_WALL)
		{
			player->pos_x += player->delta_x * PLAYER_STEP;
			player->pos_y += player->delta_y * PLAYER_STEP;
		}
	}
	else if (keycode == 'S')
	{
		angle = fix_ang(player->angle - 180);
		if (cast_ray(game, angle) > DISTANCE_TO_WALL)
		{
			player->pos_x -= player->delta_x * PLAYER_STEP;
			player->pos_y -= player->delta_y * PLAYER_STEP;
		}
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_A)
	{
		side_walk(game, &game->player, -90);
	}
	else if (keycode == KEY_D)
	{
		side_walk(game, &game->player, 90);
	}
	else if (keycode == KEY_W)
	{
		walk(game, &game->player, 'W');
	}
	else if (keycode == KEY_S)
	{
		walk(game, &game->player, 'S');
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
