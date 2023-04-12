/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:09:30 by musenov           #+#    #+#             */
/*   Updated: 2023/04/13 00:05:14 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	free_stuff(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->map_matrix[i++]);
	free(data->map_matrix);
	i = 0;
	while (i < data->height)
		free(data->inter_map[i++]);
	free(data->inter_map);
	free(data);
}

void	print_map(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->map_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	check_file(int argc, char *argv, int *fd)
{
	if (argc != 2)
		ft_error("usage ./fdf <map_name>.fdf");
	if (check_extension(argv) != 1)
		ft_error("file extension wrong, must be <.fdf>");
	*fd = open(argv, O_RDONLY, 0);
	if (*fd <= 0)
		ft_error("file doesnt exist");
}

void	mem_alloc(t_fdf *data)
{
	int	i;

	i = 0;
	data->inter_map = (t_cords **)malloc(sizeof(t_cords *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->inter_map[i++] = (t_cords *)malloc(sizeof(t_cords) * (data->width + 1));
	data->inter_map[i] = NULL;
}

int	main(int argc, char **argv)
{
	t_fdf		*data;
	int			fd;

	check_file(argc, argv[1], &fd);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->mlx = mlx_init(WIDTH, HEIGHT, argv[1], true);
	read_file(argv[1], data, fd);
	mem_alloc(data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	// print_map(data);
	default_map(data);
	draw(data);
	mlx_loop_hook(data->mlx, (void (*)(void *))ft_hooks0, data);
	mlx_loop_hook(data->mlx, (void (*)(void *))ft_hooks1, data);
	mlx_loop_hook(data->mlx, (void (*)(void *))ft_hooks2, data);
	mlx_scroll_hook(data->mlx, (mlx_scrollfunc)ft_scroll, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_stuff(data);
	system("leaks fdf");
	return (0);
}
