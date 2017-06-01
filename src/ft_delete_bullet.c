#include "fdf.h"

void	ft_delete_bullet(t_data *data)
{
	int x;
	int y;

	x = 59;
	while (++x < 80)
	{
		y = -1;
		while (++y < 13)
			mlx_pixel_put(data->mlx, data->win, x, y, 0x00);
	}
}

void	ft_delete_fps(t_data *data)
{
	int x;
	int y;

	x = 30;
	while (++x < 75)
	{
		y = 15;
		while (++y < 30)
			mlx_pixel_put(data->mlx, data->win, x, y, 0x00);
	}
}