/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:48:53 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/28 22:52:01 by rmartins         ###   ########.fr       */
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

// void	check_line_valid(t_map *map, t_player *player, t_game *game)
// {
// 	int	line;
// 	int	col;
// 	int ccol;
// 	int cline;

// 	line = map->rows;
// 	col = 0;
// 	while (col < map->cols)
// 	{
// 		ccol = 0;
// 		cline = 0;
// 		if (col == 0 || col == map->cols - 1)
// 			ccol = 1;
// 		if (line == 0)
// 			cline = 1;
// 		if (map->grid[line][col] == ' ')
// 		{
//			is_character_valid("02NSWE", game, line, col);
// 		}
// 		if (map->grid[line][col] != '1' && map->grid[line][col] != ' ')
// 		{
// 		// 	if (col == 0)
// 		// 	{
// 		// 		printf(ANSI_B_BRED "%c" ANSI_RESET, map->grid[line][col]);
// 		// 		game->other_error = -2;
// 		// 	}
// 		// 	else if (col == map->cols - 1)
// 		// 	{
// 		// 		printf(ANSI_B_BRED "%c" ANSI_RESET, map->grid[line][col]);
// 		// 		game->other_error = -2;
// 		// 	}
//			is_character_valid(" ", game, line, col);
// 		}
// 		if (ft_strchr("NSWE", map->grid[line][col]) != NULL)
// 		{
// 			if (player->valid == 0)
// 			{
// 				printf(ANSI_B_BLUE "%c" ANSI_RESET, map->grid[line][col]);
// 				player->direction = map->grid[line][col];
// 				player->valid = 1;
// 			}
// 			else
// 			{
// 				printf(ANSI_B_RED "%c" ANSI_RESET, map->grid[line][col]);
// 				player->valid = -2;
// 			}
// 		}
// 		else if (map->grid[line][col] == '1')
// 			printf(ANSI_F_BGREEN "%c" ANSI_RESET, map->grid[line][col]);
// 		else
// 			printf(ANSI_F_BBLUE "%c" ANSI_RESET, map->grid[line][col]);
// 		col++;
// 	}
// 	printf("\n");
// }

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
