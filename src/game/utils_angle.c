/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:01:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/08 11:32:41 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

double	deg_to_rad(double deg)
{
	return (fix_rad(deg * M_PI / 180.0));
}

double	rad_to_deg(double rad)
{
	return (fix_deg(rad * 180.0 / M_PI));
}

double	fix_rad(double radian)
{
	if (radian > M_2PI)
		radian -= M_2PI;
	if (radian < 0)
		radian += M_2PI;
	return (radian);
}

double	fix_deg(double a)
{
	if (a > 360)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}
