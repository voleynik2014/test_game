#include "fdf.h"
#include "math.h"
#include "enemy.h"

void	ft_print_temp(char **tmp) {
	int i;
	int j;

	i = -1;

	while (++i < 200) {
		j = -1;
		while (++j < 200) {
			if (tmp[i][j] == 'X')
//				ft_printf("%c", tmp[i][j]);
				ft_putchar(tmp[i][j]);
			else
				ft_putstr(" ");
		}
		ft_putstr("\n");
		ft_strdel(&tmp[i]);
	}
	if (tmp)
		free(tmp);
}

char 	**ft_crreate_temp()
{
	char **delete;
	int i = -1;
	int j;

	delete = (char **)malloc(sizeof(char *) * 201);
	ft_bzero(delete, sizeof(delete));
	while (++i < 200)
	{
		delete[i] = (char *)malloc(sizeof(char) * 201);
		j = -1;
		while (++j < 200)
			delete[i][j] = 'O';
		delete[i][j] = NULL;
	}
	delete[i] = NULL;
	return (delete);
}

void	ft_do_magic(t_data *data, char *new_img, int byte_per_pixel, int size_line, int endian)
{
	int x;
	int y;
	int x_x;
	int new_point_x;
	int new_point_y;
	int res;
	t_old_ship *old_ship;
//	char **delete;

//	delete = ft_crreate_temp();
	y = 0 - ((size_line / 4) / 2);
	old_ship = data->old_ship;
	while (old_ship->cur && y < 40)
	{
		x_x = 0 - ((size_line / 4) / 2);	//((size_line / 4(pixels)) / 2(middle of ship)) = (Together means coordinates relative to the center)
		x = 0;
		while (x < size_line)
		{
			new_point_x = (int)((x_x * data->angle->x_cos) - (y * data->angle->x_sin));
			new_point_y = (int)((x_x * data->angle->x_sin) + (y * data->angle->x_cos)); 	// maybe error because  i don`t check uninitiated of point
			if (new_point_x >= -20 && new_point_y >= -20 && new_point_x <= 20 && new_point_y <= 20)   // rewrite latter
			{
				res = (size_line / 2) + (new_point_x * byte_per_pixel) + ((size_line * 20) + (new_point_y * size_line));
//				if (old_ship->cur[x] == -1)
//					delete[new_point_y + 20][new_point_x + 20] = 'X';
//				ft_printf("res: %d %d %d %d\n",old_ship->cur[x], old_ship->cur[x + 1], old_ship->cur[x + 2], old_ship->cur[x + 3] );
				if (old_ship->cur[x] == -1) {
					new_img[res] = old_ship->cur[x];
					new_img[res + 1] = old_ship->cur[x + 1];
					new_img[res + 2] = old_ship->cur[x + 2];
					new_img[res + 3] = old_ship->cur[x + 3];
				}
			}
			x_x++;
			x += byte_per_pixel;
		}
		y++;
		old_ship->cur += size_line;
	}
//	ft_print_temp(delete);
}

void	ft_allocate_old_ship(t_data *data)
{
	data->old_ship->cur = mlx_get_data_addr(data->figure->img, &data->old_ship->bits_per_pixel,
									   &data->old_ship->size_line, &data->old_ship->endian);
}

void	ft_rotate_ship(t_data *data)
{

	char *tmp;
	void *new;
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;

	new = mlx_new_image(data->mlx, data->figure->x, data->figure->y);
	tmp = mlx_get_data_addr(new, &bits_per_pixel, &size_line, &endian);
	ft_allocate_old_ship(data);
	ft_do_magic(data, tmp, bits_per_pixel / 8, size_line, endian);
//	mlx_put_image_to_window(data->mlx, data->win, new, 100, 100);
	mlx_destroy_image(data->mlx, data->figure->img);
	data->figure->img = new;
	data->center_of_mass->x = 0.0;
}