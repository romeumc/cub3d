/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:03:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/11 21:36:27 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	print_map_ascii(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)game->map.rows)
	{
		j = 0;
		while (j < (int)game->map.cols)
		{
			if (game->map.grid[i][j] == '1')
				printf(ANSI_F_BGREEN "%c" ANSI_RESET, game->map.grid[i][j]);
			else if (game->map.grid[i][j] == '0')
				printf(ANSI_F_BBLUE "%c" ANSI_RESET, game->map.grid[i][j]);
			else
				printf(ANSI_F_BRED "%c" ANSI_RESET, game->map.grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	validate_args(argc, argv);
	init_structures(&game);
	if (ft_strequ(argv[2], "--save"))
		game.mode = 's';
	open_map_file(argv[1], &game);
	check_map_errors(&game);
	print_map_ascii(&game);
	rungame(&game);
	return (0);
}
