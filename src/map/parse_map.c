/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:58:30 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 01:38:22 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

static void	get_resolution(char *line, t_game *game)
{
	char	**temp;

	if (game->valid_map == -1)
	{
		temp = ft_split(line, ' ');
		if (ft_split_count(temp) == 3)
		{
			if (game->valid_resolution == -1)
			{
				game->resolution_x = ft_atoi(ft_is_all_digit(temp[1]));
				game->resolution_y = ft_atoi(ft_is_all_digit(temp[2]));
				game->valid_resolution = 1;
			}
			else
				game->valid_resolution = -2;
		}
		if (!(game->resolution_x > 0 && game->resolution_y > 0))
			game->valid_resolution = 0;
		ft_free_split(temp);
	}
	else
		game->valid_resolution = -3;
}

static void	get_texture(char *line, int *valid, char **texture, t_game *game)
{
	char	**temp;

	if (game->valid_map == -1)
	{
		temp = ft_split(line, ' ');
		if (ft_split_count(temp) == 2)
		{
			if (*valid == -1)
			{
				free(*texture);
				*texture = ft_strdup(temp[1]);
				*valid = check_valid_file(temp[1], ".xpm");
			}
			else
				*valid = -2;
		}
		if (ft_strequ(*texture, ""))
			*valid = 0;
		ft_free_split(temp);
	}
	else
		*valid = -3;
}

static int	check_and_save_rgb(t_color *area, char **rgb_color)
{
	area->red = ft_atoi(ft_is_all_digit(rgb_color[0]));
	area->green = ft_atoi(ft_is_all_digit(rgb_color[1]));
	area->blue = ft_atoi(ft_is_all_digit(rgb_color[2]));
	if (area->red >= 0 && area->red <= 255
		&& area->green >= 0 && area->green <= 255
		&& area->blue >= 0 && area->blue <= 255)
		return (1);
	else
		return (0);
}

static void	get_color(char *line, int *valid, t_color *area, t_game *game)
{
	char	**temp;
	char	**rgb_color;

	if (game->valid_map == -1)
	{
		if (*valid == -1)
		{
			temp = ft_split(line, ' ');
			if (ft_split_count(temp) == 2 && count_char(temp[1], ',') == 2)
			{
				rgb_color = ft_split(temp[1], ',');
				if (ft_split_count(rgb_color) == 3
					&& area->red == -1 && area->green == -1 && area->blue == -1)
					*valid = check_and_save_rgb(area, rgb_color);
				ft_free_split(rgb_color);
			}
			else
				*valid = 0;
			ft_free_split(temp);
		}
		else
			*valid = -2;
	}
	else
		*valid = -3;
}

int	parse_map(char *line, t_game *game)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		get_resolution(line, game);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		get_texture(line, &game->valid_texture_no, &game->texture_no, game);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		get_texture(line, &game->valid_texture_so, &game->texture_so, game);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		get_texture(line, &game->valid_texture_we, &game->texture_we, game);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		get_texture(line, &game->valid_texture_ea, &game->texture_ea, game);
	else if (ft_strncmp(line, "S ", 2) == 0)
		get_texture(line, &game->valid_texture_sprite, &game->texture_sprite, game);
	else if (ft_strncmp(line, "F ", 2) == 0)
		get_color(line, &game->valid_floor, &game->floor, game);
	else if (ft_strncmp(line, "C ", 2) == 0)
		get_color(line, &game->valid_ceilling, &game->ceilling, game);
	else if (validate_line(line, "\t 1") == 1 && game->valid_map == -1)
	{
		printf(ANSI_F_CYAN "FOUND MAP START" ANSI_RESET);
		//printf("[%ld] |%s|\n", ft_strlen(line), line);
		game->valid_map = 0;
	}
	else if (validate_line(line, "\t 1") == 1 && game->valid_map == 0)
	{
		printf(ANSI_F_CYAN "FOUND MAP END" ANSI_RESET);
		//printf("[%ld] |%s|\n", ft_strlen(line), line);
		game->valid_map = 0;
	}
	else if (ft_strequ(line, ""))
	{
		printf(ANSI_F_BYELLOW "BLANK LINE " ANSI_RESET);
		//printf("[%ld] |%s|\n", ft_strlen(line), line);
	}
	else if (validate_line(line, "\t 012SNWE") == 1 && game->valid_map == 0)
	{
		printf(ANSI_F_GREEN "MAP " ANSI_RESET);
	}
	else
	{
		printf(ANSI_F_YELLOW "ERROR " ANSI_RESET);
		game->valid_map = -5;
	}
	//printf(ANSI_F_YELLOW "ATTRIBUTES " ANSI_RESET);
	//printf("[%ld] |%s|\n", ft_strlen(line), line);
	return (0);
}
