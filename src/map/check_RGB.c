/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_RGB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:56:14 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 16:56:25 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	check_and_save_rgb(t_color *area, char **rgb_color)
{
	area->red = ft_atoi(ft_is_all_digit(rgb_color[0]));
	area->green = ft_atoi(ft_is_all_digit(rgb_color[1]));
	area->blue = ft_atoi(ft_is_all_digit(rgb_color[2]));
	if (area->red >= 0 && area->red <= 255
		&& area->green >= 0 && area->green <= 255
		&& area->blue >= 0 && area->blue <= 255)
		return (1);
	else
		return (0);
}
