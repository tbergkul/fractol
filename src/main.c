/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:19:08 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/24 16:40:15 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_julia(t_fractol *f)
{
	// f->left = -1.75;
	// f->top = -0.25;
	// f->xside = 0.25;
	// f->yside = 0.45;

	// f->x0 = -1.75;
	// f->y0 = -0.25;
	// f->x1 = 0.25;
	// f->y1 = 0.45;

	f->x0 = -5.5;
	f->y0 = -3.25;
	f->x1 = 2.5;
	f->y1 = 3;

	f->maxi = 30;
	f->zoom = 150;

	f->xscale = f->x1 / f->width;
	f->yscale = f->y1 / f->height;
}

int		verify_param(t_fractol *f, char *parameter)
{
	if (ft_strcmp(parameter, "Julia") == 0)
	{
		f->fractol = 1;
		set_julia(f);
	}
	else if (ft_strcmp(parameter, "Mandelbrot") == 0)
	{
		f->fractol = 2;
	}
	else if (ft_strcmp(parameter, "Ted") == 0)
	{
		f->fractol = 3;
	}
	else
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_fractol	*f;

	system("clear");
	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	if (ac != 2 || verify_param(f, av[1]) == 0)
	{
		ft_putendl("usage: ./fractol parameter\n");
		ft_putendl("Available parameters:\n-> Julia\n-> Mandelbrot\n-> Ted\n");
		exit(1);
	}
	begin(f);
	return (0);
}
