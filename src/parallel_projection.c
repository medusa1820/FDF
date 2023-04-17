/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_projection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:40:54 by musenov           #+#    #+#             */
/*   Updated: 2023/04/17 21:05:43 by musenov          ###   ########.fr       */
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
