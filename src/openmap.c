/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:01:15 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/17 18:04:38 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

static int	check_extension(char *argv)
{
	char	*temp;

	if (ft_strlen(argv) > 4)
		temp = ft_substr(argv, (int)ft_strlen(argv) - 4, 4);
	else
		temp = ft_strdup("");
	if (!ft_strequ(temp, ".cub"))
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

void	validate_args(int argc, char **argv)
{
	if (argc == 1 || argc > 3)
	{
		printf(ANSI_F_BRED
				"Wrong usage, please run: cub3D <path to map.cub> [--save]"
				ANSI_RESET);
		exit(0);
	}
	else if (argc == 3 && !ft_strequ(argv[2], "--save"))
	{
		printf(ANSI_F_BRED
				"Wrong usage, second parameter should be \"--save\""
				ANSI_RESET);
		exit(0);
	}
	else if (argc == 2 && check_extension(argv[1]) == 0)
	{
		printf(ANSI_F_BRED "Wrong map extension, must be [.cub]\n" ANSI_RESET);
		exit(0);
	}
}

int	openmap(char *filename)
{
	int		fd;
	int		j;
	char	*line;

	line = 0;
	j = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("\nError in open - %s\n", strerror(errno));
		exit (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		printf("[%ld] |%s|\n", ft_strlen(line), line);
		free(line);
		j++;
	}
	printf("[%ld] |%s|\n", ft_strlen(line), line);
	free(line);
	close(fd);
	return (0);
}
