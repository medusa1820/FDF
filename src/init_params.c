/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:15 by musenov           #+#    #+#             */
/*   Updated: 2023/04/16 14:53:19 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long int	color(int z)
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

void	map_color_hor(t_fdf *data, int y, int x)
{
	if (data->inter_map[y][x].color == 4289344511 || \
		data->inter_map[y][x + 1].color == 4289344511)
		data->color = 4289344511;
	if (data->inter_map[y][x].color == 445430015 || \
		data->inter_map[y][x + 1].color == 445430015)
		data->color = 445430015;
}

void	map_color_ver(t_fdf *data, int y, int x)
{
	if (data->inter_map[y][x].color == 4289344511 || \
		data->inter_map[y + 1][x].color == 4289344511)
		data->color = 4289344511;
	if (data->inter_map[y][x].color == 445430015 || \
		data->inter_map[y + 1][x].color == 445430015)
		data->color = 445430015;
}

/*
True isometric projection uses a 30° angle (0.523599 rad).

2:1 isometric projection uses a 26.57° angle (0.46373398 rad).
*/
