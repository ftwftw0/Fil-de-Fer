/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 17:14:00 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/02 17:37:47 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_destroy(t_mlxdata *data)
{
	int i;

	i = 0;
	while (i < data->grid->columns)
		free(data->grid->table[i++]);
	free(data->grid->table);
	mlx_destroy_image(data->env.mlx, data->img.ptr);
	mlx_destroy_window(data->env.mlx, data->env.window);
	free(data->grid);
	free(data->env.mlx);
	free(data);
}
