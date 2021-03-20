/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:03:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/20 00:24:52 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	free_game(t_game *game)
{
	free(game->t_no.path);
	free(game->t_so.path);
	free(game->t_we.path);
	free(game->t_ea.path);
	free(game->t_sprite.path);
}

int	main(int argc, char **argv)
{
	t_game	game;

	validate_args(argc, argv);
	init_structures(&game);
	open_map_file(argv[1], &game);
	rungame(&game);
	free_game(&game);
	return (0);
}
