#include "fdf.h"


void ft_move_background(t_data *data)
{
	char *tmp;
	int y;
	int i;
	int z;
	int x;

	tmp = mlx_get_data_addr(data->background->img, &i, &y, &z);
	while (x < y * 75)
	{
//		ft_printf("%d %d %d %d\n", tmp[x], tmp[x + 1], tmp[x + 2], tmp[x + 3]);
		if (tmp[x + 3] != -1)
			tmp[x + 3] = 200;
		x += 4;
	}
}

void ft_put_background(t_data *data)
{
	if ((data->background->head_y % 500) == 0)
		data->background->head_y = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->background->img, 0, data->background->head_y++);
	mlx_put_image_to_window(data->mlx, data->win, data->background->img, 0, -BOARD_HEIGHT + data->background->head_y);
}


void	ft_do_this(t_data *data)
{
	char *tmp;
	int y;
	int i;
	int z;
	int x;

	tmp = mlx_get_data_addr(data->figure->img, &i, &y, &z);
	x = 0;
	while (x < y * 75)
	{
//		ft_printf("%d %d %d %d\n", tmp[x], tmp[x + 1], tmp[x + 2], tmp[x + 3]);
		if (tmp[x + 3] != -1)
			tmp[x + 3] = 200;
		x += 4;
	}
}