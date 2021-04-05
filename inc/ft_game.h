/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:49:40 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/05 12:57:06 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# include "ft_structs.h"

# define PLAYER_STEP		1
# define PLAYER_SIZE		6
# define ROTATION_STEP		1
# define FIELD_OF_VIEW		60
# define MINI_MAP_PERCENT	30
# define DISTANCE_TO_WALL	1
# define SCALE				5

int		close_game(t_game *game);
void	free_game(t_game *game);
int		key_hook(int keycode, t_game *game);
int		mouse_hook(int button, int x, int y, t_game *game);
void	draw_world2d(t_game *game, int tile_size);
void	my_mlx_pixelput(t_game *game, int x, int y, int color);

void	draw_circle(t_game *game, t_player *shape, int center);
void	draw_s_rectangle(t_game *game, int x, int y, int color);
void	draw_rectangle(t_game *game, int x, int y, int color);
void	draw_player2d(t_game *game);

void	set_tile_size(t_game *game, int percentage);
int		create_trgb(t_color color);
t_color	set_trgb(int temp_color);
void	check_wall(t_game *game, char wall);
void	rotate_player(t_player *player, int rotation);

double	fix_ang(double a);
double	get_start_direction(char direction);
void	rotate_player(t_player *player, int rotation);

void	draw_rays2d(t_game *game);
double	get_ray_distance_v(t_game *game, t_player *player, t_ray *ray);
double	get_ray_distance_h(t_game *game, t_player *player, t_ray *ray);
int		is_wall(t_map *map, int screen_x, int screen_y);
double	cast_ray(t_game *game, double ray_angle, t_ray *ray);

//void	draw_line(t_game *game, double x1, double y1, double x2, double y2);
void	draw_ceilling(t_game *game, t_pane ceilling);
void	draw_floor(t_game *game, t_pane floor);
void	draw_wall(t_game *game);
void	free_textures(t_game *game);

void	free_tex(t_game *game, t_texture *tex);

#endif