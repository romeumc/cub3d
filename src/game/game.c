/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:03:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/04 17:55:40 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->resolution.x,
			game->resolution.y, "Cub3D!");
}

static void	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx,
			game->resolution.x, game->resolution.y);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel,
			&game->img.line_lenght, &game->img.endian);
}

// void	display_image_texture(t_game *game, t_texture *tex)
// {
// 	int		i;

// 	tex->timg.img = mlx_xpm_file_to_image(game->mlx, tex->path,
// 			&tex->width, &tex->height);
// 	tex->timg.addr = mlx_get_data_addr(tex->timg.img,
// 			&tex->timg.bits_per_pixel,
// 			&tex->timg.line_lenght, &tex->timg.endian);
// 	i = 0;
// 	while (i < 1200)
// 	{
// 		mlx_put_image_to_window(game->mlx, game->win, tex->timg.img, i, 0);
// 		i += tex->width;
// 	}
// 	mlx_destroy_image(game->mlx, tex->timg.img);
// }

// void	display_image_texture(t_game *game, t_texture *tex)
// {
// 	int		i;

// 	tex->timg.img = mlx_xpm_file_to_image(game->mlx, tex->path,
// 			&tex->width, &tex->height);
// 	tex->timg.addr = mlx_get_data_addr(tex->timg.img,
// 			&tex->timg.bits_per_pixel,
// 			&tex->timg.line_lenght, &tex->timg.endian);
// 	i = 0;
// 	while (i < 1200)
// 	{
// 		mlx_put_image_to_window(game->mlx, game->win, tex->timg.img, i, 0);
// 		i += tex->width;
// 	}
// 	mlx_destroy_image(game->mlx, tex->timg.img);
// }

int	main_loop(t_game *game)
{
	/* testes */
	//mlx_string_put(game->mlx, game->win, 100, 500, 0xFF0000, game->t_no.path);
	//display_image_texture(game, &game->t_so);
	init_image(game);
	draw_ceilling(game, game->ceilling);
	draw_floor(game, game->floor);
	draw_wall(game);
	draw_world2d(game, game->map.tile_size);
	draw_player2d(game);
	draw_rays2d(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img);
	return (0);
}

void	rungame(t_game *game)
{
	set_tile_size(game, MINI_MAP_PERCENT);
	printf("TILE_SIZE: %d\n", game->map.tile_size);
	init_window(game);
	load_textures(game);
	//free_textures(game);
	// mlx_get_screen_size(game->mlx, &sizex, &sizey);
	// printf("Resolution - x:%d y:%d\n", sizex, sizey);
	// printf("EXIT CODE:%d\n", KEY_EXIT);
	mlx_key_hook(game->win, key_hook, game);
	mlx_mouse_hook(game->win, mouse_hook, game);
	mlx_hook(game->win, KEY_EXIT, 0, &close_game, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
	//mlx_destroy_image(game->mlx, game->img.img);
}
