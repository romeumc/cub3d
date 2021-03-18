/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:03:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 14:28:36 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void	free_game(t_game *game)
{
	free(game->texture_no);
	free(game->texture_so);
	free(game->texture_we);
	free(game->texture_ea);
	free(game->texture_sprite);
}

static void	init_invalid_map(t_game *game)
{
	game->valid_map_resolution = -1;
	game->valid_map_texture_no = -1;
	game->valid_map_texture_so = -1;
	game->valid_map_texture_we = -1;
	game->valid_map_texture_ea = -1;
	game->valid_map_texture_sprite = -1;
	game->valid_map_floor = -1;
	game->valid_map_ceilling = -1;
	game->valid_map = -1;
}

static void	init_game_struct(t_game *game)
{
	game->resolution_x = 0;
	game->resolution_y = 0;
	game->texture_no = ft_strdup("");
	game->texture_so = ft_strdup("");
	game->texture_we = ft_strdup("");
	game->texture_ea = ft_strdup("");
	game->texture_sprite = ft_strdup("");
	game->floor.red = -1;
	game->floor.green = -1;
	game->floor.blue = -1;
	game->ceilling.red = -1;
	game->ceilling.green = -1;
	game->ceilling.blue = -1;
	init_invalid_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	validate_args(argc, argv);
	init_game_struct(&game);
	open_map_file(argv[1], &game);
	rungame();
	free_game(&game);
	return (0);
}
