/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:14:33 by flagoutt          #+#    #+#             */
/*   Updated: 2015/02/26 15:12:39 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_mlxdata *data, int i, int j, int isline)
{
	if (isline)
	{
		if (data->grid->table[i][j] > 60 || data->grid->table[i][j - 1] > 60)
			data->a.color = data->color1;
		else if (data->grid->table[i][j] > 30
				|| data->grid->table[i][j - 1] > 30)
			data->a.color = data->color2;
		else if (data->grid->table[i][j] > 0 || data->grid->table[i][j - 1] > 0)
			data->a.color = data->color3;
		else
			data->a.color = data->color4;
	}
	else
	{
		if (data->grid->table[i][j] > 60 || data->grid->table[i - 1][j] > 60)
			data->a.color = data->color1;
		else if (data->grid->table[i][j] > 30
				|| data->grid->table[i - 1][j] > 30)
			data->a.color = data->color2;
		else if (data->grid->table[i][j] > 0 || data->grid->table[i - 1][j] > 0)
			data->a.color = data->color3;
		else
			data->a.color = data->color4;
	}
}

int		mlx_putlines(t_mlxdata *data, t_grid *grid)
{
	int		j;
	int		i;
	t_point	pos;

	i = 0;
	pos = data->a;
	while (i < grid->columns)
	{
		j = 1;
		data->a.x = pos.x - (i * data->xdepth);
		data->a.y = pos.y + (i * data->ydepth)
					- (data->zdepth / 5.) * grid->table[i][j];
		while (j++ < grid->table[i][0])
		{
			data->b.x = data->a.x + data->xdepth;
			data->b.y = pos.y + data->ydepth * (j + i - 1)
						- (data->zdepth / 5.) * grid->table[i][j];
			set_color(data, i, j, 1);
			mlx_putline(data, data->a, data->b);
			data->a = data->b;
		}
		i++;
	}
	data->a = pos;
	return (1);
}

int		mlx_putcolumns(t_mlxdata *data, t_grid *grid)
{
	int		i;
	int		j;
	int		nb;
	t_point pos;

	j = 0;
	nb = grid->table[0][0];
	while (++j <= nb)
	{
		i = 0;
		data->a.x = pos.x + ((j - 1) * data->xdepth);
		data->a.y = pos.y + ((j - 1) * data->ydepth)
					- (data->zdepth / 5.) * grid->table[i][j];
		while (i++ < grid->columns - 1)
		{
			data->b.x = data->a.x - data->xdepth;
			data->b.y = pos.y + data->ydepth * (i + j - 1)
						- (data->zdepth / 5.) * grid->table[i][j];
			set_color(data, i, j, 0);
			mlx_putline(data, data->a, data->b);
			data->a = data->b;
		}
	}
	data->a = pos;
	return (1);
}

int		mlx_putgrid(t_mlxdata *data, t_grid *grid)
{
	if (!grid || !data)
	{
		perror("Donnees ou grille manquante");
		return (-1);
	}
	mlx_putlines(data, grid);
	mlx_putcolumns(data, grid);
	return (1);
}
