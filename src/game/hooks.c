/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:44:49 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 17:45:12 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_game(game);
	return (1);
}

int	mouse_hook(int button, int x, int y, t_game *game)
{
	printf("button:%d x:%d y:%d\n", button, x, y);
	printf("%p", game->mlx);
	return (1);
}
