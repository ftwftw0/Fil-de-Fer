/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mktable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 13:16:04 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/17 15:43:36 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static void	ft_mktablenext(t_grid *grid, int *i, char *str)
{
	int **tmp;

	tmp = grid->table;
	grid->table = (int **)malloc(sizeof(int *) * ((*i) + 1));
	ft_memcpy(grid->table, tmp, sizeof(int *) * (*i));
	grid->table[(*i)++] = ft_createline(str);
	free(tmp);
	free(str);
}

t_grid		*ft_mktable(char *path)
{
	t_grid	*grid;
	char	*str;
	int		fd;
	int		i;

	if ((fd = open(path, O_RDONLY, S_IREAD)) == -1)
		return (NULL);
	i = 0;
	grid = (t_grid*)malloc(sizeof(t_grid));
	grid->table = (int **)malloc(sizeof(int *) * (i + 1));
	while ((grid->top = get_next_line(fd, &str)) >= 0 && ft_countcolumns(str))
		ft_mktablenext(grid, &i, str);
	if (grid->top == -1)
	{
		free(grid->table);
		free(grid);
		return (NULL);
	}
	free(str);
	grid->columns = i;
	close(fd);
	return (grid);
}

void		ft_puttab(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < grid->columns)
	{
		j = 0;
		while (j <= grid->table[i][0])
		{
			if (grid->table[i][j] > grid->top)
				grid->top = grid->table[i][j];
			else if (grid->table[i][j] < grid->bot)
				grid->bot = grid->table[i][j];
			ft_putnbr(grid->table[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			*ft_createline(char *str)
{
	int *tab;
	int columns;
	int i;

	if (!str || *str == '\n' || *str == '\0')
		return (NULL);
	columns = ft_countcolumns(str);
	if (*str == '\n' || columns == 0)
		return (NULL);
	tab = (int*)malloc(sizeof(int) * (columns + 1));
	i = 0;
	tab[i++] = columns;
	while (*str != '\0' && *str != '\n')
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str) || *str == '-')
			tab[i++] = ft_atoi(str);
		while (*str != '\0' && *str != '\n' && *str != ' ')
			str++;
	}
	return (tab);
}

int			ft_countcolumns(char *str)
{
	int columns;

	columns = 0;
	while (*str != '\0' && *str != '\n')
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str) || *str == '-')
			columns++;
		while (*str != '\0' && *str != '\n' && *str != ' ')
			str++;
	}
	return (columns);
}
