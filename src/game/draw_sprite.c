/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:17:40 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/08 01:02:43 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

double	fix_rad(double radian)
{
	if (radian > M_2PI)
		radian -= M_2PI;
	if (radian < 0)
		radian += M_2PI;
	return (radian);
}

static void	get_sprite_info(t_map map, t_sprite *sprite, t_player player)
{
	int		i;
	double	delta_x;
	double	delta_y;
	double	fov_min_angle;
	double	fov_max_angle;

	fov_min_angle = deg_to_rad(fix_ang(0 - (map.fov / 2)));
	fov_max_angle = deg_to_rad(fix_ang(0 + (map.fov / 2)));
	i = 0;
	while (i < map.total_sprites)
	{
		delta_x = sprite[i].grid_x - player.pos_x;
		delta_y = sprite[i].grid_y - player.pos_y;
		sprite[i].distance = pythagorean(delta_x, delta_y);
		sprite[i].angle = fix_rad(fix_rad(atan(delta_y / delta_x)
				- deg_to_rad(player.angle)));
		if (sprite[i].angle > fov_min_angle || sprite[i].angle < fov_max_angle)
			sprite[i].visible = 1;
		else
			sprite[i].visible = 0;
		i++;
	}
}

void	sort_sprites(t_map map, t_sprite *sprite)
{
	int			i;
	int			swapped;
	t_sprite	aux;

	i = 0;
	while (1)
	{
		swapped = 0;
		i = 0;
		while (i < map.total_sprites - 1)
		{
			if (sprite[i].distance > sprite[i + 1].distance)
			{
				aux = sprite[i];
				sprite[i] = sprite[i + 1];
				sprite[i + 1] = aux;
				swapped = 1;
			}
			i++;
		}
		if (swapped == 0)
			break;
	}
}

void	draw_sprite(t_sprite *sprite, t_map map, t_game *game)
{
	double	m_screen;
	double	m_sprite;
	double	column_width;
	int i;
	int j;

	sprite->height = map.scale * game->resolution.x / sprite->distance;
	if (sprite->height > game->resolution.y)
		sprite->height = game->resolution.y;
	sprite->pos_y = (game->resolution.y - game->tex_sprite.height) / 2;
	m_screen = game->resolution.x / 2;
	m_sprite = tan(sprite->angle) * (m_screen - tan(deg_to_rad(map.fov / 2)));
	sprite->pos_x = m_screen + m_sprite - game->tex_sprite.width / 2;
	
	column_width = sprite->height / game->tex_sprite.height;
	i = 0;
	while (i < game->tex_sprite.width)
	{
		j = 0;
		while (j < column_width)
		{
			
			j++;
		}
		i++;
	}
}

void	draw_sprites(t_game *game)
{
	int	i;

	get_sprite_info(game->map, game->map.sprite, game->player);
	//sort_sprites(game->map, game->map.sprite);
	i = 0;
	while (i < game->map.total_sprites)
	{
		if (game->map.sprite[i].visible == 1)
			draw_sprite(&game->map.sprite[i], game->map, game);
		i++;
	}


	i = 0;
	while (i < game->map.total_sprites)
	{
		printf("sprite[%d] x:%10f y:%10f", i, game->map.sprite[i].grid_x, game->map.sprite[i].grid_y);
		printf(" player ang:%3d x:%10f y:%10f", game->player.angle, game->player.pos_x, game->player.pos_y);
		printf(" angle: %10f fix:%10f", game->map.sprite[i].angle, fix_rad(game->map.sprite[i].angle));
		printf(" distance: %10f", game->map.sprite[i].distance);
		printf(" visible:%d", game->map.sprite[i].visible);
		printf("\n");
		i++;
	}
}
