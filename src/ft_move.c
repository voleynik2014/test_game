#include "fdf.h"
#include "math.h"

void    clear_player(t_data *data)
{
    int x;
    int y;

    x = data->figure->sideLeft_x;
    while (x <= data->figure->sideRight_x)
    {
        y = data->figure->head_y;
        while (y <= data->figure->sideLeft_y) {
            mlx_pixel_put(data->mlx, data->win, x, y++, 0x000000);
        }
        x++;
    }
}

void    move_forward(t_data *data, float i)
{
	if (data->board->y > 0)
		data->board->y += i;
}

void    move_left(t_data *data, float i)
{
	data->angle->x_cos = cos(data->center_of_mass->x);
	data->angle->x_sin = sin(data->center_of_mass->x);
	data->angle->y_cos = cos(data->center_of_mass->x);
	data->angle->y_sin = sin(data->center_of_mass->x);
	if (data->center_of_mass->x)
		ft_rotate_ship(data);
}


void    move_right(t_data *data, float i)
{
	data->angle->x_cos = cos(data->center_of_mass->x);
	data->angle->x_sin = sin(data->center_of_mass->x);
	data->angle->y_cos = cos(data->center_of_mass->x);
	data->angle->y_sin = sin(data->center_of_mass->x);
//	printf("x:%f %f\n", 	data->angle->x_cos , 	data->angle->x_sin);
	if (data->center_of_mass->x)
		ft_rotate_ship(data);
}

void    move_back(t_data *data, float i)
{
	if (data->board->y < BOARD_HEIGHT)
		data->board->y += i;
}

void	ft_move(t_data *data)
{
	if (data->center_of_mass->y || data->center_of_mass->x) {
		if (data->center_of_mass->y) {
			ft_clear_img(data);
//		ft_printf("y:%d\n", data->center_of_mass->y);
			if (data->center_of_mass->y > 0.0)
				move_back(data, data->center_of_mass->y);
			else
				move_forward(data, data->center_of_mass->y);
		}
		if (data->center_of_mass->x) {
//		printf("x:%f\n", data->center_of_mass->x);
			ft_clear_img(data);
			if (data->center_of_mass->x > 0)
				move_right(data, data->center_of_mass->x);
			else
				move_left(data, data->center_of_mass->x);
		}
		ft_put_player_on_the_board(data);
	}
}
