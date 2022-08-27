/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:53:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/18 18:14:15 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ------------------------------- LIBRARIES -------------------------------- */
// Functions & Functionalities //
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

// Macros & Typedefs //
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

// Custom
# include "../includes/get_next_line/get_next_line.h"
# include "m4cr0s.h"
# include <mlx.h>

/* --------------------------------- ENUMS ---------------------------------- */
typedef enum s_dirctn
{
	NO,
	SO,
	WE,
	EA
}	t_dirctn;

/* -------------------------------- TYPEDEFS -------------------------------- */
typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

/* -------------------------------- STRUCTS --------------------------------- */
typedef struct s_input
{
	int		texture_fds[4];
	int		ceil_clr;
	int		floor_clr;
	char	**map_arr;
}	t_input;

typedef struct s_fcoords
{
	double	y;
	double	x;
}	t_fcoords;

typedef struct s_icoords
{
	int	y;
	int	x;
}	t_icoords;

typedef struct s_brsnhm
{
	t_icoords	dlta;
	t_icoords	pxl;
	t_icoords	s;
	int			err;
	int			e2;
}	t_brsnhm;

typedef struct s_player
{
	t_fcoords	pos;
	double		rot;
	char		turn_dir;
	char		walk_dir;
}	t_player;

typedef struct s_intersection
{
	double	x_point;
	double	y_point;
	char	is_intersected;
}	t_intrsctn;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	char	is_facing_down;
	char	is_facing_up;
	char	is_facing_right;
	char	is_facing_left;
}	t_ray;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_display
{
	void		*mlx;
	void		*win;
	t_img		img;
}	t_display;

typedef struct s_cub
{
	t_display	display;
	t_player	player;
	t_input		input;
}	t_cub;

/* ------------------------------- PROTOTYPES ------------------------------- */
/* DISPLAY */
void	img_pixel_put(t_img *img, t_icoords pxl, int color);
void	draw_line(t_img *img, t_fcoords p0, t_fcoords p1, int color);

void	move_horizontally(t_cub *cub, int walk_dir);
void	update_player_position(t_cub *cub);

void	draw_background(t_img *img, t_input *input);
void	draw_player(t_player *player, t_img *img, int size);
void	draw_minimap(t_cub *cub);

void	reset_window(t_cub *cub);
void	init_display_params(t_cub *cub);

/* PARSING */
void	map_is_closed(char **map_arr);
void	only_one_player(char **map_arr, t_player *player);

void	check_init_color(char **line_split, t_input *gen_data);
void	check_init_direction_texture(char **line_split, t_input *gen_data);

void	process_file_data(char *filename, t_input *gen_data, t_player *player);

/* -------------------------- EVENTS HANDLING ------------------------------- */
/* - - handle_keypress.c - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void	redraw_and_output_image(t_cub *cub);
void	player_movement(int keycode, t_cub *cub);
void	esc_close(int keycode, t_cub *cub);
int		key_press(int keycode, void *_cub);

/* - - cub3d.c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int		xclose(void *v_cub);

/* - - handle_mouse_events.c - - - - - - - - - - - - - - - - - - - - - - - - -*/
int		mouse_move(int x, int y, void *_cub);

/* - - handle_misc_events.c - - - - - - - - - - - - - - - - - - - - - - - - - */
int		xclose(void *v_cub);

/* --------------------- Ray-Casting calculations --------------------------- */
double	deg2rad(int deg);
int		rad2deg(double rad);
double	normalize_angle(double rotation);
int		check_wall_colision(t_fcoords pos, char **map_arr);
double	dstnce_btwn_points(double x1, double y1, double x2, double y2);
/* - - misc_calculs.c - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void    casting_rays(t_cub *cub);
void    cast(t_cub *cub, t_ray ray);

#endif
