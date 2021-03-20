/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_specific_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:21:58 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 22:52:15 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	count_specific_char(char *str, char c)
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
