/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:05:50 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/04 17:55:30 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

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

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**grid;
	int		valid;
	int		tile_size;
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
	int		angle;
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
	t_texture		t_sprite;
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

#endif