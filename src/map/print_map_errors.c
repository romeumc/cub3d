/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:53:59 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 09:54:10 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	print_error(char *s1, char *s2)
{
	printf(ANSI_F_RED "Error\n" ANSI_RESET);
	printf(ANSI_F_BRED "%s %s\n" ANSI_RESET, s1, s2);
}

static void	print_error_description(int error, char *field)
{
	if (error == 0)
		print_error(field, "- Missing");
	else if (error == -1)
		print_error(field, "- Type errors");
	else if (error == -2)
		print_error(field, "- Found duplicate");
	else if (error == -3)
		print_error(field, "- Found after map");
	else if (error == -4)
		print_error(field, "- File/Directory missing");
	else if (error <= -5)
		print_error(field, "- Not closed");
}

void	print_map_errors(t_game *game)
{
	if (game->other_error == -1)
		print_error("Found line with error", "");
	else if (game->other_error == -2)
		print_error("Map is NOT closed", "");
	else
	{
		print_error_description(game->resolution.valid, "Resolution");
		print_error_description(game->t_no.valid, "NO Texture");
		print_error_description(game->t_so.valid, "SO Texture");
		print_error_description(game->t_we.valid, "WE Texture");
		print_error_description(game->t_ea.valid, "EA Texture");
		print_error_description(game->t_sprite.valid, "SPRITE Texture");
		print_error_description(game->floor.valid, "Floor Color");
		print_error_description(game->ceilling.valid, "Ceilling Color");
		print_error_description(game->map.valid, "Map");
		print_error_description(game->player.valid, "Player");
	}
}
