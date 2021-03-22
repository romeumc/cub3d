/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:04:09 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 16:54:20 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include <errno.h>		//permit errors
# include <string.h>	//allow for function strerrror

# include "ft_structs.h"

void	init_structures(t_game *game);
int		parse_map(char *line, t_game *game);
int		check_and_save_rgb(t_color *area, char **rgb_color);
int		validate_map_line(char *str, char *characters);
void	print_error(char *s1, char *s2);
void	check_map_errors(t_game *game);
void	save_map_line(char *line, t_map *map, t_game *game);
char	**square_matrix(t_map map);
void	print_map_errors(t_game *game);

#endif