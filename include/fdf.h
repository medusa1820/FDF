/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:07:02 by musenov           #+#    #+#             */
/*   Updated: 2023/04/12 22:08:16 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH
#  define WIDTH 1700
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef BPP
#  define BPP 4
# endif

# ifndef PI
#  define PI 3.141592
# endif

# include "get_next_line.h"
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_cords
{
	float		x;
	float		y;
}				t_cords;

typedef struct s_fdf
{
	mlx_t		*mlx;
	int			width;
	int			height;
	int			**map_matrix;
	t_cords		**inter_map;
	int			zoom;
	long int	color;
	mlx_image_t	*img;
	int			shift_x;
	int			shift_y;
	float		exp_shrink;
	float		amp_comp;
	float		rotate_angle_x;
	float		rotate_angle_y;
	float		rotate_angle_z;
	float		iso_angle;
	char		rotate;
	int			vertical_line;
	int			width_false;
}				t_fdf;

typedef struct s_coords
{
	float		x0;
	float		y0;
	float		x1;
	float		y1;
}				t_coords;

// draw_utils.c
int			find_max_mod_step(float a, float b);
void		put_origin(t_coords *coords, t_fdf *data);
void		put_origin_0(float x, float y, t_fdf *data);
void		translate(t_fdf *data, t_coords *coords);
void		translate_0(t_fdf *data, float *x, float *y);
void		exp_shrink(t_fdf *data, t_coords *coords);
void		exp_shrink_0(t_fdf *data, float *x, float *y);
void		rotate(t_coords *coords, t_fdf *data, float *z0, float *z1);
void		rotate_0(float *y, t_fdf *data, float *z);
// draw.c
void		isometric_projection(float *x, float *y, float z, t_fdf *data);
// void		isometric_projection_0(float *x, float *y, float z, t_fdf *data);
void		line_bresenham(t_coords *coords, t_fdf *data);
void		caller_func(float x, float y, t_fdf *data);
void		caller_func_horizontal(float x, float y, t_fdf *data);
void		caller_func_vertical(float x, float y, t_fdf *data);
void		draw(t_fdf *data);
// hook_fts.c
void		ft_hooks0(t_fdf *data);
void		ft_hooks1(t_fdf *data);
void		ft_hooks2(t_fdf *data);
void		ft_scroll(double xdelta, double ydelta, t_fdf *data);
// init_params.c
long int	z_color(int z0, int z1);
long int	zz_color(int z0);
void		default_map(t_fdf *data);
int			check_extension(char *fdf);
// main.c
void		ft_error(char *msg);
void		free_stuff(t_fdf *data);
void		print_map(t_fdf *data);
void		check_file(int argc, char *argv, int *fd);
int			main(int argc, char **argv);
// read_file.c
//			static int	ft_word_count(char const *s, char c);
int			get_height(char *file_name, int *width);
void		fill_matrix(int *z_line, char *line);
void		width_false(t_fdf *data);
void		read_file(char *file_name, t_fdf *data, int fd);
// rotations.c
void		rotate_x(float *y, float **z, t_fdf *data);
void		rotate_x_0(float **y, float **z, t_fdf *data);
void		rotate_y(float *x, float **z, t_fdf *data);
void		rotate_z(float *x, float *y, t_fdf *data);

#endif