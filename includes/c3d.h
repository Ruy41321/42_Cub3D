/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:28:38 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/03 17:35:51 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define SHOW_2D 0
#define SHOW_WITH_COLORS 0

#define INVALID_PATH "Error\nInvalid path!\n"
#define INVALID_PARAMS "Error\nThe only allowed parameter is the path\
 of the map with .cub extension!\nUsage:\n./cub3d <map_path>\n"
#define INVALID_MAP "Error\nInvalid map!\n"
#define MAP_NOT_CLOSED "Error\nThe map must be closed/surrounded by walls!\n"
#define INVALID_CHARACTER "Error\nThe map must contains: only 'space', '0', \
'1', and one of 'N', 'S', 'E', 'W'.\n"
#define INVALID_TEXTURE_PATH "Error\nInvalid texture path!\n"
#define INVALID_COLOR_FORMAT "Error\nInvalid color format! Colors must be in\
 the format R,G,B with values in the range [0,255].\n"
#define MISSING_INFORMATION "Error\nMissing texture or color information!\n"
#define INVALID_ELEMENT_ORDER "Error\nInvalid element order! The map content \
must be the last element in the file.\n"
#define FILE_READ_ERROR "Error\nAn error occurred while reading the file!\n"

#define INCREMENT_X 1
#define INCREMENT_Y 0

#define TRUE 1
#define FALSE 0

#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define ESC 65307
#define ARROW_LEFT 65361
#define ARROW_RIGHT 65363

#define RED 0xff0000
#define GREEN 0x00ff00
#define BLUE 0x0000ff
#define BLACK 0X000000
#define YELLOW 0xffff00
#define WHITE 0xffffff
#define PURPLE 0x800080
#define GRAY 0x808080
#define PINK 0xffc0cb

#define NE 1330
#define E 1500
#define SE 1630
#define S 1800
#define SW 1930
#define W 2100
#define NW 2230
#define N 2400

#define EPSILON 1e-9

#define M_PI 3.14159265358979323846
#define PI_FIX 0.00000001
#define DEGREE 0.0785398163 // 2 * M_PI / 80

#define CIRCUMFERENCE_CHECKS 8

#define TILE_SIZE 64
#define RAY_LENGTH 16 // Radius * 8
#define FOOT_STEP 5
#define RADIUS 2

#define CAMERA_DISTANCE 20 // RADIUS * 10
#define FOV_ANGLE 1.25664 // M_PI / 2.5

#define SCALE_FACTOR 10000

#define NUM_OF_RAYS 1000

typedef struct s_dimension
{
	int	w;
	int	h;

}	t_dimension;

typedef struct s_win
{
	void		*mlx_win;
	t_dimension	dimension;
}	t_win;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_bras_params
{
	t_point	xy0;
	t_point	dx;
	t_point	sx;
	int		color;
}	t_bras_params;

typedef struct s_map
{
	char		*texture_data;
	char		*map_data;
	t_dimension	dimension;
	char		**grid;
	t_point		player_position;
	int			player_orientation;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*f_color;
	char		*c_color;
}	t_map;

typedef struct s_img
{
	void		*img;
	char		*data_addr;
	int			size_line;
	int			bits_per_pixel;
	int			endian;
	t_dimension	img_dimension;
}	t_img;

typedef struct s_fov
{
	double	angle;
	double	half_left;
	double	half_right;
}	t_fov;

typedef struct s_projection
{
	t_point	point;
	double	length;
}	t_projection;

typedef struct s_viwe3d
{
	double	height_wall_line;
	double	x_wall_line;
}	t_view3d;

typedef struct s_ray
{
	int				cardinal_direction;
	t_point			first_side_point;
	t_point			first_impact_point;
	t_point			delta;
	t_point			path;
	t_point			first_point;
	t_point			end_point;
	t_projection	projection;
	t_view3d		view3d;
	int				last_increment;
	int				orientation;
}	t_ray;

typedef struct s_move
{
	int	w;
	int	a;
	int	s;
	int	d;
}	t_move;

typedef struct s_player
{
	t_point		position;
	t_point		tile;
	t_move		move;
	t_fov		fov;
	int			cardinal_direction;
	double		direction;
	double		perpendicular_direction;
	double		rotate_alpha_right;
	double		rotate_alpha_left;
	t_ray		ray;
}	t_player;

