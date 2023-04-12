/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:47:50 by musenov           #+#    #+#             */
/*   Updated: 2023/04/12 23:34:06 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(float *x, float *y, float z, t_fdf *data)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = ((prev_x - prev_y) * cos(data->iso_angle)) * data->zoom \
	+ WIDTH / 2;
	*y = ((prev_x + prev_y) * sin(data->iso_angle) - z) * data->zoom \
	+ HEIGHT / 2;
}

// void	line_bresenham(t_coords *coords, t_fdf *data)
// {
// 	float	x_step;
// 	float	y_step;
// 	float	max_step;

// 	x_step = coords->x1 - coords->x0;
// 	y_step = coords->y1 - coords->y0;
// 	max_step = find_max_mod_step(x_step, y_step);
// 	x_step = x_step / max_step;
// 	y_step = y_step / max_step;
// 	while ((int)(coords->x0 - coords->x1) || (int)(coords->y0 - coords->y1))
// 	{
// 		if ((coords->x0 > 0 && coords->x0 < WIDTH) && \
// 			(coords->y0 > 0 && coords->y0 < HEIGHT))
// 			mlx_put_pixel(data->img, coords->x0, coords->y0, data->color);
// 		coords->x0 = coords->x0 + x_step;
// 		coords->y0 = coords->y0 + y_step;
// 	}
// }

void	bresenham_hor(int x, int y, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max_step;
	float	x0;
	float	y0;
	float	x1;
	float	y1;

	x0 = data->inter_map[y][x].x;
	y0 = data->inter_map[y][x].y;
	x1 = data->inter_map[y][x + 1].x;
	y1 = data->inter_map[y][x + 1].y;

	x_step = x1 - x0;
	y_step = y1 - y0;
	max_step = find_max_mod_step(x_step, y_step);
	x_step = x_step / max_step;
	y_step = y_step / max_step;
	while ((int)(x0 - x1) || (int)(y0 - y1))
	{
		if ((x0 > 0 && x0 < WIDTH) && (y0 > 0 && y0 < HEIGHT))
			mlx_put_pixel(data->img, x0, y0, data->color);
		x0 = x0 + x_step;
		y0 = y0 + y_step;
	}
}

void	bresenham_ver(int x, int y, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max_step;
	float	x0;
	float	y0;
	float	x1;
	float	y1;

	x0 = data->inter_map[y][x].x;
	y0 = data->inter_map[y][x].y;
	x1 = data->inter_map[y + 1][x].x;
	y1 = data->inter_map[y + 1][x].y;

	x_step = x1 - x0;
	y_step = y1 - y0;
	max_step = find_max_mod_step(x_step, y_step);
	x_step = x_step / max_step;
	y_step = y_step / max_step;
	while ((int)(x0 - x1) || (int)(y0 - y1))
	{
		if ((x0 > 0 && x0 < WIDTH) && (y0 > 0 && y0 < HEIGHT))
			mlx_put_pixel(data->img, x0, y0, data->color);
		x0 = x0 + x_step;
		y0 = y0 + y_step;
	}
}

void	draw_bresenham(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				// bresenham(x, y, x + 1, y, data);
				bresenham_hor(x, y, data);
			if (y < data->height - 1)
				// bresenham(x, y, x, y + 1, data);
				bresenham_ver(x, y, data);
			x++;
		}
		y++;
	}
}

///////////////////////////////////////////////////////////////////////////

void	caller_func(float x, float y, t_fdf *data)
{
	float		z;
	int			orig_x;
	int			orig_y;

	orig_x = (int)x;
	orig_y = (int)y;
	z = data->map_matrix[(int)y][(int)x] * data->amp_comp;
	data->color = zz_color(z);
	put_origin_0(x, y, data);
	// rotate_0(&x, &y, data, &z);
	rotate_0(&y, data, &z);
	exp_shrink_0(data, &x, &y);
	isometric_projection(&x, &y, z, data);
	translate_0(data, &x, &y);
	data->inter_map[orig_y][orig_x].x = x;
	data->inter_map[orig_y][orig_x].y = y;
	// line_bresenham(coords, data);
}

void	draw(t_fdf *data)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			caller_func(x, y, data);
			/*if (x < data->width - 1)
			{
				// data->vertical_line = 0;
				// caller_func(x, y, data);
				caller_func_horizontal(x, y, data);
			}
			if (y < data->height - 1)
			{
				// data->vertical_line = 1;
				// caller_func(x, y, data);
				caller_func_vertical(x, y, data);
			}*/
			
			x++;
		}
		y++;
	}
	draw_bresenham(data);
}
