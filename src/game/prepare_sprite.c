/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:44:27 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/11 17:10:26 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	get_sprite_info(t_map map, t_sprite *sprite, t_player player)
{
	int		i;
	double	delta_x;
	double	delta_y;
	double	fov_min_angle;
	double	fov_max_angle;

	fov_min_angle = 360 - (map.fov / 2) - map.fov * 0.2;
	fov_max_angle = 0 + (map.fov / 2) + map.fov * 0.2;
	i = 0;
	while (i < map.total_sprites)
	{
		delta_x = sprite[i].grid_x - player.pos_x;
		delta_y = sprite[i].grid_y - player.pos_y;
		sprite[i].distance = pythagorean(delta_x, delta_y);
		sprite[i].angle = fix_deg(rad_to_deg(atan2(delta_y, delta_x))
				- (player.angle));
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
			if (sprite[i].distance < sprite[i + 1].distance)
			{
				aux = sprite[i];
				sprite[i] = sprite[i + 1];
				sprite[i + 1] = aux;
				swapped = 1;
			}
			i++;
		}
		if (swapped == 0)
			break ;
	}
}
