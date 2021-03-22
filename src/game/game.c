/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:03:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 16:16:42 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_game(game);
	return (1);
}

int	mouse_hook(int button, int x, int y, t_game *game)
{
	printf("button:%d x:%d y:%d\n", button, x, y);
	printf("%p", game->mlx);
	return (1);
}

void	my_mlx_pixelput(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



# define TILE_SIZE 32
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

// //Draw the line by DDA algorithm
void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		my_mlx_pixelput(&game->img, x1, y1, 0xb3b3b3);
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}
	draw_line(game, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < ROWS)
	{
		draw_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1);
}

void	draw_rectangle(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_mlx_pixelput(&game->img, x+i, y+j, color);
			//game->img.data[(y  + i) * WIDTH + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_world2d(t_game *game)
{
	int		i;
	int		j;
	int	color;

	color = 0x22FFFF;
	i = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.grid[i][j] == '1')
				draw_rectangle(game, j, i, color);
			j++;
		}
		i++;
	}
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
	//mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int		main_loop(t_game *game)
{
	draw_world2d(game);
	draw_lines(game);
	draw_line_test(game);
	draw_rectangle(game, 10, 1, 0xAABBFF);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

void	rungame(t_game *game)
{
	// int		sizex;
	// int		sizey;
	
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->resolution.x, game->resolution.y, "Cub3D!");
	game->img.img = mlx_new_image(game->mlx, game->resolution.x, game->resolution.y);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_lenght, &game->img.endian);
	
	
	// mlx_get_screen_size(game->mlx, &sizex, &sizey);
	// printf("Resolution - x:%d y:%d\n", sizex, sizey);
	// printf("EXIT CODE:%d\n", KEY_EXIT);
	
	mlx_key_hook(game->win, key_hook, game);
	mlx_mouse_hook(game->win, mouse_hook, game);
	mlx_hook(game->win, KEY_EXIT, 0, &close_game, game);

	mlx_loop_hook(game->mlx, &main_loop, game);	
	mlx_loop(game->mlx);
}
