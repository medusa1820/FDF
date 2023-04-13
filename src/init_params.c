/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:15 by musenov           #+#    #+#             */
/*   Updated: 2023/04/13 22:28:07 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long int	z_color(int z0, int z1)
{
	if ((z0 > 0 && z1 >= 0) || (z0 >= 0 && z1 > 0))
		return (4289344511);
	else if (z0 == 0 && z1 == 0)
		return (100);
	return (445430015);
}

long int	zz_color(int z)
{
	if (z > 0)
		return (4289344511);
	else if (z == 0)
		return (100);
	else
		return (445430015);
}

void	put_origin_0(float *x, float *y, t_fdf *data)
{
	*x -= data->width / 2;
	*y -= data->height / 2;
}

void	default_map(t_fdf *data)
{
	data->zoom = 10;
	data->shift_x = 0;
	data->shift_y = 0;
	data->exp_shrink = 1;
	data->amp_comp = 1;
	data->rotate_angle_x = 0;
	data->rotate_angle_y = 0;
	data->rotate_angle_z = 0;
	data->iso_angle = 0.46365;
}

/*
True isometric projection uses a 30° angle (0.523599 rad).

2:1 isometric projection uses a 26.57° angle (0.46373398 rad).
*/