/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:28 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/23 16:13:08 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Draw_instructions will draw the instructions how to navigate/use
**	the program.
*/

void	draw_instructions(t_fractol *f)
{
	mlx_string_put(f->mlx, f->win, 20, 20, COLOR_GREEN, "Quit: ESC");
	mlx_string_put(f->mlx, f->win, 20, 40, COLOR_GREEN, "Move: W A S D");
	mlx_string_put(f->mlx, f->win, 20, 60, COLOR_GREEN, "Zoom: Scroll wheel");
	if (f->camera == 1)
	{
		mlx_string_put(f->mlx, f->win, 20, 80,
			COLOR_GREEN, "Rotate: Arrows");
		mlx_string_put(f->mlx, f->win, 20, 100,
			COLOR_GREEN, "Adjust z: Q E");
	}
}

int		key_pressed_three(int key, t_fractol *f)
{
	if (key == KEY_1)
	{
		f->startx = 600;
		f->starty = 100;
		f->camera = 1;
	}
	else if (key == KEY_2)
	{
		f->startx = 450;
		f->starty = 150;
		f->camera = 2;
	}
	f->zoom = 0;
	f->rotx = 0;
	f->roty = 0;
	f->z = 0;
	mlx_clear_window(f->mlx, f->win);
	//draw(f);
	fractol(f);
	return (0);
}

int		key_pressed_two(int key, t_fractol *f)
{
	if (key == KEY_PLUS_MAIN || key == KEY_PLUS_NUM)
		f->zoom += 3;
	else if (key == KEY_MINUS_MAIN || key == KEY_MINUS_NUM)
	{
		if (f->zoom > -18)
			f->zoom -= 3;
	}
	else if (key == KEY_ESC)
		exit(0);
	else
		return (key_pressed_three(key, f));
	mlx_clear_window(f->mlx, f->win);
	//draw(f);
	fractol(f);
	return (0);
}

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
			{
				mlx_pixel_put(f->mlx, f->win, x, y++, COLOR_BLUE);
			}
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
	//draw(f);
	fractol(f);
	return (0);
}

/*
**	Key_pressed functions will determine which key was pressed
**	and act accordingly.
*/

int		key_pressed(int key, t_fractol *f)
{
	if (key == ARROW_UP)
		f->starty -= 30;
	else if (key == ARROW_LEFT)
		f->startx -= 30;
	else if (key == ARROW_DOWN)
		f->starty += 30;
	else if (key == ARROW_RIGHT)
		f->startx += 30;
	else if (key == KEY_W)
		f->roty += 5;
	else if (key == KEY_S)
		f->roty -= 5;
	else if (key == KEY_A)
		f->rotx += 5;
	else if (key == KEY_D)
		f->rotx -= 5;
	else if (key == KEY_Q)
		f->z += 10;
	else if (key == KEY_E)
		f->z -= 10;
	else
		return (key_pressed_two(key, f));
	mlx_clear_window(f->mlx, f->win);
	//draw(f);
	fractol(f);
	return (0);
}
