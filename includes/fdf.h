/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 19:15:12 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/02 17:51:29 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI 3.141592
# define WIDTH 1600
# define HEIGHT 1200
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include </usr/X11R6/include/X11/X.h>

# define ZDEPTH 1
# define ZOOMSPEED 1
# define SPACE 32

/*
** Ajout des booleens, substitue par des chars
*/
typedef char	t_bool;

typedef struct		s_point
{
	int				x;
	int				y;
	int				color;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*window;
}					t_env;

typedef struct		s_grid
{
	int				**table;
	int				columns;
	int				top;
	int				bot;
}					t_grid;

typedef struct		s_img
{
	void			*ptr;
	t_point			size;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

/*
** Temp datas for hooks events
*/
typedef struct		s_hooks
{
	t_bool			xzoom;
	t_bool			yzoom;
	t_bool			zzoom;
	t_bool			moving;
}					t_hooks;

typedef struct		s_mlxdata
{
	t_env			env;
	t_point			a;
	t_point			b;
	t_img			img;
	t_grid			*grid;
	int				color;
	int				xdepth;
	int				ydepth;
	int				zdepth;
	t_hooks			hooks;
	int				color1;
	int				color2;
	int				color3;
	int				color4;
	char			**av;
	int				ac;
}					t_mlxdata;

int					mlx_putline(t_mlxdata *data, t_point a, t_point b);
void				swap_xy(t_point *a, t_point *b);
void				swap_points(t_point *a, t_point *b);
int					key_hook(int keycode, t_mlxdata *data);
int					mouse_hook(int button, int x, int y, t_mlxdata *data);
int					cursor_hook(int x, int y, t_mlxdata *data);
int					expose_hook(t_mlxdata *data);
int					keypress_hook(int keycode, t_mlxdata *data);
int					loop_hook(t_mlxdata *data);
int					ft_init(int argc, char **argv, t_mlxdata *data);
t_grid				*ft_mktable(char *path);
int					*ft_createline(char *str);
int					ft_countcolumns(char *str);
void				ft_puttab(t_grid *grid);
int					mlx_putgrid(t_mlxdata *data, t_grid *grid);
int					mlx_cleanwindow(t_mlxdata *data);
t_img				mlx_create_image(t_mlxdata *data,
									int xsize,
									int ysize,
									int bpp);
int					mlx_putpxl_img(t_mlxdata *data, int x, int y, int color);
void				swap_points(t_point *a, t_point *b);
void				ft_destroy(t_mlxdata *data);
#endif
