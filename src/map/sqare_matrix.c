/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqare_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:43:09 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/22 17:17:45 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	**square_matrix(t_map map)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < map.lines)
	{
		temp = malloc(sizeof(char) * map.cols);
		memset(temp, ' ', map.cols);
		if (ft_strlen(map.grid[i]) < (size_t)map.cols)
		{
			temp = ft_memcpy(temp, map.grid[i], ft_strlen(map.grid[i]));
			free(map.grid[i]);
			map.grid[i] = ft_strdup(temp);
		}
		i++;
		free(temp);
	}
	return (map.grid);
}
