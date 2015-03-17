/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 17:09:08 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/17 14:42:38 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	if (!(data->env.mlx = mlx_init()))
		return (-1);
	data->env.window = mlx_new_window(data->env.mlx, WIDTH, HEIGHT, "FdF");
	data->av = argv;
	data->ac = argc;
	if (ft_init(argc, argv, data) == 0)
	{
		perror("Illegal map used. Please use a valid map.\nError");
		return (-1);
	}
	mlx_expose_hook(data->env.window, expose_hook, data);
	mlx_mouse_hook(data->env.window, mouse_hook, data);
	mlx_key_hook(data->env.window, key_hook, data);
	mlx_hook(data->env.window, KeyPress, KeyPressMask, keypress_hook, data);
	mlx_hook(data->env.window, MotionNotify, PointerMotionMask,
			cursor_hook, data);
	mlx_loop_hook(data->env.mlx, loop_hook, data);
	mlx_loop(data->env.mlx);
	return (1);
}

int		loop_hook(t_mlxdata *data)
{
	if (data->hooks.zzoom == 1)
		data->zdepth++;
	else if (data->hooks.zzoom == 2)
		data->zdepth--;
	mlx_destroy_image(data->env.mlx, data->img.ptr);
	data->img = mlx_create_image(data, WIDTH, HEIGHT, 32);
	expose_hook(data);
	return (1);
}

void	show_keys(t_mlxdata *data)
{
	mlx_string_put(data->env.mlx, data->env.window, 20, 20, 0xffffff,
					"Reset the map       : Space");
	mlx_string_put(data->env.mlx, data->env.window, 20, 40, 0xffffff,
					"Increase size       : +");
	mlx_string_put(data->env.mlx, data->env.window, 20, 60, 0xffffff,
					"Decrease size       : -");
	mlx_string_put(data->env.mlx, data->env.window, 20, 80, 0xffffff,
					"Increase zoom       : Mouse wheel down");
	mlx_string_put(data->env.mlx, data->env.window, 20, 100, 0xffffff,
					"Decrease zoom       : Mouse wheel up");
	mlx_string_put(data->env.mlx, data->env.window, 20, 120, 0xffffff,
					"Move the plane      : Left click or WASD");
}

int		expose_hook(t_mlxdata *data)
{
	static struct timeval	time;
	struct timeval			nowtime;
	char					*tmp;

	gettimeofday(&nowtime, NULL);
	mlx_string_put(data->env.mlx, data->env.window, WIDTH - 50, 20, 0x00ff00,
				tmp = ft_itoa((int)(1 / ((nowtime.tv_usec - time.tv_usec)
								/ 1000000.))));
	mlx_putgrid(data, data->grid);
	mlx_put_image_to_window(data->env.mlx,
							data->env.window,
							data->img.ptr,
							0, 0);
	free(tmp);
	show_keys(data);
	time = nowtime;
	return (1);
}
