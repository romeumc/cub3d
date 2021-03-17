/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:55:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/17 19:02:07 by rmartins         ###   ########.fr       */
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		teste;
}	t_game;

void	validate_args(int argc, char **argv);
int		openmap(char *filename);
int		get_next_line(int fd, char **line);
// size_t	len(const char *s);
// void	ft_bzero(void *s, size_t n);
// char	*ft_strcpy(char *dest, const char *src);
// char	*ft_strdup_join(char *s, char c);
#endif
