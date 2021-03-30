/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:10:07 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/29 18:10:15 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_pane(t_img img, t_pane pane)
{
	int	i;
	int	j;
	int	color;

	color = create_trgb(pane.color);
	i = 0;
	while (i < pane.width)
	{
		j = 0;
		while (j < pane.height)
		{
			my_mlx_pixelput(&img, i, pane.pos_y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_ceilling(t_game *game, t_img img, t_pane ceilling)
{
	ceilling.pos_x = 0;
	ceilling.pos_y = 0;
	ceilling.width = game->resolution.x;
	ceilling.height = game->resolution.y / 2;
	draw_pane(img, ceilling);
}

void	draw_floor(t_game *game, t_img img, t_pane floor)
{
	floor.pos_x = 0;
	floor.pos_y = game->resolution.y / 2;
	floor.width = game->resolution.x;
	floor.height = game->resolution.y / 2;
	draw_pane(img, floor);
}
