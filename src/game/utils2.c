/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:31:32 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/27 19:34:12 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	fix_ang(int a)
{
	if (a > 360)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

double	get_start_direction(char direction)
{
	double	angle;

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

void	rotate_player(t_player *player, int rotation)
{
	player->angle = fix_ang(player->angle + rotation);
	printf(ANSI_F_CYAN "Rotation:%d Angle: %d\n" ANSI_RESET,
		rotation, (int)player->angle);
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
