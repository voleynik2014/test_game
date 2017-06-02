#include "fdf.h"

void    ft_print_figure(t_data *data)
{
    int x;
    int y;

    x = (int)data->board->x;
    y = (int)data->board->y;
    while (x > data->figure->sideLeft_x)
    {
        mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
        x--;
        y++;
    }
    while (x < data->figure->sideRight_x)
        mlx_pixel_put(data->mlx, data->win, x++, y, 0xFF0000);
    while (x > data->figure->head_x)
    {
        mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
        x--;
        y--;
    }
}

void	ft_clear_img(t_data *data)
{
	int x;
	int y;

	x = (int)data->board->x;
	while (x <= data->board->x + data->figure->x)
	{
		y = (int)data->board->y;
		while (y <= data->board->y + data->figure->y)
			mlx_pixel_put(data->mlx, data->win, x, y++, 0x000000);
		x++;
	}
}

void	ft_print_img(t_data *data)
{
	if (data->board->x < BOARD_WIDTH && data->board->x > 0 && data->board->y < BOARD_HEIGHT && data->board->y > 0) {
//		ft_clear_img(data);
		mlx_put_image_to_window(data->mlx, data->win, data->figure->img, (int)data->board->x, (int)data->board->y);
	}
}

void    ft_put_player_on_the_board(t_data *data)
{
	if (data->figure->img)
		return (ft_print_img(data));
	else {
		data->figure->x = 20;
		data->figure->y = 20;
	}
//	if (data->board->x < BOARD_WIDTH && data->board->x > 0 && data->board->y < BOARD_HEIGHT && data->board->y > 0)
//	{
//		clear_player(data);
//    data->figure->head_x = (int)data->board->x;
//    data->figure->sideLeft_x = (int)data->board->x - (data->figure->x / 2);
//    data->figure->sideRight_x = (int)data->board->x + (data->figure->x / 2);
//    data->figure->head_y = (int)data->board->y;
//    data->figure->sideLeft_y = (int)data->board->y + data->figure->y;
//    data->figure->sideRight_y = (int)data->board->y + data->figure->y;
//    ft_print_figure(data);
//	} else {
		data->center_of_mass->x = 0;
		data->center_of_mass->y = 0.0;
//	}
}

void	ft_delete_fs(char *img, int byte_per_pixel, int size_of_line, int end)
{
	int x;
	int y;

//	img += size_of_line * 10;
	y = 10;
	while (++y < 30)
	{
		x = (size_of_line * 10) + (byte_per_pixel * 10);
		while (x < (size_of_line * 10 ) + (byte_per_pixel * 30)) {
			img[x] = 255;
			img[x + 1] = 255;
			img[x + 2] = 255;
			img[x + 3] = end;
//			ft_printf("%d %d %d %d\n", img[x], img[x + 1], img[x + 2], img[x + 3]);
			x += byte_per_pixel;
		}
		img += size_of_line;
	}
}

int     ft_triangle(t_data *data)
{
	int y;
	int i;
	int z;
	char *tmp;

	if (0)
	{
		data->center_of_mass->x = 0.0;
		data->center_of_mass->y = 0.0;
		data->figure = (t_tri *)malloc(sizeof(t_tri) * 1);
		data->figure->x = 40;
		data->figure->y = 40;
		data->figure->img = mlx_new_image(data->mlx, data->figure->x, data->figure->y);
		tmp = mlx_get_data_addr(data->figure->img, &i, &y, &z);
		ft_delete_fs(tmp, i / 8, y, z);
		ft_put_player_on_the_board(data);
		return 0;
	}
    data->figure = (t_tri *)malloc(sizeof(t_tri) * 1);
	data->figure->img = mlx_xpm_file_to_image(data->mlx, "texture/bakuden_alone.xpm", &data->figure->x, &data->figure->y);
	ft_put_player_on_the_board(data);
    return 1;
}