/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 07:47:48 by flagoutt          #+#    #+#             */
/*   Updated: 2015/02/25 06:41:18 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mouse_hook2(int button, int x, int y, t_mlxdata *data)
{
	x = x;
	y = y;
	if (button == 5)
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
	else if (button == 1)
		data->hooks.moving = (data->hooks.moving) ? 0 : 1;
}

int		mouse_hook(int button, int x, int y, t_mlxdata *data)
{
	x = x;
	y = y;
	if (button == 4)
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
	mouse_hook2(button, x, y, data);
	return (1);
}

int		cursor_hook(int x, int y, t_mlxdata *data)
{
	if (data->hooks.moving)
	{
		data->a.x = x;
		data->a.y = y;
	}
	return (1);
}
