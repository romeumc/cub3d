/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:38:49 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 01:41:09 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

void	print_error(char *s1, char *s2)
{
	printf(ANSI_F_RED "Error\n" ANSI_RESET);
	printf(ANSI_F_BRED "%s %s\n" ANSI_RESET, s1, s2);
}

static void	print_map_error_description(int error, char *field)
{
	if (error == -1)
		print_error(field, "- Missing");
	else if (error == 0)
		print_error(field, "- Type errors");
	else if (error == -2)
		print_error(field, "- Found duplicate");
	else if (error == -3)
		print_error(field, "- Found after map");
	else if (error == -4)
		print_error(field, "- File/Directory missing");
}

static void	print_map_errors(t_game *game)
{
	if (game->valid_map == -5)
		print_error("Found line with errors", "");
	else
	{
		print_map_error_description(game->valid_resolution, "Resolution");
		print_map_error_description(game->valid_texture_no, "NO Texture");
		print_map_error_description(game->valid_texture_so, "SO Texture");
		print_map_error_description(game->valid_texture_we, "WE Texture");
		print_map_error_description(game->valid_texture_ea, "EA Texture");
		print_map_error_description(game->valid_texture_sprite, "SPRITE Texture");
		print_map_error_description(game->valid_floor, "Floor Color");
		print_map_error_description(game->valid_ceilling, "Ceilling Color");
	}
}

static void	debug___________________________game(t_game *game, int flag)
{
	if (flag == 1)
	{
		printf(ANSI_F_BGREEN);
		printf("res_X:%d - res_Y:%d\n", game->resolution_x,
			game->resolution_y);
		printf("texture_no:[%s]\n", game->texture_no);
		printf("texture_so:[%s]\n", game->texture_so);
		printf("texture_we:[%s]\n", game->texture_we);
		printf("texture_ea:[%s]\n", game->texture_ea);
		printf("texture_sprite:[%s]\n", game->texture_sprite);
		printf("floor:[%d][%d][%d]\n", game->floor.red,
			game->floor.green, game->floor.blue);
		printf("ceilling:[%d][%d][%d]\n", game->ceilling.red,
			game->ceilling.green, game->ceilling.blue);
		printf("valid map resolution: %d\n", game->valid_resolution);
		printf("valid map texture_no: %d\n", game->valid_texture_no);
		printf("valid map texture_so: %d\n", game->valid_texture_so);
		printf("valid map texture_we: %d\n", game->valid_texture_we);
		printf("valid map texture_ea: %d\n", game->valid_texture_ea);
		printf("valid map texture_sprite: %d\n",
			game->valid_texture_sprite);
		printf("valid map floor: %d\n", game->valid_floor);
		printf("valid map ceilling: %d\n", game->valid_ceilling);
		printf(ANSI_RESET);
	}
}

void	check_map_errors(t_game *game)
{
	if (game->valid_resolution <= 0
		|| game->valid_texture_no <= 0
		|| game->valid_texture_so <= 0
		|| game->valid_texture_we <= 0
		|| game->valid_texture_ea <= 0
		|| game->valid_texture_sprite <= 0
		|| game->valid_floor <= 0
		|| game->valid_ceilling <= 0
		|| game->valid_map < 0)
	{
		print_map_errors(game);
		free_game(game);
		exit(0);
	}
	else
		debug___________________________game(game, 1);
}