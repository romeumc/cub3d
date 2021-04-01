/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:38:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/01 20:21:45 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	load_tex(t_game *game, t_texture *tex)
{
	tex->timg.img = mlx_xpm_file_to_image(game->mlx, tex->path,
			&tex->width, &tex->height);
	tex->timg.addr = mlx_get_data_addr(tex->timg.img,
			&tex->timg.bits_per_pixel,
			&tex->timg.line_lenght, &tex->timg.endian);
}

void	free_tex(t_game *game, t_texture *tex)
{
	mlx_destroy_image(game->mlx, tex->timg.img);
}

void	load_textures(t_game *game)
{
	load_tex(game, &game->t_ea);
	load_tex(game, &game->t_we);
	load_tex(game, &game->t_no);
	load_tex(game, &game->t_so);
	load_tex(game, &game->t_sprite);
}

void	free_textures(t_game *game)
{
	free_tex(game, &game->t_ea);
	free_tex(game, &game->t_we);
	free_tex(game, &game->t_no);
	free_tex(game, &game->t_so);
	free_tex(game, &game->t_sprite);
}
