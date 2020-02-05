/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:45:21 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/04 13:52:54 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "minilibx/mlx.h"
# include <pthread.h>

# define GREEN 65280

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

# define KEY_X 7
# define KEY_F 3
# define KEY_ESC 53

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_MIDDLE 3
# define MOUSE_SCROLL_DOWN 4
# define MOUSE_SCROLL_UP 5

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_str;
	int			endian;
	int			sl;
	int			bpp;
	int			fractol;
	int			width;
	int			height;
	long double	oldr;
	long double	newr;
	long double	oldi;
	long double	newi;
	long double	cr;
	long double	ci;
	long double	movex;
	long double	movey;
	long double	zoom;
	int			x;
	int			y;
	int			i;
	int			maxi;
	int			color;
	int			threads;
	int			max_line;
	int			mouse_move;
}				t_fractol;

int				mouse_move(int x, int y, t_fractol *f);
void			fractol(t_fractol *f);
void			draw_burningship(t_fractol *f);
void			draw_mandelbrot(t_fractol *f);
void			draw_julia(t_fractol *f);
int				begin_thread(t_fractol *f);
void			draw_pixel(t_fractol *f);
long double		abs_ld(long double n);
void			reset_values(t_fractol *f);
void			begin(t_fractol *f);
void			draw_instructions(t_fractol *f);
int				key_pressed(int key, t_fractol *f);
int				mouse_button(int key, int x, int y, t_fractol *f);

#endif
