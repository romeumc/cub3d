/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:44:52 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 21:10:41 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void	validate_args(int argc, char **argv)
{
	if (argc == 1 || argc > 3)
	{
		print_error("Wrong usage,",
			"must use: cub3D <path to map.cub> [--save]");
		exit(0);
	}
	else if (argc == 3 && !ft_strequ(argv[2], "--save"))
	{
		print_error("Wrong usage,", "second parameter should be \"--save\"");
		exit(0);
	}
	else if (argc == 2 && check_extension(argv[1], ".cub") == 0)
	{
		print_error("Wrong map extension,", "must be [.cub]");
		exit(0);
	}
}
