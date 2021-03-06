/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:27:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/05 23:58:32 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook: %d\n", keycode);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("x:%d y:%d\n",x, y);
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

void	my_mlx_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello World!");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

	for (int x=0; x < 200; x++)
	{
		my_mlx_pixelput(&img, x, 5, 0x00FF0000);
	}
	for (int x = 0; x < 200; x++)
	{
		my_mlx_pixelput(&img, 5, x, 0x00FFFF00);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	//mlx_hook(mlx_win, 33, 0, mlx_destroy_window, mlx);
	mlx_loop(vars.mlx);
}
