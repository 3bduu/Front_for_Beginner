/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/06 23:08:23 by abenlahb          #+#    #+#             */
/*   Updated: 2023/10/06 23:08:23 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"
# define TEXTURE_EXTENSION ".xpm"
# define F_COLOR "F"
# define C_COLOR "C"

# define GREEN 0x0aad39
# define RED 0xc70c1c
# define YELLOW 0xdbd112
# define ORANGE 0Xfa8202
# define BLACK 0x000000
# define BLUE 0x87CEFA
# define WHITE 0xFFFFFF
# define FLOOR 0xcd8500

# define WIDTH 1024
# define HEIGHT 700

# define SIZE 64
# define PI 3.14159265359
# define TWOPI 6.28318530718
# define FOV 1.0471975512
# define HALF_FOV 0.52359877559

# define KEYPRESS 2
# define KEYUP 3
# define DESTROY 17
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_norm
{
	int	tex_numb;
	int	found_f;
	int	found_c;
}	t_norm;
typedef struct s_norm3
{
	int		offset_x;
	float	wall;
	int		offset_y;
	float	start_h;
	float	end_w;
	float	x;
	float	start_w;
}	t_norm3;

typedef struct s_norm2{
	int	j;
	int	i;
	int	row_length;
}	t_norm2;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tex_width;
	int		tex_height;
}	t_data;

typedef struct s_tocheck
{
	float	x;
	float	y;
	float	deltax;
	float	deltay;
	float	horz_hitx;
	float	horz_hity;
	float	vert_hitx;
	float	vert_hity;
	int		facingdw;
	int		facingup;
	int		facingright;
	int		facingleft;
	int		foundh_hit;
	int		foundv_hit;
}	t_tocheck;

typedef struct s_ray
{
	float	rayalpha;
	float	hitx;
	float	hity;
	float	dist;
	int		hitvert;
	int		facingup;
	int		facindw;
	int		facinleft;
	int		facinright;
}	t_ray;

typedef struct s_get_map
{
	int		element_numb;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		column;
	char	pos_player;
	int		row_player;
	int		col_player;
	char	**map;
	char	**map_2;
	int		nb_raw;
	int		nb_line;
	int		nb_map2;
	int		biger_row;
	t_color	f_color;
	t_color	c_color;
	void	*mlx;
	void	*win;
	int		i;
	int		windows_w;
	int		windows_h;
	int		casted_rays;
	float	step_angle;
	float	player_x;
	float	player_y;
	float	up_down;
	float	left_right;
	float	mleft_right;
	float	rangle;
	float	wspeed;
	float	tspeed;
	float	start_angle;
	float	screen_dist;
	t_ray	*ray;
	t_data	data[4];
	t_data	img;
}	t_my_map;

void			check_more(t_my_map *param);
void			process_and_copy_map_line(t_my_map *src, int start,
					int j);
void			initial_data(t_my_map *data_map);
void			process_texture_line(char *temp, t_norm *norm, int *tex_flags);
int				is_valid_digit(const char *str);
void			process_texture(t_my_map *param, char **splited);
int				handle_arg(char *str);
void			check_conditions(int tex_numb, int found_c, int found_f);
void			check_tex_flags(int tex_flags[]);
void			procces_color(t_my_map *param, char **splited);
void			process_line(char *temp, t_norm *norm, int *tex_flags);
void			get_cooma(char *str);
void			error_pars(t_my_map *src);
void			free_funct(t_my_map *src);
unsigned int	my_mlx_pixel_get(t_data data, int x, int y);
void			check_map(t_my_map *src);
int				is_char_pattern(char c, char *set);
char			*ft_strcpy(char *dest, char *src);
int				count_longest_line(int i, char **map);
char			*ft_strlen_dup(const char *s1, size_t len);
void			check2_map(t_my_map *src);
void			get_map(t_my_map *src);
int				isspace(int c);
int				is_videe(char *s);
char			*ft_str_n_dup(const char *s1, size_t len);
int				test_is_derctory(char *file_name);
int				is_empty(int fd);
int				test_extension_xpm(char *file_name, char *extension);
int				test_extension(char *file_name, char *extension);
void			free_2p(char **array);
char			*get_next_line(int fd);
int				ft_strcmp(char *s1, char *s2);
void			start_parse(char *filename, t_my_map *src);
void			let_dup(t_my_map *info_mapm, char *file_name);
int				is_spacee(char c);
void			start_parse(char *filename, t_my_map *src);
void			ft_putstr(char *str, int fd);
void			error_message(char *str, int fd);
char			**get_content(int fd, t_my_map *info_map);
void			raycasting(t_my_map *src);
void			minimap(t_my_map *src);
int				player_press(int keycode, t_my_map *src);
void			player_move(t_my_map *player);
int				player_up(int keycode, t_my_map *src);
int				end_of_game(t_my_map *src);
void			my_mlx_pixel_put(t_data *data, int x,
					int y, unsigned int color);
unsigned int	my_mlx_pixel_get(t_data data, int x, int y);
int				create_rgb(int r, int g, int b);
void			free_map(t_my_map *src);
int				end_of_game(t_my_map *src);
int				handle_mouse_motion(int x, int y, t_my_map *src);
int				render_frame(t_my_map *src);
void			take_image(void *mlx, t_data *img, char *path);
void			render_rays(t_my_map *src);
void			ray_cast(t_my_map *src);
void			one_ray(t_my_map *src,
					float rayangle, int index);
void			other_values(t_my_map *src,
					float rayangle, int index, t_tocheck *ptr);
void			dh_rightdist(t_my_map *src,
					float rayangle, int index, t_tocheck *ptr);
void			dv_rightdist(t_my_map *src,
					float rayangle, int index, t_tocheck *ptr);
void			calculate_dist(t_my_map *src,
					t_tocheck *ptr, float *dh, float *dv);
void			verticalfunction(t_my_map *src,
					float rayangle, t_tocheck *ptr);
void			vert_norm(t_my_map *src, t_tocheck *ptr);
void			horizontalfunction(t_my_map *src,
					float rayangle, t_tocheck *ptr);
void			hori_norm(t_my_map *src, t_tocheck *ptr);
float			distancebetweenpoint(float x1, float y1, float x2, float y2);
int				rayfacingrl(float rayangle);
int				rayfacingud(float rayangle);
float			corrvalue(float rayangle);
int				wallat(t_my_map *src, float x, float y);
t_tocheck		*allocation(float *rayangle);
void			draw_square1(t_my_map *src, float start_h,
					float end_w, float wall);
#endif
