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

# define COLOR_RED 16711680
# define COLOR_GREEN 65280
# define COLOR_YELLOW 16776960
# define COLOR_BLUE 255
# define COLOR_WHITE 16777215
# define COLOR_ORANGE 16742400

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
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_str;
	int			endian;
	int			sl;
	int			bpp;

	int			test;//
	int			testy;//

	float		left;//
	float		top;//
	float		xside;//
	float		yside;//
	float		xscale;//
	float		yscale;//
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
	int			i;
	int			maxi;
	int			color;
	int			zoom;
}				t_fractol;

void	begin(t_fractol *f);
void	draw_fractol(t_fractol *f);
void	draw_instructions(t_fractol *f);
int		key_pressed(int key, t_fractol *f);
int		mouse_button(int key, int x, int y, t_fractol *f);
#endif
