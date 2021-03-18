/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validate_charaters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:21:58 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 15:33:04 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

int	validate_string_chars(char *str, char *characters)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (characters[j] != '\0')
		{
			if (characters[j] != str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}