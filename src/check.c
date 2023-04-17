/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:58:36 by musenov           #+#    #+#             */
/*   Updated: 2023/04/17 21:45:20 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
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

void	check_file(int argc, char *argv, int *fd)
{
	if (argc != 2)
		ft_error("usage: ./fdf <map_name>.fdf");
	if (check_extension(argv) != 1)
		ft_error("file extension wrong, must be <.fdf>");
	*fd = open(argv, O_RDONLY, 0);
	if (*fd <= 0)
		ft_error("file doesnt exist");
}

void	free_stuff(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->map_matrix[i++]);
	free(data->map_matrix);
	free(data);
}
