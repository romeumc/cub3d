/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:15:31 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/19 22:21:41 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static int	read_buff(char *buffer, char **line, int buff_len, int pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (pos > 0)
		pos -= 1;
	while (j + i < buff_len + 1)
	{
		if (buffer[i + j] == '\0')
		{
			ft_strcpy(buffer, &buffer[i + j + 1]);
			return (pos + i + j + 1);
		}
		if (buffer[i + j] == '\n')
		{
			ft_strcpy(buffer, &buffer[i + j + 1]);
			return ((pos + i + j + 1) * -1);
		}
		line[0] = ft_strdup_join(line[0], buffer[i + j]);
		j++;
	}
	return (0);
}

static void	clean_extra_buffer(char *buffer, int pos, int buffer_size)
{
	while (pos < buffer_size)
	{
		buffer[pos] = '\0';
		pos++;
	}
}

static int	get_position(char *buffer, char **line)
{
	int	pos;

	if (ft_strlen(buffer) == 0)
		pos = 0;
	else
		pos = read_buff(buffer, line, ft_strlen(buffer), 0);
	return (pos);
}

int	get_next_line(int fd, char **line)
{
	int			pos;
	static char	buffer[MAXFD][BUFFER_SIZE + 1];
	int			ret;

	*line = malloc(sizeof(char));
	if (line == NULL || fd > MAXFD || fd < 0 || *line == NULL)
		return (-1);
	*line[0] = '\0';
	pos = get_position(buffer[fd], line);
	if (pos < 0)
		return (1);
	ft_bzero(buffer[fd], BUFFER_SIZE);
	ret = read(fd, buffer[fd], BUFFER_SIZE);
	while (ret != 0)
	{
		if (ret < 0)
			return (-1);
		clean_extra_buffer(buffer[fd], ret, BUFFER_SIZE);
		pos = read_buff(buffer[fd], line, ret, pos);
		if (pos < 0)
			return (1);
	}
	ft_bzero(buffer[fd], BUFFER_SIZE);
	return (0);
}
