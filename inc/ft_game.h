/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:49:40 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/23 13:11:50 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# include "ft_structs.h"
# define TILE_SIZE 32
# define PLAYER_RADIUS 6

int		close_game(t_game *game);
void	free_game(t_game *game);
int		key_hook(int keycode, t_game *game);
int		mouse_hook(int button, int x, int y, t_game *game);
void	draw_world2d(t_game *game);
void	my_mlx_pixelput(t_img *data, int x, int y, int color);

void	draw_circle(t_game *game, t_img *img, t_shape *shape);
void	draw_small_rectangle(t_game *game, int x, int y, int color);
void	draw_rectangle(t_game *game, int x, int y, int color);
void	draw_line(t_game *game, double x1, double y1, double x2, double y2);

#endif