

#ifndef FDF_H
# define FDF_H
# define BOARD_WIDTH 500
# define BOARD_HEIGHT 500
# define COUNT_BULLET 100


#include "../libft/libft.h"
#include <mlx.h>
#include <time.h>
//#include "enemy.h"
//#include "minilibx/mlx.h"
#include "/opt/X11/include/X11/X.h"

typedef struct  s_cofmass
{
	float		x;
	float       y;
}               t_cofmass;

typedef struct  s_tri
{
	void		*img;
	int 		speed;
    int      	x;
    int      	y;
	int			head_x;
	int			sideLeft_x;
	int			sideRight_x;
	int			head_y;
	int			sideLeft_y;
	int			sideRight_y;
}               t_tri;

typedef struct  s_key
{
    float         x;
    float         y;
	int 		x_size;
	int 		y_size;
}               t_key;

typedef struct  s_fire
{
	void		*img;
	int 		weight;
	int 		height;
	int 		x_cord;
	int 		y_cord;
}               t_fire;

typedef struct	s_coord
{
	double		x_cos;
	double 		x_sin;
	double		y_cos;
	double 		y_sin;
}				t_coord;

typedef struct  s_data
{
	void        *mlx;
	void        *win;
	int 		count_bullet;
	int			time;
	clock_t 	prev;
    struct s_key   *board;
    struct s_tri   *figure;
	struct s_fire	**bull;
	struct s_cofmass	*center_of_mass;
	struct s_enemy		**enemy;
	struct s_coord		*angle;
	struct s_old_ship	*old_ship;
}               t_data;

void	ft_clear_img(t_data *data);

void	ft_delete_bullet(t_data *data);
void	ft_delete_fps(t_data *data);

void	ft_handle_fire(t_data *data);
void	ft_create_arr_of_fire(t_data *data);

void    ft_print_figure(t_data *data);
void    ft_put_player_on_the_board(t_data *data);

void	ft_move(t_data *data);
void    clear_player(t_data *data);
void    move_forward(t_data *data, float i);
void    move_back(t_data *data, float i);
void    move_right(t_data *data, float i);
void    move_left(t_data *data, float i);

void	do_fire(t_data *data);

void	ft_rotate_ship(t_data *data);

int     ft_triangle(t_data *data);
#endif
