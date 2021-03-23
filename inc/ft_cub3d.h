/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:55:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 17:41:45 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

//# include <mlx.h>
//# include "../mlx/mlx.h"
# include "../mlxbeta/mlx.h"
# include "../libft/libft.h"
# include "ft_utils.h"
# include "ft_map.h"
# include "ft_game.h"

# ifndef LINUX_COMPUTER
#  include "ft_mac_keys.h"
# else
#  include "ft_linux_keys.h"
# endif

void	validate_args(int argc, char **argv);
void	open_map_file(char *filename, t_game *game);
void	rungame(t_game *game);
void	print_array(t_game *game);
void	print_array1(t_game *game);

#endif
