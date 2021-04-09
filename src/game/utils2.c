/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:31:32 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/09 17:49:53 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

double	get_start_direction(char direction)
{
	double	angle;

	angle = 0;
	if (direction == 'N')
		angle = 270;
	else if (direction == 'S')
		angle = 90;
	else if (direction == 'E')
		angle = 0;
	else if (direction == 'W')
		angle = 180;
	return (angle);
}

void	rotate_player(t_player *player, double rotation)
{
	player->angle = fix_deg(player->angle + rotation);
}

int	is_wall(t_map *map, int screen_x, int screen_y)
{
	int	x;
	int	y;

	x = screen_x / map->tile_size;
	y = screen_y / map->tile_size;
	if (x > map->cols - 1 || x < 0)
		return (1);
	if (y > map->rows - 1 || y < 0)
		return (1);
	if (map->grid[y][x] == '1')
		return (1);
	return (0);
}

double	pythagorean(double adjacent, double opposite)
{
	double	hypotenuse;

	hypotenuse = sqrt(pow(fabs(adjacent), 2) + pow(fabs(opposite), 2));
	return (hypotenuse);
}
