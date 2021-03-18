/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:49:07 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 14:58:55 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

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
		printf("valid map resolution: %d\n", game->valid_map_resolution);
		printf("valid map texture_no: %d\n", game->valid_map_texture_no);
		printf("valid map texture_so: %d\n", game->valid_map_texture_so);
		printf("valid map texture_we: %d\n", game->valid_map_texture_we);
		printf("valid map texture_ea: %d\n", game->valid_map_texture_ea);
		printf("valid map texture_sprite: %d\n",
			game->valid_map_texture_sprite);
		printf("valid map floor: %d\n", game->valid_map_floor);
		printf("valid map ceilling: %d\n", game->valid_map_ceilling);
		printf(ANSI_RESET);
	}
}

// static void	print_map_errors_cont(t_game *game)
// {
// 	if (game->valid_map_floor == -1)
// 		print_error("Missing map Floor color");
// 	else if (game->valid_map_floor == 0)
// 		print_error("Floor color field as error typos");
// 	else if (game->valid_map_ceilling == -1)
// 		print_error("Missing map Ceilling color");
// 	else if (game->valid_map_ceilling == 0)
// 		print_error("Ceilling color field as error typos");
// }

static void print_map_error_description(int error, char *field)
{
	if (error == -1)
		print_error("Missing map", field);
	else if (error == 0)
		print_error(field, "field as error typos");
	else if (error == -2)
		print_error(field, "found after map");
}

static void	print_map_errors(t_game *game)
{
	print_map_error_description(game->valid_map_resolution, "Resolution");
	print_map_error_description(game->valid_map_texture_no, "NO Texture");
	print_map_error_description(game->valid_map_texture_so, "SO Texture");
	print_map_error_description(game->valid_map_texture_we, "WE Texture");
	print_map_error_description(game->valid_map_texture_ea, "EA Texture");
	print_map_error_description(game->valid_map_texture_sprite, "SPRITE Texture");
	
	// if (game->valid_map_resolution == -1)
	// 	print_error("Missing map resolution");
	// else if (game->valid_map_resolution == 0)
	// 	print_error("Resolution map field as error typos");
	// else if (game->valid_map_texture_no == -1)
	// 	print_error("Missing map NO texture");
	// else if (game->valid_map_texture_no == 0)
	// 	print_error("NO texture field as error typos");
	// else if (game->valid_map_texture_so == -1)
	// 	print_error("Missing map SO texture");
	// else if (game->valid_map_texture_so == 0)
	// 	print_error("SO texture field as error typos");
	// else if (game->valid_map_texture_we == -1)
	// 	print_error("Missing map WE texture");
	// else if (game->valid_map_texture_we == 0)
	// 	print_error("WE texture field as error typos");
	// else if (game->valid_map_texture_ea == -1)
	// 	print_error("Missing map EA texture");
	// else if (game->valid_map_texture_ea == 0)
	// 	print_error("EA texture field as error typos");
	// else if (game->valid_map_texture_sprite == -1)
	// 	print_error("Missing map SRITE texture");
	// else if (game->valid_map_texture_sprite == 0)
	// 	print_error("SPRITE texture field as error typos");
	//print_map_errors_cont(game);
}

static void	check_map_errors(t_game *game)
{
	if (game->valid_map_resolution <= 0
		|| game->valid_map_texture_no <= 0
		|| game->valid_map_texture_so <= 0
		|| game->valid_map_texture_we <= 0
		|| game->valid_map_texture_ea <= 0
		|| game->valid_map_texture_sprite <= 0
		|| game->valid_map_floor <= 0
		|| game->valid_map_ceilling <= 0)
	{
		print_map_errors(game);
		free_game(game);
		exit(0);
	}
	else
		debug___________________________game(game, 1);
}

int	open_map_file(char *filename, t_game *game)
{
	int		fd;
	int		j;
	char	*line;

	line = 0;
	j = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno), "");
		exit (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		parse_map(line, game);
		free(line);
		j++;
	}
	debug___________________________game(game, 0);
	free(line);
	close(fd);
	check_map_errors(game);
	return (0);
}
