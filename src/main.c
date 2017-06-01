#include <stdio.h>
#include "../includes/fdf.h"
#include "enemy.h"
#include "math.h"

int     handl_key(int key, t_data *data)
{
//	ft_printf("%d\n", key);
	switch (key)
	{
		case 32:
			do_fire(data);
			if (data->count_bullet)
			data->count_bullet--;
			break;
		case 65307:
			exit(ft_printf("exit programm\n") - 14);
		case 65363:
			if (data->center_of_mass->x < 6.29)
			data->center_of_mass->x += 0.78;
			break;
		case 65362:
			if (data->center_of_mass->y > -2)
			data->center_of_mass->y -= 0.3;
			break;
		case 65361:
			if (data->center_of_mass->x > -6.29)
			data->center_of_mass->x -= 0.78;
			break;
		case 65364:
			if (data->center_of_mass->y < 2)
			data->center_of_mass->y += 0.3;
			break;
		default:
			;
	}
	return 0;
}

int 	handle_err(t_data *data)
{
	static size_t count = 0;
	static size_t  i = 0;

	if (clock() / 1000000 == count) {
		i++;
//		ft_delete_fps(data);
//		mlx_string_put(data->mlx, data->win, 32, 29, 0xFF0000, ft_itoa((int)i));

//		i = 0;
	}
	else {
		ft_printf("%d\n", i);
		i = 0;
		ft_new_enemy(data);
		count ++;
	}
//	if (clock() / 62500 > count) {
		ft_move(data);
//		if (clock() / 62500 > count) {
//					ft_printf("%d - %d\n",clock() / 62500, count);
			ft_handle_fire(data);
			ft_delete_bullet(data);
			ft_handle_enemy(data);
			mlx_string_put(data->mlx, data->win, 60, 10, 0xFF0000, ft_itoa((data->count_bullet)));
//		}
//		if (clock() / 2000000 > count / 32)
//
//		ft_printf("ENEMY : %d - %d\n",clock() / 2000000 , count / 32 );
//		count++;
//	}

	data->time = 0;
	return 0;
}

int handle_time_loop(t_data *data) {
	clock_t cur;

	cur = clock();
	data->time = ((cur - data->prev) / 62500) ? 1 : 0;
//	printf("%f\n", cos(1.23));
	if (data->time) {
		handle_err(data);
		data->prev = cur;
	}
	return 0;
}

void	paint_board(t_data *data)
{
	int x;
	int y;

	x = -1;
	while (++x < BOARD_WIDTH)
	{
		y = -1;
		while (++y < BOARD_HEIGHT)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0x2bdbcf);
		}
	}

}

int main()
{
    t_data      data;

    data.board = (t_key *)malloc(sizeof(t_key) * 1);
	data.board->x_size = 500;
	data.board->y_size = 500;
    if ((data.mlx = mlx_init()) == NULL)
		ft_printf("BAD\n");
    data.win = mlx_new_window(data.mlx, BOARD_WIDTH, BOARD_HEIGHT, "hello");
    data.board->x = 250.0;
    data.board->y = 250.0;
	ft_create_arr_of_fire(&data);
	paint_board(&data);
    ft_triangle(&data);

//	mlx_key_hook(data.win, handl_key, &data);
//	mlx_expose_hook(data.win, handle, &data);
	mlx_string_put(data.mlx, data.win, 10, 10, 0xFF0000, "Bullet:");
	mlx_string_put(data.mlx, data.win, 10, 23, 0xFF0000, "FPS:");
//	mlx_put_image_to_window(data.mlx, data.win, data.figure->img, 100, 100);
	mlx_loop_hook(data.mlx, handle_time_loop, &data);
	mlx_hook(data.win, 2, (1L<<0), handl_key, &data);
//	mlx_hook(data.win, 3, (1L<<1), &key_release, &e);
//	mlx_hook(data.win, MotionNotify, ButtonMotionMask, handle_err, &data);
	mlx_loop(data.mlx);
    return 0;
}
