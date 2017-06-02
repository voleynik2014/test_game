cmake_minimum_required(VERSION 3.6)
project(untitled4)

set(CMAKE_C_STANDARD 99)
set( CMAKE_EXE_LINKER_FLAGS  "-lmlx -framework OpenGL -framework AppKit")
#set( CMAKE_EXE_LINKER_FLAGS  "-L/usr/X11/lib -lmlx -lX11 -lXext ")
set(SOURCE_FILES src/main.c libft/author
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_color.c
        libft/ft_get_next_line.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_itoa_base.c
        libft/ft_itoa_ll.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_padding.c
        libft/ft_padding_str.c
        libft/ft_printf.c
        libft/ft_printf.h
        libft/ft_put_uintmax.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putnstr.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_putwchar.c
        libft/ft_putwchar_fd.c
        libft/ft_specifiers.c
        libft/ft_specifiers2.c
        libft/ft_squere.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strndup.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_type_di.c
        libft/ft_type_ox.c
        libft/ft_type_s.c
        libft/ft_type_wchar.c
        libft/get_next_line.h
        libft/libft.h
        libft/Makefile
        libft/printflib.h src/player.c src/ft_move.c src/ft_start_location.c src/do_fire.c
#        includes/minilibx/mlx_clear_window.c
#        includes/minilibx/mlx_destroy_image.c
#        includes/minilibx/mlx_destroy_window.c
#        includes/minilibx/mlx_expose_hook.c
#        includes/minilibx/mlx_flush_event.c
#        includes/minilibx/mlx_get_color_value.c
#        includes/minilibx/mlx_get_data_addr.c
#        includes/minilibx/mlx_hook.c
#        includes/minilibx/mlx_init.c
#        includes/minilibx/mlx_int_anti_resize_win.c
#        includes/minilibx/mlx_int_do_nothing.c
#        includes/minilibx/mlx_int_get_visual.c
#        includes/minilibx/mlx_int_param_event.c
#        includes/minilibx/mlx_int_set_win_event_mask.c
#        includes/minilibx/mlx_int_str_to_wordtab.c
#        includes/minilibx/mlx_int_wait_first_expose.c
#        includes/minilibx/mlx_key_hook.c
#        includes/minilibx/mlx_lib_xpm.c
#        includes/minilibx/mlx_loop.c
#        includes/minilibx/mlx_loop_hook.c
#        includes/minilibx/mlx_mouse_hook.c
#        includes/minilibx/mlx_new_image.c
#        includes/minilibx/mlx_new_window.c
#        includes/minilibx/mlx_pixel_put.c
#        includes/minilibx/mlx_put_image_to_window.c
#        includes/minilibx/mlx_rgb.c
#        includes/minilibx/mlx_string_put.c
#        includes/minilibx/mlx_xpm.c
        src/handle_fire.c src/ft_delete_bullet.c src/enemy.c includes/enemy.h src/ft_rotate_ship.c src/background.c)
add_executable(untitled4 ${SOURCE_FILES})

include_directories(includes
                    /opt/X11/include)


#-lmlx -framework OpenGL -framework AppKit