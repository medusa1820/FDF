/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_projection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:40:54 by musenov           #+#    #+#             */
/*   Updated: 2023/04/17 21:02:39 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallel_x(t_fdf *data)
{
	data->zoom = 10;
	data->shift_x = 0;
	data->shift_y = 0;
	data->exp_shrink = 1;
	data->amp_comp = 1;
	data->rotate_angle_x = 0;
	data->rotate_angle_y = 0;
	data->rotate_angle_z = 315 * PI / 180;
	data->rotate = 'z';
	data->iso_angle = 0;
}

void	parallel_y(t_fdf *data)
{
	data->zoom = 10;
	data->shift_x = 0;
	data->shift_y = 0;
	data->exp_shrink = 1;
	data->amp_comp = 1;
	data->rotate_angle_x = 0;
	data->rotate_angle_y = 0;
	data->rotate_angle_z = 225 * PI / 180;
	data->rotate = 'z';
	data->iso_angle = 0;
}

void	bresenham_2d_hor(int x, int y, t_fdf *data)
{
	float	max_step;
	float	x_step;
	float	y_step;
	float	x0;
	float	y0;
	float	x1;
	float	y1;

	// x0 = x * data->zoom;
	// y0 = y * data->zoom;
	// x1 = (x + 1) * data->zoom;
	// y1 = y * data->zoom;
	x0 = x;
	y0 = y;
	x1 = x + 1;
	y1 = y;
	map_color_hor(data, y, x);
	x_step = x1 - x0;
	y_step = y1 - y0;
	max_step = find_max_mod_step(x_step, y_step);
	x_step = x_step / max_step;
	y_step = y_step / max_step;
	while ((int)(x0 - x1) || (int)(y0 - y1))
	{
		if ((x0 >= 0 && x0 < WIDTH) && (y0 >= 0 && y0 < HEIGHT))
			mlx_put_pixel(data->img, x0 * data->zoom + WIDTH / 2, y0 * data->zoom + HEIGHT / 2, data->color);
		x0 = x0 + x_step;
		y0 = y0 + y_step;
	}
}

void	bresenham_2d_ver(int x, int y, t_fdf *data)
{
	float	max_step;
	float	x_step;
	float	y_step;
	float	x0;
	float	y0;
	float	x1;
	float	y1;

	// x0 = x * data->zoom;
	// y0 = y * data->zoom;
	// x1 = x * data->zoom;
	// y1 = (y + 1) * data->zoom;
	x0 = x;
	y0 = y;
	x1 = x;
	y1 = y + 1;
	map_color_ver(data, y, x);
	x_step = x1 - x0;
	y_step = y1 - y0;
	max_step = find_max_mod_step(x_step, y_step);
	x_step = x_step / max_step;
	y_step = y_step / max_step;
	while ((int)(x0 - x1) || (int)(y0 - y1))
	{
		if ((x0 >= 0 && x0 < WIDTH) && (y0 >= 0 && y0 < HEIGHT))
			mlx_put_pixel(data->img, x0 * data->zoom + WIDTH / 2, y0 * data->zoom + HEIGHT / 2, data->color);
		x0 = x0 + x_step;
		y0 = y0 + y_step;
	}
}

void	parallel_z(t_fdf *data)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham_2d_hor(x, y, data);
			if (y < data->height - 1)
				bresenham_2d_ver(x, y, data);
			x++;
		}
		y++;
	}
}
