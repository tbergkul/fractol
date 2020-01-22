/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:12:32 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/22 14:15:57 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		coord_x(t_fractol *f, int x, int y)
{
	return (f->startx - (f->scalex * y) + (f->scalex * x));
}

/*
**	Coord_x and coord_y will return the x or y coordinates to be used
**	in the 3D f for each number in the 3D array.
*/

int		coord_y(t_fractol *f, int x, int y, int z)
{
	if (z > 25000)
		z = 25000;
	if (z < -25000)
		z = -25000;
	if (z != 0)
	{
		return (f->starty + ((f->scaley) * x) +
		((f->scaley) * y) - (z * 2 + f->z));
	}
	else
		return (f->starty + ((f->scaley) * x) + ((f->scaley) * y));
}

/*
**	Draw_y will draw the lines in the y-axis in the 3D f.
**	Will call functions coord_x and coord_y to get the coordinates
**	for the x and y values and then call the bresenham function to
**	draw the line using the calculated coordinates.
*/

void	draw_y(t_fractol *f)
{
	int	i;
	int	j;

	j = -1;
	while (++j < f->rows - 1)
	{
		i = -1;
		while (++i < f->rowlen)
		{
			f->x1 = coord_x(f, i, j);
			f->y1 = coord_y(f, i, j, ft_atoi(f->nbrs[j][i]));
			f->x2 = coord_x(f, i, j + 1);
			f->y2 = coord_y(f, i, j + 1, ft_atoi(f->nbrs[j + 1][i]));
			bresenham(f, ft_atoi(f->nbrs[j][i]),
			ft_atoi(f->nbrs[j + 1][i]));
		}
	}
}

/*
**	Draw_x will draw the lines in the x-axis in the 3D f.
**	Will call functions coord_x and coord_y to get the coordinates
**	for the x and y values and then call the bresenham function to
**	draw the line using the calculated coordinates.
*/

void	draw_x(t_fractol *f)
{
	int	i;
	int	j;

	j = -1;
	while (++j < f->rows)
	{
		i = 0;
		while (i < (f->rowlen - 1))
		{
			f->x1 = coord_x(f, i, j);
			f->y1 = coord_y(f, i, j, ft_atoi(f->nbrs[j][i]));
			i++;
			f->x2 = coord_x(f, i, j);
			f->y2 = coord_y(f, i, j, ft_atoi(f->nbrs[j][i]));
			bresenham(f, ft_atoi(f->nbrs[j][i - 1]),
			ft_atoi(f->nbrs[j][i]));
		}
	}
}

/*
**	The function draw will decide depending on the camera
**	variable if the 3D f or the 2D f should be drawn.
*/

int		draw(t_fractol *f)
{
	if (f->camera == 1)
	{
		f->scalex = 20 + f->zoom + f->rotx;
		f->scaley = 20 + f->zoom + f->roty;
		draw_x(f);
		draw_y(f);
	}
	else
	{
		f->scalex = 20 + f->zoom;
		f->scaley = 20 + f->zoom;
		f->a = f->startx;
		f->b = f->starty;
		draw_twod(f);
	}
	draw_instructions(f);
	mlx_key_hook(f->win, key_pressed, f);
	mlx_mouse_hook(f->win, mouse_button, f);
	mlx_loop(f->mlx);
	return (0);
}
