/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:14:01 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 01:38:04 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_cub3d.h"

int	check_extension(char *argv, char *extension)
{
	char	*temp;

	if (ft_strlen(argv) > 4)
		temp = ft_substr(argv, (int)ft_strlen(argv) - 4, 4);
	else
		temp = ft_strdup("");
	if (!ft_strequ(temp, extension))
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

int	check_valid_file(char *file, char *extension)
{
	int fd;

	if (check_extension(file, extension))
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			return (-4);
		return (1);
	}
	else
		return (0);
}