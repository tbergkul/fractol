/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:39:09 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/04 13:59:54 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Resets the real and imaginary values to 0.
*/

void	reset_real_imaginary(t_fractol *f)
{
	f->oldr = 0;
	f->newr = 0;
	f->oldi = 0;
	f->newi = 0;
}

/*
**	Draws the burningship fractal.
*/

void	draw_burningship(t_fractol *f)
{
	while (f->y < f->max_line)
	{
		f->x = -1;
		while (++f->x < f->width)
		{
			f->cr = 1.5 * (f->x - f->width / 2) /
				(0.5 * f->zoom * f->width) + f->movex;
			f->ci = (f->y - f->height / 2) /
				(0.5 * f->zoom * f->height) + f->movey;
			reset_real_imaginary(f);
			f->i = -1;
			while (++f->i < f->maxi)
			{
				f->oldr = f->newr;
				f->oldi = f->newi;
				f->newr = abs_ld(f->oldr * f->oldr - f->oldi * f->oldi + f->cr);
				f->newi = abs_ld(2 * f->oldr * f->oldi + f->ci);
				if (f->newr * f->newr + f->newi * f->newi > 4)
					break ;
			}
			draw_pixel(f);
		}
		f->y++;
	}
}

/*
**	Draws the mandelbrot fractal.
*/

void	draw_mandelbrot(t_fractol *f)
{
	while (f->y < f->max_line)
	{
		f->x = -1;
		while (++f->x < f->width)
		{
			f->cr = 1.5 * (f->x - f->width / 2) /
				(0.5 * f->zoom * f->width) + f->movex;
			f->ci = (f->y - f->height / 2) /
				(0.5 * f->zoom * f->height) + f->movey;
			reset_real_imaginary(f);
			f->i = -1;
			while (++f->i < f->maxi)
			{
				f->oldr = f->newr;
				f->oldi = f->newi;
				f->newr = f->oldr * f->oldr - f->oldi * f->oldi + f->cr;
				f->newi = 2 * f->oldr * f->oldi + f->ci;
				if (f->newr * f->newr + f->newi * f->newi > 4)
					break ;
			}
			draw_pixel(f);
		}
		f->y++;
	}
}

/*
**	Draws the julia fractal.
*/

void	draw_julia(t_fractol *f)
{
	while (f->y < f->max_line)
	{
		f->x = -1;
		while (++f->x < f->width)
		{
			f->newr = 1.5 * (f->x - f->width / 2) /
				(0.5 * f->zoom * f->width) + f->movex;
			f->newi = (f->y - f->height / 2) /
				(0.5 * f->zoom * f->height) + f->movey;
			f->i = -1;
			while (++f->i < f->maxi)
			{
				f->oldr = f->newr;
				f->oldi = f->newi;
				f->newr = f->oldr * f->oldr - f->oldi * f->oldi + f->cr;
				f->newi = 2 * f->oldr * f->oldi + f->ci;
				if (f->newr * f->newr + f->newi * f->newi > 4)
					break ;
			}
			draw_pixel(f);
		}
		f->y++;
	}
}

/*
**	Set the window width and height, and amount of threads.
**	Establish the connection to a new window and create an image.
**	Resets values to default and the starts the drawing process.
*/

void	begin(t_fractol *f)
{
	f->width = 1300;
	f->height = 1000;
	f->threads = 50;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->width, f->height, "FRACTOL");
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	f->img_str = (int *)mlx_get_data_addr(f->img, &f->bpp, &f->sl, &f->endian);
	reset_values(f);
	fractol(f);
}
