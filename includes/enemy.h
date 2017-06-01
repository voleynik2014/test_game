
#ifndef ENEMY_H
#define ENEMY_H

#include "fdf.h"

typedef struct	s_enemy
{
	void 		*img;
	size_t 		speed;
	int 		x_cord;
	int 		y_cord;
	int 		weight;
	int 		height;
}				t_enemy;

typedef struct	s_tmp_cord
{
	double		x_cos;
	double 		x_sin;
	double		y_cos;
	double 		y_sin;
}				t_tmp_cord;

typedef struct	s_old_ship
{
	char 		*cur;
	int 		bits_per_pixel;
	int 		size_line;
	int 		endian;
	struct s_tmp_cord	*tmp_cord;
}				t_old_ship;


void	ft_handle_enemy(t_data *data);
void	ft_clear_enemy_img(t_data *data, t_enemy *enemy);
void	ft_print_enemy_img(t_data *data, t_enemy *enemy);
void	ft_new_enemy(t_data *data);
#endif
