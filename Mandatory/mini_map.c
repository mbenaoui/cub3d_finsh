#include "include/cub3d.h"


int a, b;
void paint_wall(t_cub *cub)
{
    int i, j;
    i = (cub->player.beg_y / 64) - 4;
    if (i < 0)
        i = 0;
    while (cub->map[i] && i < (cub->player.beg_y / 64) + 4)
    {
        j = (cub->player.beg_x / 64) - 4;
        if (j < 0)
            j = 0;
        while (cub->map[i][j] && j < (cub->player.beg_x / 64) + 4)
        {
            if (cub->map[i][j] == '1')
                mlx_put_image_to_window(cub->mlx, cub->window, cub->txts->txt_no, (j * 64 - a), (i * 64 - b));
            j++;
        }
        i++;
    }
}

void player_drawing(t_cub *cub)
{
    int x;
    int y;

    y = cub->player.beg_y - 10;
    while (y < cub->player.beg_y + 10)
    {
        x = cub->player.beg_x - 10;
        while (x < cub->player.beg_x + 10)
        {
            mlx_pixel_put(cub->mlx, cub->window, (x - a), (y - b), 0xf0f0ffff / 8);
            x++;
        }
        y++;
    }
}

int weapon(t_cub *cub)
{
    int t[2];
    char *str;
    if (cub->index %2 == 0)
        str = mlx_xpm_file_to_image(cub->mlx, "weapon_2.xpm", &t[0], &t[1]);
    else
        str = (char *)mlx_xpm_file_to_image(cub->mlx, "weapon.xpm", &t[0], &t[1]);
    int i = 0;
    if (!cub->flag_wpn)
    {
        mlx_put_image_to_window(cub->mlx, cub->window, str, WINDOW_WIDTH / 2 - 200, WINDOW_HEIGHT - 200);
        cub->flag_wpn = 1;
    }
    else
    {
        mlx_put_image_to_window(cub->mlx, cub->window, str, WINDOW_WIDTH / 2 - 200, WINDOW_HEIGHT - 180);
        cub->flag_wpn = 0;
    }
    free(str);
    
    return 0;
}

void mini_map(t_cub *cub)
{

    
    if (cub->player.beg_x > 100)
        a = cub->player.beg_x - 100;
    else if (cub->player.beg_x <= 100)
        a = 100 - cub->player.beg_x;
    if (cub->player.beg_y > 100)
        b = cub->player.beg_y - 100;
    else if (cub->player.beg_y <= 100)
        b = 100 - cub->player.beg_y;
    paint_wall(cub);
    player_drawing(cub);
    // weapon(cub);
}
