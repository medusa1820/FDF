/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:41:01 by musenov           #+#    #+#             */
/*   Updated: 2023/04/06 20:10:51 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hooks0(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		default_map(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->shift_y -= 20;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->shift_y += 20;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->shift_x -= 20;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->shift_x += 20;
	if (mlx_is_key_down(data->mlx, MLX_KEY_Z))
	{
		data->rotate_angle_z += 10 * PI / 180;
		data->rotate = 'z';
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
	{
		data->rotate_angle_z -= 10 * PI / 180;
		data->rotate = 'z';
	}
	ft_memset(data->img->pixels, 0, WIDTH * HEIGHT * BPP);
	draw(data);
}

void	ft_hooks1(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_U))
		data->iso_angle += 5 * PI / 180;
	if (mlx_is_key_down(data->mlx, MLX_KEY_J))
		data->iso_angle -= 5 * PI / 180;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->amp_comp += 0.15;
	if (mlx_is_key_down(data->mlx, MLX_KEY_C))
		data->amp_comp -= 0.15;
	if (mlx_is_key_down(data->mlx, MLX_KEY_E))
	{
		data->exp_shrink += 0.1;
		printf("exp_shrink = %f\n", data->exp_shrink);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->exp_shrink -= 0.1;
		printf("exp_shrink = %f\n", data->exp_shrink);
	}
	ft_memset(data->img->pixels, 0, WIDTH * HEIGHT * BPP);
	draw(data);
}

void	ft_hooks2(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_X))
	{
		data->rotate_angle_x += 10 * PI / 180;
		data->rotate = 'x';
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_V))
	{
		data->rotate_angle_x -= 10 * PI / 180;
		data->rotate = 'x';
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_Y))
	{
		data->rotate_angle_y += 10 * PI / 180;
		data->rotate = 'y';
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_I))
	{
		data->rotate_angle_y -= 10 * PI / 180;
		data->rotate = 'y';
	}
	ft_memset(data->img->pixels, 0, WIDTH * HEIGHT * BPP);
	draw(data);
}

void	ft_scroll(double xdelta, double ydelta, t_fdf *data)
{
	(void) xdelta;
	if (ydelta > 0)
	{
		data->zoom -= 1;
		printf("Up!, zoom = %d\n", data->zoom);
	}
	else if (ydelta < 0)
	{
		data->zoom += 1;
		printf("Down!, zoom = %d\n", data->zoom);
	}
	ft_memset(data->img->pixels, 0, WIDTH * HEIGHT * BPP);
	draw(data);
}
