/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:56:06 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/16 23:12:24 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERR_ARGS "Invalid number of arguments\n"
# define ERR_PIPE "Error pipe "
# define ERR_EXECVE "Error execve "
# define ERR_MALLOC "Error malloc "
# define ERR_OPEN "Error open "
# define ERR_CMD " command not found\n"
# define ERR_DIR " No such file of directory\n"
# define ERR_FILE "Error invalid file \n"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define DEFAULT_COLOR 0x7cfc00
# define TEXT_COLOR 0xeaeaea
# define HORIZONTAL 0
# define VERTICAL 1
# define ESC_KEY 65307
# define DESTROY_NOTIFY 17
# define ANGLE_30 0.523599

typedef struct s_point
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;
	double	z;
	int		color;
	int		center_x;
	int		center_y;
}			t_point;

typedef struct s_map
{
	int		width;
	int		height;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	int		**height_map;
	int		**color_map;
}			t_map;

typedef struct s_view
{
	double	angle_x;
	double	angle_y;
	int		depth;
	double	scale;
	double	offset_x;
	double	offset_y;
}			t_view;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

typedef struct s_data
{
	t_mlx	mlx;
	t_point	point;
	t_map	map;
	t_view	view;
}			t_data;

void		handle_read_error(t_data *data, int row, const char *error_message);
int			check_file_extension(char *filename);
int			check_map_empty(char *filename);
int			check_line_width(char *line, int *width, int *first_line_width);
int			check_map_consistent_width(char *filename);
void		check_file(char *filename);
void		check_ac(int ac);
void		perror_and_exit(const char *msg);
void		put_invalid_file(const char *msg);
int			map_height(char *filename);
int			map_width(char *filename);
void		row_memory(t_data *data, int y);
void		put_map(int y, char *line, t_data *data);
void		fill_map(char *filename, t_data *data);
void		map_memory(t_data *data);
void		set_map(char *filename, t_data *data);
void		coordinate(t_data *data);
void		set_point(int x, int y, t_data *data, int flag);
void		draw_map(t_data *data);
int			main(int ac, char **av);
void		initialize(t_data *data);
void		set_offset(t_data *data);
void		calc_isometric(double *x, double *y, int z, t_data *data);
void		updata_maxmin(double x1, double y1, t_data *data);
void		display_info(t_data *data);
void		init_mlx(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		update_min_max(double iso_x, double iso_y, t_data *data);
void		find_min_max_iso(t_data *data);
double		calc_scale(t_data *data);
void		set_scale(t_data *data);
int			hex_str_to_int(char *hex);
int			get_width_from_line(char *line);
char		*gnl_remove_trailing_chars(int fd);
void		calc_line_steps(t_data *data);
int			x_botton(t_data *vars);
int			press(int keycode, t_data *var);
void		reset_gnl(char *filename);
char		**spe_split(char *str);
void map_free(t_data *data);
#endif
