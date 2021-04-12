/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:48:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/12 14:43:40 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include <sys/stat.h>

void	write_file_header(t_game *game, int fd)
{
	t_bmp_header	bmp_header;

	ft_strncpy(bmp_header.byte_signature, "BM", 2);
	bmp_header.size = 54 + game->resolution.x * game->resolution.y
		* (game->img.bits_per_pixel / 8);
	bmp_header.reserved_bytes = 0;
	bmp_header.byte_offset = 14 + 40;
	write(fd, &bmp_header.byte_signature, 2);
	write(fd, &bmp_header.size, 4);
	write(fd, &bmp_header.reserved_bytes, 4);
	write(fd, &bmp_header.byte_offset, 4);
}

void	write_info_header(t_game *game, int fd)
{
	t_dib_header	dib_header;

	ft_memset(&dib_header, 0, 40);
	dib_header.dib_header_size = 40;
	dib_header.width = game->resolution.x;
	dib_header.height = -game->resolution.y;
	dib_header.number_color_planes = 1;
	dib_header.bpp = game->img.bits_per_pixel;
	dib_header.horizontal_resolution = 2835;
	dib_header.vertical_resolution = 2835;
	write(fd, &dib_header.dib_header_size, 4);
	write(fd, &dib_header.width, 4);
	write(fd, &dib_header.height, 4);
	write(fd, &dib_header.number_color_planes, 2);
	write(fd, &dib_header.bpp, 2);
	write(fd, &dib_header.compression_method, 4);
	write(fd, &dib_header.raw_bitmap_data_size, 4);
	write(fd, &dib_header.horizontal_resolution, 4);
	write(fd, &dib_header.vertical_resolution, 4);
	write(fd, &dib_header.color_table, 4);
	write(fd, &dib_header.important_colors, 4);
}

void	write_data(t_game *game, int fd)
{
	size_t	size;
	int		i;
	int		j;
	char	*pixel_arr;

	size = game->resolution.x * game->resolution.y
		* (game->img.bits_per_pixel / 8);
	pixel_arr = malloc(sizeof(char) * size);
	if (pixel_arr == NULL)
		exit(EXIT_SUCCESS);
	i = 0;
	j = 0;
	size /= 4;
	while (i < (int)size)
	{
		pixel_arr[j++] = get_b(game->img.addr[i]);
		pixel_arr[j++] = get_g(game->img.addr[i]) >> 8;
		pixel_arr[j++] = get_r(game->img.addr[i]) >> 16;
		pixel_arr[j++] = get_t(game->img.addr[i]) >> 24;
		i++;
	}
	write(fd, pixel_arr, size * 4);
	free(pixel_arr);
}

void	save_bmp(t_game *game)
{
	int		fd;
	mode_t	mode;

	mode = S_IRUSR | S_IRGRP | S_IROTH;
	fd = open("capture.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, mode);
	if (fd == -1)
	{
		printf("Error\nCould not create file");
		exit(0);
	}
	write_file_header(game, fd);
	write_info_header(game, fd);
	write_data(game, fd);
}
