/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 10:22:39 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/17 23:29:01 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		swap_points(t_point *a, t_point *b)
{
	t_point tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
	(*a).color = tmp.color;
}

void		swap_xy(t_point *a, t_point *b)
{
	double tmp;

	tmp = (*b).x;
	(*b).x = (*b).y;
	(*b).y = tmp;
	tmp = (*a).x;
	(*a).x = (*a).y;
	(*a).y = tmp;
}

int			mlx_putlinetwo(t_mlxdata *data, t_point a, t_point b)
{
	int x;

	if (a.x > b.x)
		swap_points(&a, &b);
	x = a.x;
	while (x <= b.x)
	{
		mlx_putpxl_img(data, (int)x,
						(int)(a.y + ((b.y - a.y) * (x - a.x)) / (b.x - a.x)),
						a.color);
		x++;
	}
	return (1);
}

int			mlx_putline(t_mlxdata *data, t_point a, t_point b)
{
	int x;

	if (a.x > WIDTH || b.x > WIDTH || a.y > HEIGHT || b.y > HEIGHT
		|| a.x < 0 || b.x < 0 || a.y < 0 || b.y < 0)
		return (0);
	b.color = a.color;
	if (ft_abs(b.y - a.y) > ft_abs(b.x - a.x))
	{
		if (a.y > b.y)
			swap_points(&a, &b);
		swap_xy(&a, &b);
		x = a.x;
		while (x <= b.x)
		{
			mlx_putpxl_img(data,
						(int)(a.y + ((b.y - a.y) * (x - a.x)) / (b.x - a.x)),
						(int)x, a.color);
			x++;
		}
	}
	else
		mlx_putlinetwo(data, a, b);
	return (1);
}
