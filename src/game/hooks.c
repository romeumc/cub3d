/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:44:49 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/30 01:43:57 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	side_walk(t_game *game, t_player *player, int angle)
{
	t_ray	ray;
	angle = fix_ang(player->angle + angle);
	if (cast_ray(game, angle, &ray) > DISTANCE_TO_WALL)
	{
		player->delta_x = cos(deg_to_rad(angle));
		player->delta_y = sin(deg_to_rad(angle));
		player->pos_x += player->delta_x * PLAYER_STEP;
		player->pos_y += player->delta_y * PLAYER_STEP;
	}
}

static void	walk(t_game *game, t_player *player, char keycode)
{
	int		angle;
	t_ray	ray;

	if (keycode == 'W')
	{
		angle = fix_ang(player->angle);
		if (cast_ray(game, angle, &ray) > DISTANCE_TO_WALL)
		{
			player->pos_x += player->delta_x * PLAYER_STEP;
			player->pos_y += player->delta_y * PLAYER_STEP;
		}
	}
	else if (keycode == 'S')
	{
		angle = fix_ang(player->angle - 180);
		if (cast_ray(game, angle, &ray) > DISTANCE_TO_WALL)
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

int	mouse_hook(int button, int x, int y, t_game *game)
{
	printf("button:%d x:%d y:%d\n", button, x, y);
	(void)game;
	return (1);
}
