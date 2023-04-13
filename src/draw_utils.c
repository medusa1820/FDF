/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:33:39 by musenov           #+#    #+#             */
/*   Updated: 2023/04/13 21:50:49 by musenov          ###   ########.fr       */
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

void	rotate_0(float *x, float *y, t_fdf *data, float *z)
{
	if (data->rotate == 'x')
		rotate_x_0(&y, &z, data);
	if (data->rotate == 'y')
		rotate_y_0(&x, &z, data);
	if (data->rotate == 'z')
		rotate_z_0(&x, &y, data);
}

void	exp_shrink_0(t_fdf *data, float *x, float *y)
{
	*x *= data->exp_shrink;
	*y *= data->exp_shrink;
}

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

void	translate_0(t_fdf *data, float *x, float *y)
{
	*x += data->shift_x;
	*y += data->shift_y;
}
