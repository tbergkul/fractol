/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:45:21 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/22 11:41:47 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "minilibx/mlx.h"
# include <stdio.h>//remove

// # define WIN_WIDTH 1280
// # define WIN_HEIGHT 720

# define COLOR_RED 16711680
# define COLOR_GREEN 65280
# define COLOR_YELLOW 16776960
# define COLOR_BLUE 255
# define COLOR_WHITE 16777215
# define COLOR_ORANGE 16742400

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_PLUS_MAIN 24
# define KEY_MINUS_MAIN 27
# define KEY_PLUS_NUM 69
# define KEY_MINUS_NUM 78
# define KEY_1 18
# define KEY_2 19
# define KEY_ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

# define KEY_F 3

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_MIDDLE 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct	s_fractol
{
	int			rowlen;
	int			rows;
	char		***nbrs;
	void		*mlx;
	void		*win;
	int			zoom;
	int			rotx;
	int			roty;
	int			scaley;
	int			scalex;
	int			startx;
	int			starty;
	// int			x1;
	// int			x2;
	// int			y1;
	// int			y2;
	int			dx;
	int			dy;
	int			incx;
	int			incy;
	int			camera;
	int			z;
	int			a;
	int			b;

	int			test;//
	int			testy;
	float		left;//
	float		top;//
	float		xside;//
	float		yside;//
	float		xscale;
	float		yscale;
	float		zr;
	float		zi;
	float		cr;
	float		ci;
	float		temp;
	int			fractol;
	int			width;
	int			height;
	int			x;
	int			y;
	float		x0;
	float		x1;
	float		y0;
	float		y1;
	void		*img;
	void		*img_str;
	int			endian;
	int			sl;
	int			bpp;
	int			i;
	int			maxi;
	int			color;
}				t_fractol;

void	draw_fractol(t_fractol *f);
void	begin(t_fractol *f);

// int		save_input(char *av, t_fractol *f);
// void	draw_twod(t_fractol *f);
// int		get_color(int z1, int z2);
// void	bresenham(t_fractol *f, int z1, int z2);
// int		window(t_fractol *f);
// int		draw(t_fractol *f);
void	draw_instructions(t_fractol *f);
int		key_pressed(int key, t_fractol *f);
int		mouse_button(int key, int x, int y, t_fractol *f);
#endif
