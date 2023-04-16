/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_projection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:40:54 by musenov           #+#    #+#             */
/*   Updated: 2023/04/16 15:15:00 by musenov          ###   ########.fr       */
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

void	bresenham_2D_hor(int x, int y, t_fdf *data)
{
	
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
				bresenham_2D_hor(x, y, data);
			if (y < data->height - 1)
				bresenham_2D_ver(x, y, data);
			x++;
		}
		y++;
	}
}
