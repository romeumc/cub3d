/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:38:49 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/29 17:31:38 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	debug___________________________game(t_game *game, int flag)
{
	if (flag == 1)
	{
		printf(ANSI_F_BGREEN);
		printf("resX:%d - resY:%d\n", game->resolution.x, game->resolution.y);
		printf("texture_no:[%s]\n", game->t_no.path);
		printf("texture_so:[%s]\n", game->t_so.path);
		printf("texture_we:[%s]\n", game->t_we.path);
		printf("texture_ea:[%s]\n", game->t_ea.path);
		printf("texture_sprite:[%s]\n", game->t_sprite.path);
		printf("floor:[%d][%d][%d]\n", game->floor.color.red,
			game->floor.color.green, game->floor.color.blue);
		printf("ceilling:[%d][%d][%d]\n", game->ceilling.color.red,
			game->ceilling.color.green, game->ceilling.color.blue);
		printf("valid map resolution: %d\n", game->resolution.valid);
		printf("valid map texture_no: %d\n", game->t_no.valid);
		printf("valid map texture_so: %d\n", game->t_so.valid);
		printf("valid map texture_we: %d\n", game->t_we.valid);
		printf("valid map texture_ea: %d\n", game->t_ea.valid);
		printf("valid map texture_sprite: %d\n", game->t_sprite.valid);
		printf("valid map floor: %d\n", game->floor.valid);
		printf("valid map ceilling: %d\n", game->ceilling.valid);
		printf("player dir: %c\n", game->player.direction);
		printf("valid map: %d", game->map.valid);
		printf(ANSI_RESET "\n");
	}
}

void	check_map_errors(t_game *game)
{
	if (game->resolution.valid <= 0
		|| game->t_no.valid <= 0
		|| game->t_so.valid <= 0
		|| game->t_we.valid <= 0
		|| game->t_ea.valid <= 0
		|| game->t_sprite.valid <= 0
		|| game->floor.valid <= 0
		|| game->ceilling.valid <= 0
		|| game->other_error < 0
		|| game->map.valid <= 0
		|| game->player.valid <= 0)
	{
		print_map_errors(game);
		free_game(game);
		exit(0);
	}
	else
	{
		debug___________________________game(game, 0);
		game->map.grid = square_matrix(game->map);
	}
}
