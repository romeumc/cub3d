/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:03:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/26 16:21:43 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"



void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->resolution.x,
			game->resolution.y, "Cub3D!");
	game->img.img = mlx_new_image(game->mlx,
			game->resolution.x, game->resolution.y);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel,
			&game->img.line_lenght, &game->img.endian);
}

void	display_image_texture(t_game *game)
{
	int i = 0;
	t_img img1;

	img1.addr = mlx_xpm_file_to_image(game->mlx, game->t_no.path, &game->t_no.width, &game->t_no.height);
	while (i < 1200)
	{
		mlx_put_image_to_window(game->mlx, game->win, img1.addr, i, 0);
		i += game->t_no.height;
	}
	mlx_destroy_image(game->mlx, img1.addr);
}

int	main_loop(t_game *game)
{
	/* testes */
	// mlx_string_put(game->mlx, game->win, 100, 500, 0xFF0000, game->t_no.path);
	// draw_line_test(game);
	//display_player(game);
	//display_image_texture(game);
	
	draw_world2d(game);
	draw_player2d(game);
	draw_rays2d(game);
	
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}


void	rungame(t_game *game)
{
	set_tile_size(game, 100);
	// int		sizex;
	// int		sizey;
	printf("TILE_SIZE: %d\n", game->map.tile_size);
	init_game(game);
	// mlx_get_screen_size(game->mlx, &sizex, &sizey);
	// printf("Resolution - x:%d y:%d\n", sizex, sizey);
	// printf("EXIT CODE:%d\n", KEY_EXIT);
	mlx_key_hook(game->win, key_hook, game);
	mlx_mouse_hook(game->win, mouse_hook, game);
	mlx_hook(game->win, KEY_EXIT, 0, &close_game, game);

	
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);

	//mlx_destroy_image(game->mlx, game->img.addr);
}
