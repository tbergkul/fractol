/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:22:10 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/05 11:09:17 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Choose which fractal to draw.
*/

void	*choose_fractal(void *temp)
{
	t_fractol	*f;

	f = temp;
	if (f->fractol == 1)
		draw_julia(f);
	else if (f->fractol == 2)
		draw_mandelbrot(f);
	else if (f->fractol == 3)
		draw_burningship(f);
	return (NULL);
}

/*
**	Create the threads, calculate where threads shall start and end
** drawing on the image. Ends by placing the image in the window.
*/

int		begin_thread(t_fractol *f)
{
	pthread_t	thread_id[f->threads];
	t_fractol	temp[f->threads];
	int			i;

	i = -1;
	while (++i < f->threads)
	{
		ft_memcpy((void*)&temp[i], (void*)f, sizeof(t_fractol));
		temp[i].y = i * (f->height / f->threads);
		temp[i].max_line = (i + 1) * (f->height / f->threads);
		pthread_create(&thread_id[i], NULL, choose_fractal, &temp[i]);
	}
	while (i--)
		pthread_join(thread_id[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

/*
**	Create the threads and draw the image. Then draws the instructions
**	on screen. Check for different inputs from the user.
*/

void	fractol(t_fractol *f)
{
	begin_thread(f);
	draw_instructions(f);
	mlx_hook(f->win, 2, 0, key_pressed, f);
	mlx_mouse_hook(f->win, mouse_button, f);
	mlx_hook(f->win, 6, 0, mouse_move, f);
	mlx_loop(f->mlx);
}
