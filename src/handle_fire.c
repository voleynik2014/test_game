#include "fdf.h"
#include "enemy.h"

void	ft_create_arr_of_fire(t_data *data)
{
	int i;
	data->bull	= (t_fire **)malloc(sizeof(t_fire *) * 101);
	i = -1;
	while (data->bull[++i])
		data->bull[i] = NULL;
	data->center_of_mass = (t_cofmass *)malloc((sizeof(t_cofmass *) * 1));
	data->center_of_mass->x = 0.0;
	data->center_of_mass->y = 0.0;
	ft_bzero(data->center_of_mass, sizeof(t_cofmass));
	data->count_bullet = COUNT_BULLET;
	data->angle = (t_coord *)malloc(sizeof(t_coord) * 1);
	data->old_ship = (t_old_ship *)malloc(sizeof(t_old_ship) * 1);
	data->old_ship->tmp_cord = (t_tmp_cord *)malloc(sizeof(t_tmp_cord) * 1);
	data->enemy = (t_enemy **)malloc(sizeof(t_enemy *) * 100);
	i = -1;
	while (data->enemy[++i])
		data->enemy[i] = NULL;
}

void	ft_clear_bullet_img(t_data *data, t_fire *enemy)
{
	int x;
	int y;

	x = enemy->x_cord;
	while (x <= enemy->x_cord + enemy->weight)
	{
		y = enemy->y_cord;
		while (y <= enemy->y_cord + enemy->height) {
			mlx_pixel_put(data->mlx, data->win, x, y++, 0x000000);
		}
		x++;
	}
}

void	ft_handle_fire(t_data *data)
{
	int i;

	i = -1;
//	printf("%f\n", (float )clock() / 500000);
//	if (clock() / 250000 > count) {

//		printf("%f\n", (float )clock() / 250000);
		while (data->bull[++i]) {
			ft_clear_bullet_img(data, data->bull[i]);
			if (data->bull[i]->x_cord < BOARD_WIDTH && data->bull[i]->x_cord > 0 && data->bull[i]->y_cord < BOARD_HEIGHT && data->bull[i]->y_cord > 0) {
				data->bull[i]->y_cord -= 15;
				mlx_put_image_to_window(data->mlx, data->win, data->bull[i]->img, data->bull[i]->x_cord, data->bull[i]->y_cord);
			}

//			if (data->bull[i]->y_cord >= 0) {
//				z = 0;
//				while (++z < 6)
//					mlx_pixel_put(data->mlx, data->win, data->bull[i]->x_cord, data->bull[i]->y_cord - z, 0x000000);
//				data->bull[i]->y_cord -= 15;
//				z = 0;
//				while (++z < 6)
//					mlx_pixel_put(data->mlx, data->win, data->bull[i]->x_cord, data->bull[i]->y_cord - z, 0xFF0000);
//			}
		}
}