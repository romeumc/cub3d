/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:03:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/12 00:29:31 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->resolution.x,
			game->resolution.y, "Cub3D!");
	mlx_do_key_autorepeaton(game->mlx);
}

static void	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx,
			game->resolution.x, game->resolution.y);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel,
			&game->img.line_lenght, &game->img.endian);
}

int	main_loop(t_game *game)
{
	init_image(game);
	draw_minimap(game);
	draw_ceilling(game, game->ceilling);
	draw_floor(game, game->floor);
	draw_wall(game, game->map);
	draw_sprites(game);
	if (game->map.toggle_minimap == 1)
		draw_minimap(game);
	if (game->mode == 's')
	{
		save_bmp(game);
		close_game(game);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
		mlx_destroy_image(game->mlx, game->img.img);
	}
	return (0);
}

void	rungame(t_game *game)
{
	set_tile_size(game, MINI_MAP_PERCENT);
	init_window(game);
	load_textures(game);
	get_sprites(&game->map);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, KEY_EXIT, 0, &close_game, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}
