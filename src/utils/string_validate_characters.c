/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validate_characters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:21:58 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 00:51:41 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

int	validate_line(char *str, char *characters)
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

int	count_char(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}
