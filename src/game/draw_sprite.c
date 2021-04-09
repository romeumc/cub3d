/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:17:40 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/09 16:19:51 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_sprite_slice(t_sprite *sprite, t_game *game, t_ray *ray)
{
	double	tex_pos;
	int		y;
	int		color;

	ray->tex = game->tex_sprite;
	ray->tex_step = 1.0 * ray->tex.height / sprite->height;
	tex_pos = (sprite->pos_y - game->resolution.y / 2 + sprite->height / 2) * ray->tex_step;
	y = 0;
	while (y < sprite->height && y < game->resolution.y)
	{
		ray->y_tex = (int)tex_pos & (ray->tex.height - 1);
		//ray->y_tex = 1.0 * ray->tex_step * (y + (int)ray->tex_offset);
		tex_pos += ray->tex_step;
		color = get_color_tex(&ray->tex, ray);
		//if (color != 0)
			my_mlx_pixelput(game, ray->tex_offset, sprite->pos_y + y, color);
		y++;
	}
}

void	draw_sprite1(t_sprite *sprite, t_game *game)
{
	int		i;
	int		j;
	t_ray	ray;

	ray.angle = fix_deg(sprite->angle);
	sprite->slice_width = sprite->height / game->tex_sprite.height;
	i = 0;
	while (i < game->tex_sprite.width)
	{
		j = 0;
		while (j < sprite->slice_width)
		{
			ray.distance = cast_ray(game, ray.angle, &ray);
			ray.tex_offset = (int)(sprite->pos_x + (i - 1) * sprite->slice_width + j);
			ray.x_tex = i;
			printf(ANSI_F_BRED "RAY dist:%10f offset:%10f x_tex:%2d slice:%10f" ANSI_RESET,
								ray.distance, ray.tex_offset, ray.x_tex, sprite->slice_width);
			if (ray.tex_offset >= 0 && ray.tex_offset <= game->resolution.x - 1
				&& sprite->distance < ray.distance)
			{
				printf(ANSI_F_BMAGENTA" sprite_distance:%10f ray.distance:%10f ray.angle:%10f\n"ANSI_RESET, sprite->distance, ray.distance, ray.angle);
				draw_sprite_slice(sprite, game, &ray);
			}
			j++;
			ray.angle = fix_deg(ray.angle + game->map.fov * 1.0 / game->resolution.x);
		}
		i++;
	}
}

void	draw_sprite(t_sprite *sprite, t_map map, t_game *game)
{
	double	m_screen;
	double	m_sprite;

	sprite->height = map.scale * game->resolution.x / sprite->distance;
	if (sprite->height > game->resolution.y)
		sprite->height = game->resolution.y;
	sprite->pos_y = (game->resolution.y - sprite->height) / 2;
	m_screen = game->resolution.x / 2;
	m_sprite = tan(deg_to_rad(sprite->angle)) * (m_screen / tan(deg_to_rad(map.fov / 2)));
	sprite->pos_x = m_screen + m_sprite - game->tex_sprite.width / 2;
	draw_sprite1(sprite, game);
}

void	draw_sprites(t_game *game)
{
	int	i;

	get_sprite_info(game->map, game->map.sprite, game->player);
	sort_sprites(game->map, game->map.sprite);
	i = 0;
	while (i < game->map.total_sprites)
	{
		if (game->map.sprite[i].visible == 1)
			draw_sprite(&game->map.sprite[i], game->map, game);
		i++;
	}

	i = 0;
	t_ray ray;
	while (i < game->map.total_sprites)
	{
		printf("sprite[%d]", i);
		//printf(" x:%10f y:%10f", game->map.sprite[i].grid_x, game->map.sprite[i].grid_y);
		printf(" player_ang:%3d", game->player.angle);
		//printf(" x:%10f y:%10f", game->player.pos_x, game->player.pos_y);
		//printf(" angle: %10f fix:%10f", game->map.sprite[i].angle, fix_rad(game->map.sprite[i].angle));
		printf(" sprite_ang: %3.f", game->map.sprite[i].angle);
		printf(" distance: %10f", game->map.sprite[i].distance);
		printf(" height: %10f", game->map.sprite[i].height);
		//printf(" minFOV: %3d", 360 - game->map.fov / 2);
		//printf(" maxFOV: %3d", 0 + game->map.fov / 2);
		printf(" sprite.pos_x:%10d", game->map.sprite[i].pos_x);
		printf(" sprite.pos_y:%10d", game->map.sprite[i].pos_y);
		printf(" visible:%d", game->map.sprite[i].visible);
		printf(" wall:%10f", cast_ray(game, game->player.angle, &ray));
		printf("\n");
		i++;
	}
}
