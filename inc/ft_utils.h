/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:43:53 by rmartins          #+#    #+#             */
/*   Updated: 2021/04/08 10:06:31 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <fcntl.h>		//open
# include <unistd.h>	//close write
# include <stdlib.h>	//malloc free
# include <stdio.h>		//printf
# include <math.h>

# include "ft_ansi.h"
# include "get_next_line.h"

int		count_specific_char(char *str, char c);
int		check_valid_file(char *file, char *extension);
int		check_extension(char *argv, char *extension);
double	pythagorean(double adjacent, double opposite);
double	deg_to_rad(double deg);
double	fix_rad(double radian);
double	rad_to_deg(double rad);
double	fix_deg(double a);

#endif