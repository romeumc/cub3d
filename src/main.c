/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:27:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/15 22:29:49 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

int	close_game(int keycode, t_game *game)
{
	printf("Hello from close: %d\n", keycode);
	printf("%p", game->mlx);
	//mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_game(KEY_ESC, game);
	return (1);
}

int	mouse_hook(int button, int x, int y, t_game *game)
{
	printf("button:%d x:%d y:%d\n",button, x, y);
	printf("%p", game->mlx);
	return (1);
}

void	my_mlx_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	img;
	t_game	game;
	int sizex;
	int sizey;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 500, 500, "Hello World!");
	img.img = mlx_new_image(game.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

	for (int x=0; x < 200; x++)
	{
		my_mlx_pixelput(&img, x, 5, 0x00FF0000);
	}
	for (int x = 0; x < 200; x++)
	{
		my_mlx_pixelput(&img, 5, x, 0x00FFFF00);
	}
	mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 0);

	mlx_get_screen_size(game.mlx, &sizex, &sizey);
	printf("Resolution - x:%d y:%d\n", sizex, sizey);
	printf("EXIT CODE:%d\n", X_EVENT_KEY_EXIT);
	
	mlx_key_hook(game.win, key_hook, &game);
	mlx_mouse_hook(game.win, mouse_hook, &game);

	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	//mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
