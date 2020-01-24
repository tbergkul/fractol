/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:39:09 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/24 16:40:11 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_ted(t_fractol *f)
{
	ft_putendl("Ted");
	f->test = 1;
}

void	draw_julia(t_fractol *f)
{
	ft_putendl("Julia");
	f->test = 1;
}

void	draw_pixel(t_fractol *f)
{
	if (f->i == f->maxi)
		f->color = mlx_get_color_value(f->mlx, 0);
	else
		f->color = mlx_get_color_value(f->mlx, (f->i * 1100000));
	ft_memmove(f->img_str + (4 * (f->width * f->y)) + (f->x * 4), &f->color, sizeof(int));
}

void	draw_mandelbrot(t_fractol *f)
{
	ft_putendl("Mandelbrot");
	f->y = -1;
	while (++f->y < f->height)
	{
		f->x = -1;
		while (++f->x < f->width)
		{
			f->cr = f->x / f->zoom + f->x0;
			f->ci = f->y / f->zoom + f->y0;
			//f->cr = f->x * f->xscale + f->x0;//c_real
			//f->ci = f->y * f->yscale + f->y0;//c_imaginary
			f->zr = 0;//z_real
			f->zi = 0;//z_imaginary
			f->i = 0;
			while ((f->zr * f->zr + f->zi * f->zi < 4) && f->i < 30)
			{
				f->temp = f->zr;
				f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
				f->zi = 2 * f->temp * f->zi + f->ci;
				f->i++;
				// f->temp = f->zr * f->zr - f->zi * f->zi + f->cr;
				// f->zi = 2 * f->zr * f->zi + f->ci;
				// f->zr = f->temp;
			}
			draw_pixel(f);
			//if (x > 300 || x <= 1)
			//mlx_pixel_put(f->mlx, f->win, x, y, COLOR_RED);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	draw_fractol(t_fractol *f)
{
	if (f->fractol == 1)
		draw_julia(f);
	else if (f->fractol == 2)
		draw_mandelbrot(f);
	else if (f->fractol == 3)
		draw_ted(f);
	draw_instructions(f);
	mlx_key_hook(f->win, key_pressed, f);
	mlx_mouse_hook(f->win, mouse_button, f);
	mlx_loop(f->mlx);
}

void	begin(t_fractol *f)
{
	f->width = 1280;
	f->height = 720;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->width, f->height, "FRACTOL");
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	f->img_str = mlx_get_data_addr(f->img, &f->bpp, &f->sl, &f->endian);
	draw_fractol(f);
}
