#include "include/cub3d.h"

int game_over(t_cub *cub)
{
    if (cub->flag_over == 1)
        return (1);
    mlx_clear_window(cub->mlx, cub->window);
    mlx_put_image_to_window(cub->mlx, cub->window, cub->txts->game_over, 0, 0);
    mlx_put_image_to_window(cub->mlx, cub->window, cub->txts->sprite[cub->index_g_ov], WINDOW_WIDTH / 2 - 400, WINDOW_HEIGHT - 300);
    int f = 0;
    while (f < 70000000)
        f++;
    cub->index_g_ov++;
    if (cub->index_g_ov == 6)
        cub->index_g_ov = 0;
    return (0);
}