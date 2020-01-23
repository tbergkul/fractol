/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:39:09 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/23 16:20:47 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol(t_fractol *f)
{
	int	x;
	int	y;
	// int	maxx;
	// int	maxy;
	int	count;

	// f->camera = 2;
	// f->mlx = mlx_init();
	// f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "FRACTOL");
	// f->left = -1.75;
	// f->top = -0.25;
	// f->xside = 0.25;
	// f->yside = 0.45;

	// maxx = WIN_WIDTH;
	// maxy = WIN_HEIGHT;

	f->xscale = f->xside / f->maxx;
	f->yscale = f->yside / f->maxy;

	//calling rectangle function
	//where required image will be seen
	//rectangle(0, 0, maxx, maxy);

	y = -1;
	while (++y <= f->maxy - 1)
	{
		x = -1;
		while (++x <= f->maxx - 1)
		{
			f->cx = x * f->xscale + f->left;//c_real
			f->cy = y * f->yscale + f->top;//c_imaginary
			f->zx = 0;//z_real
			f->zy = 0;//z_imaginary
			count = 0;
			while ((f->zx * f->zx + f->zy * f->zy < 4) && (count < 30))
			{
				f->tempx = f->zx * f->zx - f->zy * f->zy + f->cx;
				f->zy = 2 * f->zx * f->zy + f->cy;
				f->zx = f->tempx;
				count += 1;
			}
			if (x > 300 || x <= 1)
				mlx_pixel_put(f->mlx, f->win, x, y, COLOR_RED);
		}
	}
	draw_instructions(f);
	mlx_key_hook(f->win, key_pressed, f);
	mlx_mouse_hook(f->win, mouse_button, f);
	mlx_loop(f->mlx);
}

void	begin(t_fractol *f)
{
	f->camera = 2;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "FRACTOL");
	f->left = -1.75;
	f->top = -0.25;
	f->xside = 0.25;
	f->yside = 0.45;
	f->maxx = WIN_WIDTH;
	f->maxy = WIN_HEIGHT;
	fractol(f);
}
