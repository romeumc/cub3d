/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:48:53 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/12 14:48:35 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	check_player(t_player *player, char direction)
{
	if (player->valid == 0)
	{
		player->direction = direction;
		player->valid = 1;
	}
	else
		player->valid = -2;
}

static void	is_character_valid(char *str, t_game *game, int line, int col)
{
	int		ccol;
	int		cline;
	char	**grid;

	ccol = 0;
	cline = 0;
	grid = game->map.grid;
	if (col == 0 || col == game->map.cols - 1)
		ccol = 1;
	if (line == 0)
		cline = 1;
	if (ft_strchr(str, grid[line][col - 1 + ccol]) != NULL
		|| ft_strchr(str, grid[line][col + 1 - ccol]) != NULL
		|| ft_strchr(str, grid[line - 1 + cline][col - 1 + ccol]) != NULL
		|| ft_strchr(str, grid[line - 1 + cline][col]) != NULL
		|| ft_strchr(str, grid[line - 1 + cline][col + 1 - ccol]) != NULL)
		game->other_error = -2;
}

void	check_line_valid(t_map *map, t_player *player, t_game *game)
{
	int	line;
	int	col;

	line = map->rows;
	col = 0;
	while (col < map->cols)
	{
		if (map->grid[line][col] == ' ')
			is_character_valid("02NSWE", game, line, col);
		if (map->grid[line][col] != '1' && map->grid[line][col] != ' ')
			is_character_valid(" ", game, line, col);
		if (ft_strchr("NSWE", map->grid[line][col]) != NULL)
			check_player(player, map->grid[line][col]);
		col++;
	}
}
