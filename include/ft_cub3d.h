/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:55:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/15 22:14:02 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef LINUX
#  define X_EVENT_KEY_EXIT		33 //Exit program key Linux
# else
#  define X_EVENT_KEY_EXIT		17 //Exit program on MAC
# endif

# define KEY_ESC				65307
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100
# define KEY_W					119
# define ARROW_RIGHT			65363
# define ARROW_LEFT				65361

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
}				t_game;

#endif