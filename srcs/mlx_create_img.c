/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:26:15 by flagoutt          #+#    #+#             */
/*   Updated: 2014/12/14 19:28:43 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img mlx_create_image(t_mlxdata *data, int xsize, int ysize, int bpp)
{
	t_img img;

	img.ptr = mlx_new_image(data->env.mlx, xsize, ysize);
	img.size.x = xsize;
	img.size.y = ysize;
	img.bpp = bpp;
	img.sizeline = (bpp / 8) * ysize;
	img.endian = 1;
	return (img);
}
