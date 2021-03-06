/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:05:50 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/12 00:22:51 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include <stdint.h>

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_img;

typedef struct s_texture
{
	char	*path;
	int		valid;
	int		width;
	int		height;
	t_img	timg;
}	t_texture;

typedef struct s_resolution
{
	int		x;
	int		y;
	int		valid;
}	t_resolution;

typedef struct s_sprite
{
	double	grid_x;
	double	grid_y;
	double	angle;
	double	distance;
	int		visible;
	double	height;
	int		pos_y;
	int		pos_x;
	double	slice_width;
}	t_sprite;

typedef struct s_map
{
	int			rows;
	int			cols;
	char		**grid;
	int			valid;
	int			tile_size;
	int			toggle_minimap;
	int			fov;
	int			scale;
	int			total_sprites;
	t_sprite	*sprite;
}	t_map;

typedef struct s_color
{
	int	transparency;
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_player
{
	char	direction;
	int		valid;
	double	pos_x;
	double	pos_y;
	t_color	color;
	double	delta_x;
	double	delta_y;
	double	angle;
}	t_player;

typedef struct s_pane
{
	int		pos_x;
	int		pos_y;
	int		height;
	int		width;
	t_color	color;
	int		valid;
}	t_pane;

typedef struct s_game
{
	char			mode;
	void			*mlx;
	void			*win;
	t_img			img;
	int				other_error;
	t_player		player;
	t_map			map;
	t_resolution	resolution;
	t_texture		t_no;
	t_texture		t_so;
	t_texture		t_ea;
	t_texture		t_we;
	t_texture		tex_sprite;
	t_pane			floor;
	t_pane			ceilling;
}	t_game;

typedef struct s_ray
{
	int			grid_hit_v;
	int			grid_hit_h;
	int			pos_x;
	int			pos_y;
	int			height;
	char		intersection;
	double		distance;
	int			x_tex;
	int			y_tex;
	double		tex_step;
	double		tex_offset;
	double		angle;
	t_texture	tex;
}	t_ray;

typedef struct s_bmp_header
{
	char		byte_signature[2];
	uint32_t	size;
	uint32_t	reserved_bytes;
	uint32_t	byte_offset;
}	t_bmp_header;

typedef struct s_dib_header
{
	uint32_t	dib_header_size;
	int32_t		width;
	int32_t		height;
	uint16_t	number_color_planes;
	uint16_t	bpp;
	uint32_t	compression_method;
	uint32_t	raw_bitmap_data_size;
	int32_t		horizontal_resolution;
	int32_t		vertical_resolution;
	uint32_t	color_table;
	uint32_t	important_colors;
}	t_dib_header;

#endif