/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putpxl_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:50:46 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/17 23:33:26 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int mlx_putpxl_img(t_mlxdata *data, int x, int y, int color)
{
	char	*imgptr;
	int		*pxl;

	if (x >= data->img.size.x || x < 0 || y < 0 || y >= data->img.size.y)
		return (0);
	imgptr = mlx_get_data_addr(data->img.ptr,
								&(data->img.bpp),
								&(data->img.sizeline),
								&(data->img.endian));
	pxl = (int*)(imgptr + y * data->img.sizeline + 4 * x);
	*pxl = color;
	data = data;
	return (1);
}
