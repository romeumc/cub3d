/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:03:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/24 22:28:08 by rmartins         ###   ########.fr       */
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




// void	draw_line_test(t_game *game)
// {
// 	for (int x=0; x < 200; x++)
// 	{
// 		my_mlx_pixelput(&game->img, x, 5, 0x00FF0000);
// 	}
// 	for (int x = 0; x < 200; x++)
// 	{
// 		my_mlx_pixelput(&game->img, 5, x, 0x00FFFF00);
// 	}
// 	for (int x = 0; x < 200; x++)
// 	{
// 		my_mlx_pixelput(&game->img, x, x, 0x00FFFF00);
// 	}
// }

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

// void	display_player(t_game *game)
// {
// 	t_shape	player;

// 	player.color = 0x60FF22;
// 	for (int x=0; x < 200; x++)
// 	{
// 		player.color++;
// 		player.pos_x = x;
// 		player.pos_y = x;
// 		draw_circle(game, &game->img, &player, 1);
// 	}
// }

double	get_start_direction(char direction)
{
	double	angle;

	angle = 0;
	if (direction == 'N')
		angle = 270;
	else if (direction == 'S')
		angle = 90;
	else if (direction == 'E')
		angle = 360;
	else if (direction == 'W')
		angle = 180;
	return (angle);
}

void	draw_player_line1(t_game *game, t_player *line, int distance)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = line->delta_x * distance;
	delta_y = line->delta_y * distance;
	pixels = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = line->pos_x;
	pixel_y = line->pos_y;
	while (pixels)
	{
		my_mlx_pixelput(&game->img, (int)pixel_x, (int)pixel_y, 0xFF0000);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	draw_player2d(t_game *game)
{
	int		i;
	int		j;
	
	if (game->player.valid == 1)
	{
		i = 0;
		while (i < game->map.rows)
		{
			j = 0;
			while (j < game->map.cols)
			{
				if (ft_strchr("NSWE", game->map.grid[i][j]))
				{
					game->player.valid = 2;
					game->player.color = set_trgb(0xFF2222);
					game->player.pos_x = game->map.tile_size * j;
					game->player.pos_y = game->map.tile_size * i;
					draw_circle(game, &game->img, &game->player, 1);
					game->player.angle = get_start_direction(game->player.direction);
					//game->player.delta_x = cos(deg_to_rad(game->player.angle));
					//game->player.delta_y = -sin(deg_to_rad(game->player.angle));
				}
				j++;
			}
			i++;
		}
	}
	else if (game->player.valid == 2)
	{
		draw_circle(game, &game->img, &game->player, 0);
		game->player.delta_x = cos(deg_to_rad(game->player.angle));
		game->player.delta_y = sin(deg_to_rad(game->player.angle));
		// // game->player.delta_x = game->player.pos_x - 1000;
		// game->player.delta_y = game->player.pos_y + 200;
		//printf(ANSI_F_BBLUE"x:%f y:%f - dx:%f dy:%f\n"ANSI_RESET, game->player.pos_x, game->player.pos_y, game->player.delta_x, game->player.delta_y);
		draw_player_line1(game, &game->player, 100);
	}
}

int	fix_ang(int a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return a;
}

void	rotate_player(t_player *player, int rotation)
{
	player->angle += rotation;
	printf(ANSI_F_CYAN "Rotation:%d Angle: %f " ANSI_RESET, rotation, player->angle);
	player->angle = fix_ang(player->angle);
	printf(ANSI_F_YELLOW "new Angle: %f \n" ANSI_RESET, player->angle);

	// player->delta_x = cos(deg_to_rad(player->angle));
	// player->delta_y = sin(deg_to_rad(player->angle));
}

int	main_loop(t_game *game)
{
	/* testes */
	// mlx_string_put(game->mlx, game->win, 100, 500, 0xFF0000, game->t_no.path);
	// draw_line_test(game);
	//display_player(game);
	display_image_texture(game);
	
	draw_world2d(game);
	draw_player2d(game);
	
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 64);
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
