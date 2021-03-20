/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:38:49 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 22:21:03 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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
	if (game->other_error == -1)
		print_error("Found line with errors", "or map not closed");
	else
	{
		print_map_error_description(game->resolution.valid, "Resolution");
		print_map_error_description(game->t_no.valid, "NO Texture");
		print_map_error_description(game->t_so.valid, "SO Texture");
		print_map_error_description(game->t_we.valid, "WE Texture");
		print_map_error_description(game->t_ea.valid, "EA Texture");
		print_map_error_description(game->t_sprite.valid, "SPRITE Texture");
		print_map_error_description(game->floor.valid, "Floor Color");
		print_map_error_description(game->ceilling.valid, "Ceilling Color");
	}
}

static void	debug___________________________game(t_game *game, int flag)
{
	if (flag == 1)
	{
		printf(ANSI_F_BGREEN);
		printf("resX:%d - resY:%d\n", game->resolution.x, game->resolution.y);
		printf("texture_no:[%s]\n", game->t_no.path);
		printf("texture_so:[%s]\n", game->t_so.path);
		printf("texture_we:[%s]\n", game->t_we.path);
		printf("texture_ea:[%s]\n", game->t_ea.path);
		printf("texture_sprite:[%s]\n", game->t_sprite.path);
		printf("floor:[%d][%d][%d]\n",
			game->floor.red, game->floor.green, game->floor.blue);
		printf("ceilling:[%d][%d][%d]\n",
			game->ceilling.red, game->ceilling.green, game->ceilling.blue);
		printf("valid map resolution: %d\n", game->resolution.valid);
		printf("valid map texture_no: %d\n", game->t_no.valid);
		printf("valid map texture_so: %d\n", game->t_so.valid);
		printf("valid map texture_we: %d\n", game->t_we.valid);
		printf("valid map texture_ea: %d\n", game->t_ea.valid);
		printf("valid map texture_sprite: %d\n", game->t_sprite.valid);
		printf("valid map floor: %d\n", game->floor.valid);
		printf("valid map ceilling: %d\n", game->ceilling.valid);
		printf(ANSI_RESET "\n");
	}
}

void	check_map_errors(t_game *game)
{
	if (game->resolution.valid <= 0
		|| game->t_no.valid <= 0
		|| game->t_so.valid <= 0
		|| game->t_we.valid <= 0
		|| game->t_ea.valid <= 0
		|| game->t_sprite.valid <= 0
		|| game->floor.valid <= 0
		|| game->ceilling.valid <= 0
		|| game->other_error < 0
		|| game->valid_map < 0)
	{
		print_map_errors(game);
		free_game(game);
		exit(0);
	}
	else
		debug___________________________game(game, 1);
}
