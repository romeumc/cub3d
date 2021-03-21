/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:54:32 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/21 21:32:16 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static size_t		get_length_with_tabs(char *line)
{
	size_t	i;
	size_t j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\t')
			j += 4;
		else
			j++;
		i++;
	}
	return (j);
}

static char	*ft_strdup_subst(const char *s, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	j;
	char	*temp;

	i = -1;
	k = 0;
	temp = malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	while (s[++i] != '\0')
	{
		if(s[i] == '\t')
		{
			j = 0;
			while(j < 4)
				temp[k + j++] = ' ';
			k += 4;
		}
		else
			temp[k++] = s[i];
	}
	while (k < len)
		temp[k++] = ' ';
	temp[k] = '\0';
	return (temp);
}

void	check_line_valid(t_map *map, t_player *player, t_game *game)
{
	size_t	line;
	size_t	col;

	line = map->line;
	col = 0;
	while(col < map->col)
	{
		if (map->grid[line][col] != '1' && map->grid[line][col] != ' ')
		{
			if (map->grid[line][col - 1] == ' '
				|| map->grid[line - 1][col - 1] == ' '
				|| map->grid[line - 1][col] == ' '
				|| map->grid[line - 1][col + 1] == ' '
				|| map->grid[line][col + 1] == ' ')
			{
				printf(ANSI_B_BRED "%c" ANSI_RESET, map->grid[line][col]);
				game->other_error = -2;
			}
			else if (ft_strchr("NSWE", map->grid[line][col]) != NULL)
			{
				if (player->valid == 0)
				{
					printf(ANSI_B_BLUE "%c" ANSI_RESET, map->grid[line][col]);
					player->direction = map->grid[line][col];
					player->valid = 1;
				}
				else
				{
					printf(ANSI_F_RED "%c" ANSI_RESET, map->grid[line][col]);
					player->valid = -2;
				}
			}
			else
			{
				printf(ANSI_F_BBLUE "%c" ANSI_RESET, map->grid[line][col]);
			}
		}
		else
		{
			//printf(ANSI_F_GREEN "%c" ANSI_RESET, map->grid[line-1][col]);
			printf(ANSI_F_BGREEN "%c" ANSI_RESET, map->grid[line][col]);
		}
		col++;
	}
}

void	save_map_line(char *line, t_map *map, t_game *game)
{
	if (get_length_with_tabs(line) > map->col)
		map->col = get_length_with_tabs(line);
	//map->grid = malloc(sizeof(char *) * 200);
	//map->grid = ft_realloc(map->grid, sizeof(char *) * (map->line + 1));
	// if (map->grid == NULL)
	// 	return (0);
	map->grid[map->line] = ft_strdup_subst(line, map->col);
	check_line_valid(map, &game->player, game);
	printf("length:%3ld - grid.line:%3d ", ft_strlen(map->grid[map->line]), map->line);
	printf(ANSI_B_BCYAN "[%s]" ANSI_RESET "\n", map->grid[map->line]);
	map->line++;
	map->grid[map->line] = NULL;
	//return (1);
}