/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:07:02 by musenov           #+#    #+#             */
/*   Updated: 2023/04/13 22:28:14 by musenov          ###   ########.fr       */
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
}				t_coords;

typedef struct s_inter_coords
{
	float		x_step;
	float		y_step;
}				t_inter_coords;

typedef struct s_fdf
{
	mlx_t			*mlx;
	int				width;
	int				height;
	int				**map_matrix;
	t_coords		**inter_map;
	t_inter_coords	inter_coords;
	int				zoom;
	long int		color;
	mlx_image_t		*img;
	int				shift_x;
	int				shift_y;
	float			exp_shrink;
	float			amp_comp;
	float			rotate_angle_x;
	float			rotate_angle_y;
	float			rotate_angle_z;
	float			iso_angle;
	char			rotate;
	int				vertical_line;
	int				width_false;
}					t_fdf;

// check.c
void		ft_error(char *msg);
int			check_extension(char *fdf);
void		check_file(int argc, char *argv, int *fd);

// draw_utils.c
int			find_max_mod_step(float a, float b);
void		rotate_0(float *x, float *y, t_fdf *data, float *z);
void		exp_shrink_0(t_fdf *data, float *x, float *y);
void		isometric_projection(float *x, float *y, float z, t_fdf *data);
void		translate_0(t_fdf *data, float *x, float *y);

// draw.c
void		bresenham_hor(int x, int y, t_fdf *data);
void		bresenham_ver(int x, int y, t_fdf *data);
void		draw_bresenham(t_fdf *data);
void		caller_func(float x, float y, t_fdf *data);
void		draw(t_fdf *data);

// hook_fts.c
void		ft_hooks0(t_fdf *data);
void		ft_hooks1(t_fdf *data);
void		ft_hooks2(t_fdf *data);
void		ft_scroll(double xdelta, double ydelta, t_fdf *data);

// init_params.c
long int	z_color(int z0, int z1);
long int	zz_color(int z);
void		put_origin_0(float *x, float *y, t_fdf *data);
void		default_map(t_fdf *data);

// main.c
void		free_stuff(t_fdf *data);
void		print_map(t_fdf *data);
void		mem_alloc(t_fdf *data);
int			main(int argc, char **argv);

// read_file.c
int			get_height(char *file_name, int *width);
void		fill_map_matrix(int *matrix_line, char *line);
void		width_false(t_fdf *data);
void		read_file(char *file_name, t_fdf *data, int fd);

// rotations.c
void		rotate_x_0(float **y, float **z, t_fdf *data);
void		rotate_y_0(float **x, float **z, t_fdf *data);
void		rotate_z_0(float **x, float **y, t_fdf *data);

#endif