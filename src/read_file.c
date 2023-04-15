/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:30:53 by musenov           #+#    #+#             */
/*   Updated: 2023/04/15 23:30:20 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static int	ft_word_count_fdf(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s && *(s + i) != '\0' && *(s + i) != '\n')
	{
		if (*(s + i) == c)
			i++;
		else
		{
			word_count++;
			while (*(s + i) != '\0' && *(s + i) != c)
				i++;
		}
	}
	return (word_count);
}

int	get_height(char *file_name, int *width)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	*width = ft_word_count_fdf(line, ' ');
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	fill_map_matrix(int *matrix_line, char *line)
{
	char	**row;
	int		i;

	row = ft_split(line, ' ');
	i = 0;
	while (row[i])
	{
		matrix_line[i] = ft_atoi(row[i]);
		free(row[i++]);
	}
	matrix_line[i] = '\0';
	free(row);
}

void	width_false(t_fdf *data)
{
	free_stuff(data);
	mlx_terminate(data->mlx);
	ft_error("false width of map");
}

void	read_file(char *file_name, t_fdf *data, int fd)
{
	char	*line;
	int		i;
	int		width;

	data->height = get_height(file_name, &width);
	data->width = width;
	data->map_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->map_matrix[i++] = (int *)malloc(sizeof(int) * \
		(data->width + 1));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (data->width != ft_word_count_fdf(line, ' '))
			data->width_false = 1;
		fill_map_matrix(data->map_matrix[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (data->width_false == 1)
		width_false(data);
	data->map_matrix[i] = NULL;
}
