/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:54:32 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/27 22:52:12 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static size_t	get_length_with_tabs(char *line)
{
	size_t	i;
	size_t	j;

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

static char	*ft_strdup_subst(const char *s, size_t len, size_t k)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = -1;
	temp = malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[i] == '\t')
		{
			j = 0;
			while (j < 4)
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

//***** Atempt to remalloc rows ****
//map->grid = ft_realloc(map->grid, sizeof(char *) * (map->line + 1));
// if (map->grid == NULL)
// 	return (0);

void	save_map_line(char *line, t_map *map, t_game *game)
{
	if ((int)get_length_with_tabs(line) > map->cols)
		map->cols = get_length_with_tabs(line);
	map->grid[map->rows] = ft_strdup_subst(line, map->cols, 0);
	check_line_valid(map, &game->player, game);
	map->rows++;
	map->grid[map->rows] = NULL;
}
