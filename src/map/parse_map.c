/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:58:30 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 17:34:39 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	get_resolution(char *line, t_game *game)
{
	char	**temp;

	if (game->map.valid == 0)
	{
		temp = ft_split(line, ' ');
		if (ft_split_count(temp) == 3)
		{
			if (game->resolution.valid == 0)
			{
				game->resolution.x = ft_atoi(ft_is_all_digit(temp[1]));
				game->resolution.y = ft_atoi(ft_is_all_digit(temp[2]));
				game->resolution.valid = 1;
			}
			else
				game->resolution.valid = -2;
		}
		if (!(game->resolution.x > 0 && game->resolution.y > 0))
			game->resolution.valid = -1;
		ft_free_array_array(temp);
	}
	else
		game->resolution.valid = -3;
}

static void	get_texture(char *line, t_texture *texture, t_game *game)
{
	char	**temp;

	if (game->map.valid == 0)
	{
		temp = ft_split(line, ' ');
		if (ft_split_count(temp) == 2)
		{
			if (texture->valid == 0)
			{
				free(texture->path);
				texture->path = ft_strdup(temp[1]);
				texture->valid = check_valid_file(temp[1], ".xpm");
			}
			else
				texture->valid = -2;
		}
		if (ft_strequ(texture->path, ""))
			texture->valid = -1;
		ft_free_array_array(temp);
	}
	else
		texture->valid = -3;
}

static void	get_color(char *line, t_color *color, t_game *game)
{
	char	**temp;
	char	**rgb_color;

	if (game->map.valid == 0)
	{
		if (color->valid == 0)
		{
			temp = ft_split(line, ' ');
			if (ft_split_count(temp) == 2
				&& count_specific_char(temp[1], ',') == 2)
			{
				rgb_color = ft_split(temp[1], ',');
				if (ft_split_count(rgb_color) == 3)
					color->valid = check_and_save_rgb(color, rgb_color);
				ft_free_array_array(rgb_color);
			}
			else
				color->valid = -1;
			ft_free_array_array(temp);
		}
		else
			color->valid = -2;
	}
	else
		color->valid = -3;
}

int	parse_map2(char *line, t_game *game)
{
	if (validate_map_line(line, "\t 1") == 1 && game->map.valid == 0)
	{
		game->map.valid = -5;
		save_map_line(line, &game->map, game);
	}
	else if (validate_map_line(line, "\t 1") == 1 && game->map.valid == -6)
	{
		game->map.valid = 1;
		save_map_line(line, &game->map, game);
	}
	else if (validate_map_line(line, "\t 0123SNWE") == 1
		&& game->map.valid <= -5)
	{
		game->map.valid = -6;
		save_map_line(line, &game->map, game);
	}
	else
	{
		game->other_error = -1;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_map(char *line, t_game *game)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		get_resolution(line, game);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		get_texture(line, &game->t_no, game);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		get_texture(line, &game->t_so, game);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		get_texture(line, &game->t_we, game);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		get_texture(line, &game->t_ea, game);
	else if (ft_strncmp(line, "S ", 2) == 0)
		get_texture(line, &game->t_sprite, game);
	else if (ft_strncmp(line, "F ", 2) == 0)
		get_color(line, &game->floor, game);
	else if (ft_strncmp(line, "C ", 2) == 0)
		get_color(line, &game->ceilling, game);
	else if (ft_strequ(line, ""))
		return (EXIT_SUCCESS);
	else
	{
		if (parse_map2(line, game) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