typedef struct s_c3d
{
	void		*mlx_connection;
	t_win		win_2d;
	t_win		win_3d;
	t_map		raw_map;
	t_img		map;
	t_img		texture[4];
	t_img		scene_3d;
	t_player	player;
	char		**map_lines;
}	t_c3d;

int		get_direction(double perpendicular_direction);
int		find_x_texture(t_point impact_point, t_ray ray);
void	set_texture(t_c3d *c3d);
int		on_destroy(t_c3d *c3d);
void	error_exit(t_c3d *c3d, char *message);

t_point	find_intersection(t_point p1, double p1_ang, t_point p2, double p2_ang);
double	find_x_3d(double ray_angle, double fov_left_ray, double win_width);
double	pitagora_theorem(t_point first_point, t_point second_point);
double	calculate_3d_wall_height(t_player player);

void	create_visualize_2d_map_img(t_c3d *c3d);
int		get_pixel(t_img *img, int x, int y);
void	put_pixel(t_img *img, int x, int y, int color);

char	*read_the_map(char *file_path);
void	get_map_dimensions(char *file_content, int *width, int *height);
char	**get_map_from_file(char *file_content, int width, int height);
void	build_map(char *path, t_c3d *c3d);
void	parse_and_check(t_c3d *c3d);

void	initialization(t_c3d *c3d);
void	initialize_ray(t_ray *ray);
void	initialize_win(t_win *win);
void	point_init(t_point *point_to_initialize);

void	set_connection_and_windows(t_c3d *c3d);

int		n_corner(int x, int y, t_c3d *c3d);
int		north(int x, int y, t_c3d *c3d);
int		west(int x, int y, t_c3d *c3d);
t_point	calculate_end_point(t_ray *ray, double alpha, t_c3d *c3d);
t_ray	dda(t_point start_point, double alpha, t_c3d *c3d);
t_point	chose_side_point(t_point first_point, int cardinal_direction);
int		get_cardinal_direction(double angle);
t_point	calc_delta(t_point first_point, t_point second_point, \
int cardinal_direction);
t_point	calculate_path(t_point delta, double alpha);
t_point	trigonometric_point_calc(t_point player_position, double path, \
double alpha);

int		is_it_inside_map_perimeter(t_point point_to_verify, \
t_dimension map_dimension);
int		is_it_passing_between_two_walls(t_ray *ray, char **map_grid, t_point \
point_to_verify);
int		is_it_a_wall(t_point point_to_verify, char **map_grid);

void	draw_2d_map(t_img *img, t_c3d *c3d);
void	draw_player(t_c3d *c3d, t_point center, int radius, int color);
void	draw_player_in_img(t_c3d *c3d);
void	draw_player_direction(t_c3d *c3d, t_point xy, double alpha, \
int color);
void	bresenham(t_c3d *c3d, int x1, int y1, int color);
void	draw_line(t_point point, double angle, int color, t_c3d *c3d);
int		get_pixel(t_img *img, int x, int y);
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_2d_fov_boundaries(t_c3d *c3d);
void	draw_floor(t_c3d *c3d);
void	draw_ceiling(t_c3d *c3d);
void	draw_3d_fov(t_c3d *c3d);
void	draw_3d_scene(t_c3d *c3d);
void	drawing_routine(t_c3d *c3d);
int		on_2d_resize(t_c3d *c3d);
int		on_3d_resize(t_c3d *c3d);

int		mov_key_press(int keycode, void *param);
int		mov_key_release(int keycode, void *param);
int		update_position(void *param);
void	move_player_mains(int direction, t_move move, t_point *position, \
int step_decr);
void	move_player_oblq(int direction, t_move move, t_point *position, \
int step_decr);
int		update_alpha_rotation(void *param);
int		update_movement(void *param);
int		is_collision(double player_next_x, double player_next_y, t_c3d *c3d);
t_point	tile_reference(t_point point);
void	set_player_orientation(t_c3d *c3d);

void	draw_3d_wall_height_with_one_color(double x_3d, double line_heigth, \
t_c3d *c3d);
void	draw_tile(char **img_data_addr, t_point xy, int color, t_c3d *c3d);
void	check_shorter_rows(t_c3d *c3d, char **map_lines, int height);
void	check_map_closed(t_c3d *c3d, char **map_lines);
void	remove_extra_space(char **lines);
int		check_color_format(t_map *raw_map, char *line);
int		check_map_characters(t_map *raw_map, char **lines);