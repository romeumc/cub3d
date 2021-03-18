/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:55:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/18 01:09:45 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

//# include <mlx.h>
//# include "../mlx/mlx.h"
# include "../mlxbeta/mlx.h"
# include "../libft/libft.h"
# include "ft_ansi.h"
# include <stdio.h> //printf
# include <stdlib.h> //malloc free
# include <fcntl.h>	//open
# include <unistd.h> //close write
# include <errno.h> //permit errors
# include <string.h> // allow for fucntion strerrror

# define BUFFER_SIZE 1024
# define MAX 2147479552
# define MAXFD 512

# ifndef LINUX_COMPUTER
#  define X_EVENT_KEY_EXIT		17 //Exit program on MAC
# else
#  define X_EVENT_KEY_EXIT		33 //Exit program key Linux
# endif

# define KEY_ESC				65307
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100
# define KEY_W					119
# define ARROW_RIGHT			65363
# define ARROW_LEFT				65361

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;
typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		resolution_x;
	int		resolution_y;
	char	*texture_no;
	char	*texture_so;
	char	*texture_ea;
	char	*texture_we;
	char	*texture_sprite;
	t_color	floor;
	t_color	ceilling;
	int		invalid_map_resolution;
	int		invalid_map_texture_no;
	int		invalid_map_texture_so;
	int		invalid_map_texture_we;
	int		invalid_map_texture_ea;
	int		invalid_map_texture_sprite;
	int		invalid_map_floor;
	int		invalid_map_ceilling;
}	t_game;

void	validate_args(int argc, char **argv);
int		get_next_line(int fd, char **line);
int		open_map_file(char *filename, t_game *game);
int		parse_map(char *line, t_game *game);
void	rungame(void);
// size_t	len(const char *s);
// void	ft_bzero(void *s, size_t n);
// char	*ft_strcpy(char *dest, const char *src);
// char	*ft_strdup_join(char *s, char c);
#endif
