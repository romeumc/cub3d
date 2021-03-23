/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:03:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/23 13:19:42 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	my_mlx_pixelput(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line_test(t_game *game)
{
	for (int x=0; x < 200; x++)
	{
		my_mlx_pixelput(&game->img, x, 5, 0x00FF0000);
	}
	for (int x = 0; x < 200; x++)
	{
		my_mlx_pixelput(&game->img, 5, x, 0x00FFFF00);
	}
	for (int x = 0; x < 200; x++)
	{
		my_mlx_pixelput(&game->img, x, x, 0x00FFFF00);
	}
	// draw_rectangle(game, 0, 20, 0xAAFFFF);
	// draw_rectangle(game, 1, 1, 0xFFFFAA);
	// draw_rectangle(game, 10, 10, 0xFF00FF);
	// mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	display_image(t_game *game)
{
	int i = 0;
	t_img img1;

	draw_line_test(game);
	img1.addr = mlx_xpm_file_to_image(game->mlx, game->t_no.path, &game->t_no.width, &game->t_no.height);
	while (i < 1200)
	{
		mlx_put_image_to_window(game->mlx, game->win, img1.addr, i, 0);
		i += game->t_no.height;
	}
	mlx_destroy_image(game->mlx, img1.addr);
	printf("TESTE:%d %d\n", game->t_no.width, game->t_no.height);
}

void	display_player(t_game *game)
{
	t_img	img1;
	t_shape	player;

	img1.img = mlx_new_image(game->mlx, 10, 10);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.line_lenght, &img1.endian);

	player.color = 0x60FF22;

	for (int x=0; x < 200; x++)
	{
		player.pos_x = x;
		player.pos_y = 100;
		//draw_circle(game, x, 100, 0x60FF25);
		draw_circle(game, &img1, &player);
	}
	mlx_destroy_image(game->mlx, &img1);
}

int	main_loop(t_game *game)
{
	draw_world2d(game);
	// draw_line_test(game);
	// draw_rectangle(game, 10, 1, 0xAABBFF);
	display_player(game);
	mlx_string_put(game->mlx, game->win, 100, 500, 0xFF0000, game->t_no.path);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 50);
	return (0);
}

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

void	set_tile_size(t_game *game, int percentage)
{
	int tile_x;
	int tile_y;

	tile_x = game->resolution.x / game->map.cols;
	tile_y = game->resolution.y / game->map.rows;
	if (tile_x > tile_y)
		game->map.tile_size = tile_y * percentage/100;
	else
		game->map.tile_size = tile_x * percentage/100;
}

void	rungame(t_game *game)
{
	// int		sizex;
	// int		sizey;
	set_tile_size(game, 80);
	printf("TILE_SIZE: %d\n", game->map.tile_size);
	init_game(game);
	// mlx_get_screen_size(game->mlx, &sizex, &sizey);
	// printf("Resolution - x:%d y:%d\n", sizex, sizey);
	// printf("EXIT CODE:%d\n", KEY_EXIT);
	mlx_key_hook(game->win, key_hook, game);
	mlx_mouse_hook(game->win, mouse_hook, game);
	mlx_hook(game->win, KEY_EXIT, 0, &close_game, game);

	
	mlx_loop_hook(game->mlx, &main_loop, game);
	display_image(game);

	mlx_loop(game->mlx);

	//mlx_destroy_image(game->mlx, game->img.addr);
}
