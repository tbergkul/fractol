/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:28 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/04 14:05:19 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Draw_instructions will draw the instructions how to navigate/use
**	the program.
*/

void	draw_instructions(t_fractol *f)
{
	mlx_string_put(f->mlx, f->win, 20, 20, GREEN, "Move: Arrow keys");
	mlx_string_put(f->mlx, f->win, 20, 40, GREEN, "Zoom: Scroll wheel");
	mlx_string_put(f->mlx, f->win, 20, 60, GREEN, "Change fractol: F");
	mlx_string_put(f->mlx, f->win, 20, 80, GREEN,
		"+ - iterations: Left & right click");
	mlx_string_put(f->mlx, f->win, 20, 100, GREEN,
		"Change color: Middle mouse button");
	mlx_string_put(f->mlx, f->win, 20, 120, GREEN,
		"Unlock/Lock mouse in Julia: X");
	mlx_string_put(f->mlx, f->win, 20, 140, GREEN, "Quit: ESC");
}

/*
**	The function Mouse_move will change the cr and ci values
**	depending on where the mouse cursor is on the screen.
**	Bottom of the screen will change the ci value and top
**	of the screen will change the cr value.
*/

int		mouse_move(int x, int y, t_fractol *f)
{
	if (f->mouse_move == 1)
	{
		if (x < f->width / 2 && y < f->height / 2)
			f->cr -= 0.005;
		if (x > f->width / 2 && y < f->height / 2)
			f->cr += 0.005;
		if (x < f->width / 2 && y > f->height / 2)
			f->ci -= 0.005;
		if (x > f->width / 2 && y > f->height / 2)
			f->ci += 0.005;
		fractol(f);
	}
	return (0);
}

/*
**	mouse_button function will determine which button was used
**	and act accordingly.
*/

int		mouse_button(int key, int x, int y, t_fractol *f)
{
	x = y;
	if (key == MOUSE_LEFT)
		f->maxi += 1;
	else if (key == MOUSE_RIGHT)
	{
		if (f->maxi > 2)
			f->maxi -= 1;
	}
	else if (key == MOUSE_MIDDLE)
		f->color += 265;
	else if (key == MOUSE_SCROLL_UP)
		f->zoom *= 0.80;
	else if (key == MOUSE_SCROLL_DOWN)
		f->zoom *= 1.20;
	fractol(f);
	return (0);
}

/*
**	Key_pressed function will determine which key was pressed
**	and act accordingly.
*/

int		key_pressed(int key, t_fractol *f)
{
	if (key == ARROW_UP)
		f->movey -= 0.15 / f->zoom;
	else if (key == ARROW_DOWN)
		f->movey += 0.15 / f->zoom;
	else if (key == ARROW_LEFT)
		f->movex -= 0.15 / f->zoom;
	else if (key == ARROW_RIGHT)
		f->movex += 0.15 / f->zoom;
	else if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_X)
		f->mouse_move = f->mouse_move == 0 ? 1 : 0;
	else if (key == KEY_F)
	{
		f->fractol = f->fractol == 3 ? 1 : ++f->fractol;
		reset_values(f);
	}
	fractol(f);
	return (0);
}
