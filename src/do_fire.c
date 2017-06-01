#include "fdf.h"

void	do_fire(t_data *data)
{
	int i;

	i = -1;
	while (data->bull[++i])
		;
	if (i >= 100)
		return;
	data->bull[i] = (t_fire *)malloc(sizeof(t_fire) * 1);
	data->bull[i]->img = mlx_xpm_file_to_image(data->mlx, "texture/new_star.xpm", &data->bull[i]->weight, &data->bull[i]->height);
	data->bull[i]->x_cord = (int)data->board->x + (data->figure->x / 2) - (data->bull[i]->weight / 2);
	data->bull[i]->y_cord = (int)data->board->y - data->bull[i]->height;
//	while (y >= 0 )
//	{
//		ft_printf("\n%d,%d\n",data->figure->head_x, data->figure->head_y);
//		z = 0;
//		ft_printf("OK\n");
//		while (++z < 6)
//		{
//			ft_printf("%d,%d\t",x, y - z);
//			mlx_pixel_put(data->mlx, data->win, x, y - z, 0xFF0000);
//		}
//		sleep(1);
//		z = 0;
//		while (++z < 6)
//			mlx_pixel_put(data->board->mlx, data->board->win, x, y - z, 0x000000);
//		y -= 15;

//	}
}