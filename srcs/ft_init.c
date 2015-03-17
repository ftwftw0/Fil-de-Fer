/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:02:33 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/02 18:29:25 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			continue_init(t_mlxdata *data)
{
	data->a.x = WIDTH / 3;
	data->a.y = HEIGHT / 10;
	if (data->img.ptr)
		mlx_destroy_image(data->env.mlx, data->img.ptr);
	data->img = mlx_create_image(data, WIDTH, HEIGHT, 32);
	data->color = 0x00ffffff;
	data->xdepth = WIDTH / (data->grid->columns + data->grid->table[0][0]);
	data->xdepth = (data->xdepth >= 1) ? data->xdepth : 1;
	data->ydepth = HEIGHT
		/ (data->grid->columns + data->grid->table[0][0] + data->zdepth);
	data->ydepth = (data->ydepth >= 1) ? data->ydepth : 1;
	data->zdepth = ZDEPTH;
	data->a.color = 0x00ffffff;
	data->b.x = 0;
	data->b.y = 0;
	data->b.color = 0x00ffffff;
}

unsigned int	hexstrtoi(char *str)
{
	unsigned int nb;

	nb = 0;
	if (*str == '0' && *(str + 1) == 'x')
		str = str + 2;
	else
	{
		if (ft_strlen(str) == 8)
		{
			nb += ((*str < 58) ? *str++ - 47 : *str++ - 87) << 28;
			nb += ((*str < 58) ? *str++ - 47 : *str++ - 87) << 24;
		}
		nb += ((*str < 58) ? *str++ - 47 : *str++ - 87) << 20;
		nb += ((*str < 58) ? *str++ - 47 : *str++ - 87) << 16;
		nb += ((*str < 58) ? *str++ - 47 : *str++ - 87) << 12;
		nb += ((*str < 58) ? *str++ - 47 : *str++ - 87) << 8;
		nb += ((*str < 58) ? *str++ - 47 : *str++ - 87) << 4;
		nb += ((*str < 58) ? *str++ - 47 : *str++ - 87) << 0;
	}
	return (nb);
}

int				ft_init(int argc, char **argv, t_mlxdata *data)
{
	if (argc < 2)
	{
		perror("Please set a path to a valid map ");
		return (0);
	}
	if (data->grid == NULL)
		if ((data->grid = ft_mktable(argv[1])) == NULL)
			return (0);
	if (argc == 6)
	{
		data->color1 = hexstrtoi(argv[2]);
		data->color2 = hexstrtoi(argv[3]);
		data->color3 = hexstrtoi(argv[4]);
		data->color4 = hexstrtoi(argv[5]);
	}
	else
	{
		data->color1 = 0x00ffffff;
		data->color2 = 0x00804a2d;
		data->color3 = 0x0048b427;
		data->color4 = 0x0046aeff;
	}
	continue_init(data);
	return (1);
}
