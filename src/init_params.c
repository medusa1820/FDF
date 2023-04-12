/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:15 by musenov           #+#    #+#             */
/*   Updated: 2023/04/12 22:12:59 by musenov          ###   ########.fr       */
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

long int	zz_color(int z0)
{
	if (z0 > 0)
		return (4289344511);
	else if (z0 == 0)
		return (100);
	return (445430015);
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

int	check_extension(char *fdf)
{
	int		name_len;
	int		i;
	char	*fdf_true;

	fdf_true = ".fdf";
	name_len = ft_strlen(fdf);
	i = 0;
	while (fdf[name_len - 1 - i] == fdf_true[3 - i])
		i++;
	if (i < 4)
		return (0);
	return (1);
}

/*
True isometric projection uses a 30° angle (0.523599 rad).

2:1 isometric projection uses a 26.57° angle (0.46373398 rad).
*/