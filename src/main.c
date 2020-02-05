/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:19:08 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/04 14:05:10 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Returns the absolute value of the long double value
**	passed to the function.
*/

long double	abs_ld(long double n)
{
	return (n < 0 ? -n : n);
}

/*
**	Draws the pixel with a color depending on the fractol drawn.
**	The pixel will be black if f->i == f->maxi.
*/

void		draw_pixel(t_fractol *f)
{
	if (f->i == f->maxi)
		f->img_str[f->y * f->width + f->x] = 0;
	else
		f->img_str[f->y * f->width + f->x] = f->color * f->i;
}

/*
**	Resets the "default" values each time the a new fractol
**	is going to be drawn.
*/

void		reset_values(t_fractol *f)
{
	if (f->fractol == 1)
	{
		f->color = 1800000;
		f->cr = -1.076;
		f->ci = 0.267000;
		f->movex = 0;
		f->movey = 0;
		f->maxi = 50;
		f->mouse_move = 0;
	}
	else if (f->fractol == 2)
	{
		f->color = 1795;
		f->movex = -0.70;
		f->movey = 0;
		f->maxi = 50;
	}
	else if (f->fractol == 3)
	{
		f->color = 9830400;
		f->movex = -0.55;
		f->movey = -0.50;
		f->maxi = 50;
	}
	f->zoom = 1;
}

/*
**	Verify_param checks if the parameter passed to the program
**	is valid or not and sets the variable f->fractol to either
**	1, 2 or 3 depending on which fractol was chosen.
*/

int			verify_param(t_fractol *f, char *parameter)
{
	if (ft_strcmp(parameter, "julia") == 0)
		f->fractol = 1;
	else if (ft_strcmp(parameter, "mandelbrot") == 0)
		f->fractol = 2;
	else if (ft_strcmp(parameter, "burningship") == 0)
		f->fractol = 3;
	else
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	t_fractol	*f;

	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	if (ac != 2 || verify_param(f, av[1]) == 0)
	{
		ft_putendl("\033[36musage: ./fractol parameter\n");
		ft_putendl("\033[33mAvailable parameters:\n");
		ft_putendl("\033[35m-> julia\n\033[32m-> mandelbrot");
		ft_putendl("\033[34m-> burningship\n");
		exit(1);
	}
	begin(f);
	return (0);
}
