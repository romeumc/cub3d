/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:58:30 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 15:34:50 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

static int	check_valid_file(char *file, char *extension)
{
	if (check_extension(file, extension))
	{
		//printf(ANSI_B_CYAN "OOOOKKKKKKKKKK\n" ANSI_RESET);
		return (1);
	}
	else
		return (0);
}

static void	get_resolution(char *line, t_game *game)
{
	char	**temp;
	int		i;

	if (game->valid_map == -1)
	{
		temp = ft_split(line, ' ');
		i = 0;
		while (temp[i] != NULL)
			i++;
		if (i == 3 && game->resolution_x == 0 && game->resolution_y == 0)
		{
			game->resolution_x = ft_atoi(ft_is_all_digit(temp[1]));
			game->resolution_y = ft_atoi(ft_is_all_digit(temp[2]));
			game->valid_map_resolution = 1;
		}
		if (!(game->resolution_x > 0 && game->resolution_y > 0))
			game->valid_map_resolution = 0;
		ft_free_split(temp);
	}
	else
		game->valid_map_resolution = -2;
}

static void	get_texture(char *line, int *valid, char **texture, t_game *game)
{
	char	**temp;
	int		i;

	if (game->valid_map == -1)
	{
		temp = ft_split(line, ' ');
		i = 0;
		while (temp[i] != NULL)
		{
			//printf("i:%d.(%s)\n", i, temp[i]);
			i++;
		}
		//printf("texture antes:[%s]\n", *texture);
		if (i == 2 && ft_strequ(*texture, "") && *valid == -1)
		{
			//printf("Aqui(%s)\n", temp[1]);
			free(*texture);
			*texture = ft_strdup(temp[1]);
			*valid = check_valid_file(temp[1], ".xpm");
		}
		//printf("texture:%s\n", *texture);
		if (ft_strequ(*texture, ""))
			*valid = 0;
		ft_free_split(temp);
	}
	else
		*valid = -2;
}

static void	get_color(char *line, int *valid, t_color *area)
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
			*valid = 1;
		}
	}
	else
		*valid = 0;
	ft_free_split(temp);
	ft_free_split(temp_colors);
}

int	parse_map(char *line, t_game *game)
{
	printf(ANSI_F_YELLOW "ATTRIBUTES " ANSI_RESET);
	printf("[%ld] |%s|\n", ft_strlen(line), line);
	if (ft_strncmp(line, "R ", 2) == 0)
		get_resolution(line, game);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		get_texture(line, &game->valid_map_texture_no, &game->texture_no, game);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		get_texture(line, &game->valid_map_texture_so, &game->texture_so, game);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		get_texture(line, &game->valid_map_texture_we, &game->texture_we, game);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		get_texture(line, &game->valid_map_texture_ea, &game->texture_ea, game);
	else if (ft_strncmp(line, "S ", 2) == 0)
		get_texture(line, &game->valid_map_texture_sprite,
					&game->texture_sprite, game);
	else if (ft_strncmp(line, "F ", 2) == 0)
		get_color(line, &game->valid_map_floor, &game->floor);
	else if (ft_strncmp(line, "C ", 2) == 0)
		get_color(line, &game->valid_map_ceilling, &game->ceilling);
	else if (validate_string_chars(line, "\t 1") == 1)
	{
		printf(ANSI_F_CYAN "FOUND MAP " ANSI_RESET);
		//printf("[%ld] |%s|\n", ft_strlen(line), line);
		game->valid_map = 0;
	}
	return (0);
}
