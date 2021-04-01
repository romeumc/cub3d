/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:48:48 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/30 22:51:09 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	free_game(t_game *game)
{
	if (game->t_no.valid != 0)
		free(game->t_no.path);
	if (game->t_so.valid != 0)
		free(game->t_so.path);
	if (game->t_we.valid != 0)
		free(game->t_we.path);
	if (game->t_ea.valid != 0)
		free(game->t_ea.path);
	if (game->t_sprite.valid != 0)
		free(game->t_sprite.path);
	if (game->map.valid != 0)
		ft_free_array_array(game->map.grid);
}

int	close_game(t_game *game)
{
	//mlx_destroy_image(game->mlx, game->img.img);
	//free_textures(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	exit(0);
}
