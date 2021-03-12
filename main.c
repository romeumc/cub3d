/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:27:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/12 16:39:54 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_EXIT		33 //Exit program key code

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
}				t_game;

// int	key_hook(int keycode, t_game *game)
// {
// 	printf("Hello from key_hook: %d\n", keycode);
// }

// int	mouse_hook(int button, int x, int y, t_game *game)
// {
// 	printf("x:%d y:%d\n",x, y);
// }

int	close(int keycode, t_game *game)
{

	//mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

// void	my_mlx_pixelput(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int		main_loop(t_game *game)
{

	// draw_rectangles(game);
	// draw_lines(game);
	// mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	img;
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 500, 500, "Hello World!");
	// img.img = mlx_new_image(game.mlx, 500, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

	// for (int x=0; x < 200; x++)
	// {
	// 	my_mlx_pixelput(&img, x, 5, 0x00FF0000);
	// }
	// for (int x = 0; x < 200; x++)
	// {
	// 	my_mlx_pixelput(&img, 5, x, 0x00FFFF00);
	// }
	// mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 0);

	
	// mlx_key_hook(game.win, key_hook, &game);
	// mlx_mouse_hook(game.win, mouse_hook, &game);
	//mlx_hook(game.win, 2, 1L<<0, close, &game);
	//mlx_hook(mlx_win, 33, 0, mlx_destroy_window, mlx);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
