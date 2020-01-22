/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:53:04 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/22 14:03:41 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Get_color will calculate which color to use for the next line.
*/

int		get_color(int z1, int z2)
{
	int	z;

	z = (z2 >= z1) ? z2 : z1;
	if (z < 0)
		return (COLOR_BLUE);
	if (z == 0)
		return (COLOR_WHITE);
	if (z >= 1 && z < 5)
		return (COLOR_YELLOW);
	if (z >= 5 && z < 10)
		return (COLOR_ORANGE);
	return (COLOR_RED);
}

/*
**	The error variable (e) will determine if the next pixel
**	is on the same line or the line below. If it's on the
**	line below, e > 0, y will get incremented by 1 and the
**	error variabel will get corrected.
*/

void	m_negative(t_fractol *f, int z1, int z2)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	mlx_pixel_put(f->mlx, f->win, f->x1, f->y1, get_color(z1, z2));
	e = (2 * f->dy) - f->dx;
	inc1 = 2 * (f->dy - f->dx);
	inc2 = 2 * f->dy;
	i = -1;
	while (++i < f->dx)
	{
		if (e > 0)
		{
			f->y1 = f->y1 + f->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		f->x1 = f->x1 + f->incx;
		mlx_pixel_put(f->mlx, f->win, f->x1, f->y1, get_color(z1, z2));
	}
}

void	m_positive(t_fractol *f, int z1, int z2)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	mlx_pixel_put(f->mlx, f->win, f->x1, f->y1, get_color(z1, z2));
	e = (2 * f->dx) - f->dy;
	inc1 = 2 * (f->dx - f->dy);
	inc2 = 2 * f->dx;
	i = -1;
	while (++i < f->dy)
	{
		if (e > 0)
		{
			f->x1 = f->x1 + f->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		f->y1 = f->y1 + f->incy;
		mlx_pixel_put(f->mlx, f->win, f->x1, f->y1, get_color(z1, z2));
	}
}

/*
**	Bresenham function will calculate the distances between both
**	x-coordinates and y-coordinates and get the absolute value
**	of those distances. If dx > dy, m_negative will be called.
**	In m_negative, the x-value increases by 1 continuosly and
**	the y-value increases by 1 only when changing line.
**	In m_positive, the y-value increases by 1 continuosly and
**	the x-value increases by 1 only when changing line.
*/

void	bresenham(t_fractol *f, int z1, int z2)
{
	f->dx = f->x2 - f->x1;
	f->dy = f->y2 - f->y1;
	f->dx = abs(f->dx);
	f->dy = abs(f->dy);
	f->incx = (f->x2 > f->x1) ? 1 : -1;
	f->incy = (f->y2 > f->y1) ? 1 : -1;
	if (f->dx > f->dy)
		m_negative(f, z1, z2);
	else
		m_positive(f, z1, z2);
}

/*
**	Window will reset variabels and initiate the connection to the
**	drawing window and call the function draw to draw the 3D f.
*/

int		window(t_fractol *f)
{
	f->zoom = 0;
	f->rotx = 0;
	f->roty = 0;
	f->startx = 600;
	f->starty = 100;
	f->camera = 1;
	f->z = 0;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	draw(f);
	return (0);
}
