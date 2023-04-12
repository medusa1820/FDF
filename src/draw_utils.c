/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:33:39 by musenov           #+#    #+#             */
/*   Updated: 2023/04/12 22:00:44 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_max_mod_step(float a, float b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		return (a);
	return (b);
}

void	put_origin(t_coords *coords, t_fdf *data)
{
	coords->x0 -= data->width / 2;
	coords->y0 -= data->height / 2;
	coords->x1 -= data->width / 2;
	coords->y1 -= data->height / 2;
}

void	put_origin_0(float x, float y, t_fdf *data)
{
	x -= data->width / 2;
	y -= data->height / 2;
}

void	translate(t_fdf *data, t_coords *coords)
{
	coords->x0 += data->shift_x;
	coords->y0 += data->shift_y;
	coords->x1 += data->shift_x;
	coords->y1 += data->shift_y;
}

void	translate_0(t_fdf *data, float *x, float *y)
{
	*x += data->shift_x;
	*y += data->shift_y;
}

void	exp_shrink(t_fdf *data, t_coords *coords)
{
	coords->x0 *= data->exp_shrink;
	coords->y0 *= data->exp_shrink;
	coords->x1 *= data->exp_shrink;
	coords->y1 *= data->exp_shrink;
}

void	exp_shrink_0(t_fdf *data, float *x, float *y)
{
	*x *= data->exp_shrink;
	*y *= data->exp_shrink;
	// coords->x1 *= data->exp_shrink;
	// coords->y1 *= data->exp_shrink;
}

void	rotate(t_coords *coords, t_fdf *data, float *z0, float *z1)
{
	if (data->rotate == 'x')
	{
		rotate_x(&coords->y0, &z0, data);
		rotate_x(&coords->y1, &z1, data);
	}
	if (data->rotate == 'y')
	{
		rotate_y(&coords->x0, &z0, data);
		rotate_y(&coords->x1, &z1, data);
	}
	if (data->rotate == 'z')
	{
		rotate_z(&coords->x0, &coords->y0, data);
		rotate_z(&coords->x1, &coords->y1, data);
	}
}

// void	rotate_0(float *x, float *y, t_fdf *data, float *z)
void	rotate_0(float *y, t_fdf *data, float *z)
{
	if (data->rotate == 'x')
		rotate_x_0(&y, &z, data);
	// if (data->rotate == 'y')
	// 	rotate_y(&coords->x0, &z0, data);
	// if (data->rotate == 'z')
	// 	rotate_z(&coords->x0, &coords->y0, data);
}
