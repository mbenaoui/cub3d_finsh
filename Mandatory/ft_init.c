#include "include/cub3d.h"

t_cub *int_cub()
{
    t_cub *cub;
    cub = ft_calloc(sizeof(t_cub), 1);
    cub->rgb_c = ft_calloc(sizeof(t_color), 1);
    cub->rgb_f = ft_calloc(sizeof(t_color), 1);
    cub->txts = ft_calloc(sizeof(t_textures), 1);
    cub->xx_D = ft_calloc(sizeof(int), cub->size_d + 1);
    cub->yy_D = ft_calloc(sizeof(int), cub->size_d + 1);
    return cub;
}

void ft_init_mlx(t_cub *cub)
{
    int arr[3];
    cub->index = 0;
    cub->flag_wpn = 0;
    cub->flag_over = 0;
    cub->index_g_ov = 0;
    cub->k = 0;
    width_and_height_window(cub);
    position_of_player(cub);
    cub->mlx = mlx_init();
    cub->window = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
    init_textures(cub);
}
