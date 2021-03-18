/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:58:30 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 01:52:52 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

static void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*ft_is_all_digit(char *str)
{
	size_t	i;
	i = 0;

	while (i < ft_strlen(str))
	{
		if (!(ft_isdigit(str[i])))
			return ("0");
		i++;
	}
	return (str);
}

static void	get_resolution(char *line, t_game *game)
{
	char	**temp;
	int		i;

	temp = ft_split(line, ' ');
	i = 0;
	while (temp[i] != NULL)
		i++;
	if (i == 3 && game->resolution_x == 0 && game->resolution_y == 0)
	{
		game->resolution_x = ft_atoi(ft_is_all_digit(temp[1]));
		game->resolution_y = ft_atoi(ft_is_all_digit(temp[2]));
	}
	else
		game->invalid_map_resolution = 1;
	if (!(game->resolution_x > 0 && game->resolution_y > 0))
		game->invalid_map_resolution = 1;
	ft_free_split(temp);
}

static void	get_texture(char *line, int *invalid, char **texture)
{
	char	**temp;
	int		i;

	temp = ft_split(line, ' ');
	i = 0;
	while (temp[i] != NULL)
	{
		//printf("i:%d.(%s)\n", i, temp[i]);
		i++;
	}
	//printf("texture antes:[%s]\n", *texture);
	if (i == 2 && ft_strequ(*texture, ""))
	{
		//printf("Aqui(%s)\n", temp[1]);
		free(*texture);
		*texture = ft_strdup(temp[1]);
	}
	else
		*invalid = 1;
	//printf("texture:%s\n", *texture);
	if (ft_strequ(*texture, ""))
		*invalid = 1;
	ft_free_split(temp);
}

static void	get_color(char *line, t_game *game, t_color *area)
{
	char	**temp;
	char	**temp_colors;
	int		i;

	temp = ft_split(line, ' ');
	i = 0;
	while (temp[i] != NULL)
		i++;
	if (i == 2)
	{
		temp_colors = ft_split(temp[1], ',');
		i = 0;
		while (temp_colors[i] != NULL)
			i++;
		if (i == 3 && area->red == -1 && area->green == -1 && area->blue == -1)
		{
			area->red = ft_atoi(temp_colors[0]);
			area->green = ft_atoi(temp_colors[1]);
			area->blue = ft_atoi(temp_colors[2]);
		}
		else
			game->invalid_map_floor = 1;
	}
	else
		game->invalid_map_floor = 1;
	ft_free_split(temp);
	ft_free_split(temp_colors);
}

int	parse_map(char *line, t_game *game)
{
	printf("[%ld] |%s|\n", ft_strlen(line), line);
	if (ft_strncmp(line, "R ", 2) == 0)
		get_resolution(line, game);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		get_texture(line, &game->invalid_map_texture_no, &game->texture_no);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		get_texture(line, &game->invalid_map_texture_so, &game->texture_so);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		get_texture(line, &game->invalid_map_texture_we, &game->texture_we);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		get_texture(line, &game->invalid_map_texture_ea, &game->texture_ea);
	else if (ft_strncmp(line, "S ", 2) == 0)
		get_texture(line, &game->invalid_map_texture_sprite,
					&game->texture_sprite);
	else if (ft_strncmp(line, "F ", 2) == 0)
		get_color(line, game, &game->floor);
	else if (ft_strncmp(line, "C ", 2) == 0)
		get_color(line, game, &game->ceilling);
	return (0);
}
