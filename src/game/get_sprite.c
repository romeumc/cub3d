/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:51:33 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/08 00:58:42 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	save_sprite(t_map *map, int x, int y, int index)
{
	map->sprite[index].grid_x = x * map->tile_size + (map->tile_size / 2);
	map->sprite[index].grid_y = y * map->tile_size + (map->tile_size / 2);
}

static int	count_sprites(t_map *map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == '2')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	get_sprites(t_map *map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	map->total_sprites = count_sprites(map);
	map->sprite = malloc(sizeof(t_sprite) * map->total_sprites);
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == '2')
			{
				save_sprite(map, x, y, count);
				count++;
			}
			x++;
		}
		y++;
	}
}
