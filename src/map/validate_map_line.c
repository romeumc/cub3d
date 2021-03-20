/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:47:27 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 23:33:30 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

/*
** Validate if is a Map line, by checking if only contains allowed characters
** And make sure it as digit at least a '1'
** this doesn't garantee that the map is enclosed
*/
int	validate_map_line(char *str, char *characters)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (characters[j] != '\0')
		{
			if (str[i] == characters[j])
				break ;
			j++;
		}
		if (j == ft_strlen(characters))
			return (0);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}
