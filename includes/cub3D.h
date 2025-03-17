/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:09:34 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/28 17:21:24 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdbool.h>

# define PIXELS 64
# define WIDTH 640
# define HEIGHT 480
# define NUM_TEXTURES 4
# define MOVEMENTSPEED 0.0125
# define ROTATIONSPEED 0.015
# define XK_ESCAPE 0xff1b
# define FORWARD 0x77
# define BACKWARD 0x73
# define MOVE_LEFT 0x61
# define MOVE_RIGHT 0x64
# define ROTATE_LEFT 0xff51
# define ROTATE_RIGHT 0xff53
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define RED 0xFF0000
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define MINIMAP_SIZE 100
# define MINIMAP_TILE 16

# ifndef BONUS
#  define BONUS 1
# endif

//set up enum for directions
typedef enum e_direction
{
	N = 0,
	E = 1,
	S = 2,
	W = 3
}	t_direction;

//Structure for the image it include:
//pointer to image, pointer to img address, bit per pixel
//line len, endian
typedef struct s_img
{
	void	*img; 
	int		*img_addr;
	int		texture_width;
	int		texture_height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

//Structure for the text information of the game, it includes:
//pointer to path of north, south, east and west. Color of floor and ceiling
//
typedef struct s_textinfo
{
	char			**paths;
	int				*floor_rgb;
	int				*ceiling_rgb;
	char			**grid;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				idx;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_textinfo;

//Structure for map information, it includes:
//fd to open the map file, a counter of lines in the map, the map path
//file, height, width and index of tcharhe end of the map
typedef struct s_mapinfo
{
	char	**map;
	size_t	map_height;
	size_t	map_width;
	int		idx_map_end;
}	t_mapinfo;

//Structure for the ray it includes:
//camera, direction in x and y, map in x and y, steps in x and y
//side distance in x and y, delta distance in x and y, wall distance 
typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedistance_x;
	double	sidedistance_y;
	double	deltadistance_x;
	double	deltadistance_y;
	double	wall_distance;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

//Structure for the player, it includes:
//direction in which the player is oriented, position in x and y, 
//direction in x and y plane in x and y, check if the player has 
//moved, movement in x and y and rotation
typedef struct s_player
{
	char	direction;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_minimap
{
	char	**map;
	int		size;
	int		height;
	int		width;
	int		mini_x;
	int		mini_y;
	int		tile_size;
}	t_minimap;

//Structure to store the global data of the game, it includes:
//pointer to minilibx connection and window, window height and width, pointer to
//map, player, ray and textinfo. It also includes map and textures
typedef struct s_data
{
	void			*mlx_conn;
	void			*mlx_window;
	char			**path;
	t_mapinfo		*mapinfo;
	t_player		player;
	t_ray			ray;
	t_textinfo		*textinfo;
	int				**textures;
	int				**texture_pixels;
	int				height;
	int				width;
	t_minimap		minimap;
}	t_data;

//sources/initialize/init_textures.c
void		ft_init_texture_pixels(t_data *data);
void		ft_get_texture_idx(t_data *data, t_ray *ray);
int			*xpm_buffer_image(t_data *data, char *path);
int			ft_initialize_textures(t_data *data);
void		ft_put_pixel_to_img(t_img *imginfo, int x, int y, int colour);

//sources/initialize/initialize_data.c
int			ft_initialize_map(t_data *data, t_textinfo *text);
int			ft_initialize_data(t_data **data, t_textinfo *text);
int			ft_initialize_player(t_data *data);
int			check_player_position(t_data *data);
void		find_player_direction(t_data *data);

//sources/initializing/initialize_info.c
t_textinfo	*ft_initialize_info(char **arr);
int			fill_paths(t_textinfo *text, char **grid);
int			*validate_and_convert(t_textinfo *text, char **arr, \
				char **grid, unsigned long *hex_value);
int			*populate_rgb_values(t_textinfo *text, char **grid, \
				int c, unsigned long *hex_value);
int			check_rgb_for_illegal_chars(char **arr);

//sources/initialize/initialize_window.c
int			ft_initialize_connection(t_data *data);
int			ft_init_texture_img(t_data *data, t_img *image, char *path);
int			ft_init_img(t_data *data, t_img *image);

//sources/initialize/render_image.c
void		ft_update_pixels_img(t_data *data, t_img *img, int x, int y);
void		ft_draw_image_in_window(t_data *data);
void		ft_init_game(t_data *data);
int			ft_render(t_data *data);

//sources/moving/check_position.c
int			ft_check_if_empty(t_data *data, double x, double y);
int			ft_check_if_inside_map(t_data *data, double x, double y);
int			ft_allow_movement(t_data *data, double x, double y);
int			ft_validate_movement(t_data *data, double x_after, double y_after);

//sources/moving/initial_position.c
void		ft_initialize_north_south(t_player *player);
void		ft_initialize_west_east(t_player *player);
void		ft_init_player_dir(t_data *data);

//sources/moving/input_handler.c
int			ft_handle_key(int keysym, t_data *data);
int			ft_release_key(int keysym, t_data *data);
int			on_destroy(t_data *data);
void		ft_loop_events(t_data *data);

//sources/moving/move_player.c
int			ft_move_player_fw(t_data *data);
int			ft_move_player_bw(t_data *data);
int			ft_move_player_left(t_data *data);
int			ft_move_player_right(t_data *data);
int			ft_move_player(t_data *data);

//sources/moving/rotate.c
void		ft_rotate(double *x, double *y, double speedrot);
int			ft_rotate_player_dir_vector(t_data *data, double speedrot);
int			ft_execute_rotation(t_data *data, double dirrot);

//sources/parsing/check_map.c
void		valid_chars(t_textinfo *text);
void		count_chars(char **arr, size_t *player);
void		check_map_items(t_textinfo *text);
char		*ft_trim_line(char *str);

//sources/parsing/check_map2.c
char		**copy_grid(t_textinfo *text, char **grid, int start);
int			filter_grid_lines(t_textinfo *text, char **grid);
int			find_grid_start(char **grid);
int			check_after_grid(char **grid, int start);

//sources/parsing/flood_fill_check.c
int			find_item(char **grid, char axis);
int			path_checker(char **game, size_t y, size_t x);
void		flood_fill(t_textinfo *text);
void		check_map_size(t_textinfo *text);

//sources/parsing/helper_functions.c
void		copy_valid_lines(char *grid, char *trimmed, char **arr);
void		check_empty_lines(char **grid, int i);
char		*ft_strndup(const char *s, size_t n);
void		print_map(char **arr);
int			ft_strstr(char *str, char *to_find);

//sources/parsing/make_game_map.c
void		ft_change_space(t_data *data);
int			ft_make_game_map(t_data *data);
int			ft_find_longest_line(char **arr);
char		**reallocate_map(t_data *data, int len);
char		*ft_strncpy(char *dest, char *src, unsigned int n);

//sources/parsing/parse_input.c
char		*find_cardinal_paths(char **arr, char *s);
char		*path_extractor(char **arr, char *str);
char		*find_floor_ceiling(t_textinfo *text, char **arr, int c);
char		**remove_empty_lines(char **arr);
int			ft_empty_check(char **arr);

//sources/parsing/read_input.c
void		check_extension(char *s);
size_t		row_count(char **grid);
char		**read_map(char *s);
char		*ft_replace(char *s);
char		**graphic_gnl(int size, int fd, char **arr, int i);

//sources/raycasting/handle_textures.c
void		ft_calculate_texture_coordinates(t_data *data, t_ray *ray);
void		ft_update_texture_pixels(t_data *data, t_ray *ray, int x);

//sources/raycasting/implement_raycasting.c
void		ft_initialize_raycasting(int x, t_ray *ray, t_player *player);
void		ft_get_ray_step_and_distance(t_ray *ray, t_player *player);
void		ft_implement_dda(t_data *data, t_ray *ray);
void		ft_calculate_wall_height(t_data *data, t_ray *ray, \
				t_player *player);
int			ft_make_raycasting(t_player *player, t_data *data);

//sources/errors.c
void		error_message(char *str);
int			error_message_simple(char *str, char **arr);
void		error_reading_file(char *str, char **arr, int fd);
void		error_exit(char *str, t_data *data, t_textinfo *text);
void		error_message_text(char *str, t_textinfo *text);

//sources/errors2.c
int			error_malloc(char *s);
void		error_text_with_array(char *str, t_textinfo *text, char **arr);

//sources/free_functions.c
void		free_memory(char **arr);
void		ft_exit_game(t_data *data);
void		ft_clean_exit(t_data *data);
void		free_text(t_textinfo *text);
void		free_partials(void **arr);

//sources/bonus/minimap.c
void		ft_mouse_position(t_data *data, int x, int y);
int			ft_mouse_handler(t_data *data, int x, int y);
void		ft_initialize_minimap(t_data *data);
void		render_minimap(t_data *data);

//sources/bonus/minimap_helper.c
int			ft_find_colour(t_data *data, int y, int x);
void		ft_make_mini_tiles(t_data *data, t_img *img, int y, int x);

char		**split_rgb_and_validate(char **grid, t_textinfo *text, char *temp);
char		*find_string_path(char **arr, char *s);
char		*find_path_in_info(char **arr, int c);

#endif