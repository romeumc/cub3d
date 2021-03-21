/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:03:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/21 18:15:03 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

// void print_array(t_game *game)
// {
// 	int	i;
// 	//int	j;

// 	i = 0;
// 	//j = 0;
// 	printf("****************\n");
// 	while (game->map.grid[i] != NULL)
// 	{
// 		printf("%s\n", game->map.grid[i]);
// 		i++;
// 	}
// 	printf("++++++++++++++++");
// }

int	main(int argc, char **argv)
{
	t_game	game;

	validate_args(argc, argv);
	init_structures(&game);
	open_map_file(argv[1], &game);
	rungame(&game);
	return (0);
}
