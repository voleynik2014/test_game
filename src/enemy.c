#include "fdf.h"
#include "enemy.h"

void	ft_new_enemy(t_data *data)
{
	t_enemy	*new;
	int i;

	new = (t_enemy *)malloc(sizeof(t_enemy) * 1);
	new->img =  mlx_xpm_file_to_image(data->mlx, "texture/cat.xpm", &new->weight, &new->height);
	new->y_cord = 0;
	new->speed = clock() % 7;
	while (1)
	{
		new->x_cord = (int)clock() % 450;
		if (new->x_cord > 30)
			break ;
	}
	i = -1;
	while (data->enemy[++i])
		;
	data->enemy[i] = new;
}

void	ft_handle_enemy(t_data *data)
{
	int i;

	i = -1;
	while (data->enemy[++i])
	{
		ft_clear_enemy_img(data, data->enemy[i]);
		data->enemy[i]->y_cord += data->enemy[i]->speed;
		ft_print_enemy_img(data, data->enemy[i]);
	}
}


void	ft_clear_enemy_img(t_data *data, t_enemy *enemy)
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

void	ft_print_enemy_img(t_data *data, t_enemy *enemy)
{
	if (enemy->x_cord < BOARD_WIDTH && enemy->x_cord > 0 && enemy->y_cord < BOARD_HEIGHT && enemy->y_cord > 0) {
		mlx_put_image_to_window(data->mlx, data->win, enemy->img, enemy->x_cord, enemy->y_cord);
	}
}