/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:17:40 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/12 00:28:29 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_sprite_slice(t_sprite *sprite, t_game *game, t_ray *ray)
{
	int		y;
	int		color;

	ray->tex = game->tex_sprite;
	ray->tex_step = 1.0 * ray->tex.height / sprite->height;
	y = 0;
	while (y < sprite->height)
	{
		ray->y_tex = ray->tex_step * y;
		color = get_color_tex(&ray->tex, ray);
		if (color != 0)
			my_mlx_pixelput(game, ray->pos_x, sprite->pos_y + y, color);
		y++;
	}
}

void	draw_sprite1(t_sprite *sprite, t_game *game)
{
	int		i;
	int		j;
	t_ray	ray;

	ray.angle = fix_deg(sprite->angle + game->player.angle);
	sprite->slice_width = sprite->height / game->tex_sprite.height;
	i = 0;
	while (i < game->tex_sprite.width)
	{
		j = 0;
		while (j < sprite->slice_width)
		{
			ray.distance = cast_ray(game, ray.angle, &ray);
			ray.pos_x = sprite->slice_width * i + sprite->pos_x + j;
			ray.x_tex = i;
			if (sprite->distance < ray.distance && ray.pos_x >= 0
				&& ray.pos_x <= game->resolution.x)
				draw_sprite_slice(sprite, game, &ray);
			j++;
			ray.angle = fix_deg(ray.angle + game->map.fov
					* 1.0 / game->resolution.x);
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
	m_sprite = tan(deg_to_rad(sprite->angle))
		* (m_screen / tan(deg_to_rad(map.fov / 2)));
	sprite->pos_x = m_screen + m_sprite + (game->tex_sprite.width / 2);
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
}
