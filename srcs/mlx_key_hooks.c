/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 23:00:30 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/02 17:50:31 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hkmove(int keycode, t_mlxdata *data)
{
	if (keycode == 119)
	{
		data->a.y -= HEIGHT / 10;
		data->b.y -= WIDTH / 10;
	}
	else if (keycode == 97)
	{
		data->a.x -= HEIGHT / 10;
		data->b.x -= WIDTH / 10;
	}
	else if (keycode == 115)
	{
		data->a.y += HEIGHT / 10;
		data->b.y += WIDTH / 10;
	}
	else if (keycode == 100)
	{
		data->a.x += HEIGHT / 10;
		data->b.x += WIDTH / 10;
	}
	else if (keycode == 61)
		data->hooks.zzoom = 0;
	else if (keycode == 45)
		data->hooks.zzoom = 0;
}

void	key_hkresize(int keycode, t_mlxdata *data)
{
	if (keycode == 105)
		data->ydepth++;
	else if (keycode == 106)
		data->xdepth++;
	else if (keycode == 107 && data->ydepth > 1)
		data->ydepth--;
	else if (keycode == 108 && data->ydepth > 1)
		data->xdepth--;
	else if (keycode == 120)
	{
		if (data->ydepth > 4)
		{
			data->ydepth /= 1.2;
			data->xdepth /= 1.2;
		}
		else if (data->ydepth > 1 && data->xdepth > 1)
		{
			data->ydepth--;
			data->xdepth--;
		}
	}
}

int		keypress_hook(int keycode, t_mlxdata *data)
{
	if (keycode == 45)
		data->hooks.zzoom = 1;
	else if (keycode == 61)
		data->hooks.zzoom = 2;
	return (1);
}

int		key_hook(int keycode, t_mlxdata *data)
{
	key_hkmove(keycode, data);
	key_hkresize(keycode, data);
	if (keycode == SPACE)
		ft_init(data->ac, data->av, data);
	else if (keycode == 50)
		mlx_clear_window(data->env.mlx, data->env.window);
	else if (keycode == 122)
	{
		if (data->ydepth > 4)
		{
			data->ydepth *= 1.2;
			data->xdepth *= 1.2;
		}
		else if (data->ydepth > 0)
		{
			data->ydepth++;
			data->xdepth++;
		}
	}
	else if (keycode == 65307)
	{
		ft_destroy(data);
		exit(0);
	}
	return (1);
}
