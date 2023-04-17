/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:47:50 by musenov           #+#    #+#             */
/*   Updated: 2023/04/17 20:14:57 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_hor(int x, int y, t_fdf *data)
{
	float	max_step;
	float	x0;
	float	y0;
	float	x1;
	float	y1;

	x0 = data->inter_map[y][x].x;
	y0 = data->inter_map[y][x].y;
	x1 = data->inter_map[y][x + 1].x;
	y1 = data->inter_map[y][x + 1].y;
	data->color = 100;
	map_color_hor(data, y, x);
	data->inter_coords.x_step = x1 - x0;
	data->inter_coords.y_step = y1 - y0;
	max_step = find_max_mod_step(data->inter_coords.x_step, \
								data->inter_coords.y_step);
	data->inter_coords.x_step = data->inter_coords.x_step / max_step;
	data->inter_coords.y_step = data->inter_coords.y_step / max_step;
	while ((int)(x0 - x1) || (int)(y0 - y1))
	{
		if ((x0 > 0 && x0 < WIDTH) && (y0 > 0 && y0 < HEIGHT))
			mlx_put_pixel(data->img, x0, y0, data->color);
		x0 = x0 + data->inter_coords.x_step;
		y0 = y0 + data->inter_coords.y_step;
	}
}

void	bresenham_ver(int x, int y, t_fdf *data)
{
	float	max_step;
	float	x0;
	float	y0;
	float	x1;
	float	y1;

	x0 = data->inter_map[y][x].x;
	y0 = data->inter_map[y][x].y;
	x1 = data->inter_map[y + 1][x].x;
	y1 = data->inter_map[y + 1][x].y;
	data->color = 100;
	map_color_ver(data, y, x);
	data->inter_coords.x_step = x1 - x0;
	data->inter_coords.y_step = y1 - y0;
	max_step = find_max_mod_step(data->inter_coords.x_step, \
								data->inter_coords.y_step);
	data->inter_coords.x_step = data->inter_coords.x_step / max_step;
	data->inter_coords.y_step = data->inter_coords.y_step / max_step;
	while ((int)(x0 - x1) || (int)(y0 - y1))
	{
		if ((x0 > 0 && x0 < WIDTH) && (y0 > 0 && y0 < HEIGHT))
			mlx_put_pixel(data->img, x0, y0, data->color);
		x0 = x0 + data->inter_coords.x_step;
		y0 = y0 + data->inter_coords.y_step;
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
				bresenham_hor(x, y, data);
			if (y < data->height - 1)
				bresenham_ver(x, y, data);
			x++;
		}
		y++;
	}
}

void	caller_func(float x, float y, t_fdf *data)
{
	float	z;
	int		orig_x;
	int		orig_y;

	orig_x = (int)x;
	orig_y = (int)y;
	z = data->map_matrix[orig_y][orig_x] * data->amp_comp;
	data->inter_map[orig_y][orig_x].color = color(z);
	put_origin_0(&x, &y, data);
	rotate_0(&x, &y, data, &z);
	exp_shrink_0(data, &x, &y);
	isometric_projection(&x, &y, z, data);
	translate_0(data, &x, &y);
	data->inter_map[orig_y][orig_x].x = x;
	data->inter_map[orig_y][orig_x].y = y;
}

void	draw(t_fdf *data)
{
	int			x;
	int			y;

	if (data->parallel_z == 1)
		parallel_z(data);
	else
	{
		y = 0;
		while (y < data->height)
		{
			x = 0;
			while (x < data->width)
			{
				caller_func(x, y, data);
				x++;
			}
			y++;
		}
		draw_bresenham(data);
	}
}
