/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:28 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/27 11:59:41 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Draw_instructions will draw the instructions how to navigate/use
**	the program.
*/

void	draw_instructions(t_fractol *f)
{
	mlx_string_put(f->mlx, f->win, 20, 20, COLOR_GREEN, "Move: Arrow keys");
	mlx_string_put(f->mlx, f->win, 20, 40, COLOR_GREEN, "Zoom: Scroll wheel");
	mlx_string_put(f->mlx, f->win, 20, 60, COLOR_GREEN, "Change fractol: F");
	mlx_string_put(f->mlx, f->win, 20, 80, COLOR_GREEN, "Quit: ESC");
}

/*
**	mouse_button function will determine which button was used
**	and act accordingly.
*/

int		mouse_button(int key, int x, int y, t_fractol *f)
{
	if (key == MOUSE_LEFT)
	{
		//printf("left mouse button\nx = %d\ny = %d\n", x, y);
		f->test = x + 20;
		f->testy = y + 20;
		while (x < f->test)
		{
			y = f->testy - 20;
			while (y < f->testy)
				mlx_pixel_put(f->mlx, f->win, x, y++, COLOR_BLUE);
			x++;
		}
	}
	else if (key == MOUSE_RIGHT)
		f->test = 2;
	else if (key == MOUSE_MIDDLE)
		f->test = 3;
	else if (key == MOUSE_SCROLL_UP)
		f->zoom += 3;
	else if (key == MOUSE_SCROLL_DOWN)
	{
		if (f->zoom > -18)
			f->zoom -= 3;
	}
	mlx_clear_window(f->mlx, f->win);
	draw_fractol(f);
	return (0);
}

/*
**	Key_pressed function will determine which key was pressed
**	and act accordingly.
*/

int		key_pressed(int key, t_fractol *f)
{
	if (key == ARROW_UP)
		f->test -= 30;
	else if (key == ARROW_LEFT)
		f->test -= 30;
	else if (key == ARROW_DOWN)
		f->test += 30;
	else if (key == ARROW_RIGHT)
		f->test += 30;
	else if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_F)
	{
		if (f->fractol == 3)
			f->fractol = 1;
		else
			f->fractol += 1;
	}
	else
	{
		printf("key = %d\n", key);
		return (0);
	}
	mlx_clear_window(f->mlx, f->win);
	draw_fractol(f);
	return (0);
}
