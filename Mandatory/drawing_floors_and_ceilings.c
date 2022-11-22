#include "include/cub3d.h"

void drawing_floors(t_cub *cub, int color)
{
    int i = WINDOW_HEIGHT / 2;
    int j;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
        {
            cub->data_image[i * WINDOW_WIDTH + j] = color;
            j++;
        }
        i++;
    }
}

void drawing_ceilings(t_cub *cub, int color)
{
    int i = 0;
    int j;
    while (i < WINDOW_HEIGHT / 2)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
        {
            cub->data_image[i * WINDOW_WIDTH + j] = color;
            j++;
        }
        i++;
    }
}

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

void drawing_floors_and_ceilings(t_cub *cub)
{
    drawing_floors(cub, create_trgb(150, cub->rgb_f->_r, cub->rgb_f->_g, cub->rgb_f->_b));
    drawing_ceilings(cub, create_trgb(100, cub->rgb_c->_r, cub->rgb_c->_g, cub->rgb_c->_b));
}
