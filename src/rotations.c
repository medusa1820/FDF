/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:27:02 by musenov           #+#    #+#             */
/*   Updated: 2023/04/13 20:04:13 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x_0(float **y, float **z, t_fdf *data)
{
	float	prev_y;
	float	prev_z;

	prev_y = **y;
	prev_z = **z;
	**y = prev_y * cos(data->rotate_angle_x) - \
		prev_z * sin(data->rotate_angle_x);
	**z = prev_y * sin(data->rotate_angle_x) + \
		prev_z * cos(data->rotate_angle_x);
}

void	rotate_y_0(float **x, float **z, t_fdf *data)
{
	float	prev_x;
	float	prev_z;

	prev_x = **x;
	prev_z = **z;
	**x = prev_x * cos(data->rotate_angle_y) + \
		prev_z * sin(data->rotate_angle_y);
	**z = -prev_x * sin(data->rotate_angle_y) + \
		prev_z * cos(data->rotate_angle_y);
}

void	rotate_z_0(float **x, float **y, t_fdf *data)
{
	float	prev_x;
	float	prev_y;

	prev_x = **x;
	prev_y = **y;
	**x = prev_x * cos(data->rotate_angle_z) - \
		prev_y * sin(data->rotate_angle_z);
	**y = prev_x * sin(data->rotate_angle_z) + \
		prev_y * cos(data->rotate_angle_z);
}
