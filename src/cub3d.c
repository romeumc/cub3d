/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:03:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 00:18:14 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void print_array1(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	printf("lines:%d cols:%ld\n", game->map.line, game->map.col);
	printf("****************\n");
	while (i < (int)game->map.line)
	{
		j = 0;
		//while (game->map.grid[i][j] != '\0')
		while (j < (int)game->map.col)
		{
			printf("%c", game->map.grid[i][j]);
			j++;
		}
		printf("| line:%i cols:%i\n", i, j);
		i++;
	}
}

void print_array(t_game *game)
{
	int	i;

	i = 0;
	printf("****************\n");
	while (game->map.grid[i] != NULL)
	{
		printf("%s| line:%i cols:%ld\n", game->map.grid[i], i, game->map.col);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	validate_args(argc, argv);
	init_structures(&game);
	open_map_file(argv[1], &game);
	print_array1(&game);
	print_array(&game);
	rungame(&game);
	return (0);
}
