#include "include/cub3d.h"

void drawing_walls(t_cub *cub, t_var *v)
{
    int textur_ofs_X;
    int textur_ofs_Y;
    if (cub->distanc_if_v_or_h)
        textur_ofs_X = (int)v->Wally % 64;
    else
        textur_ofs_X = (int)v->Wallx % 64;
    for (int y = v->start_y; y < v->end_y; y++)
    {
        int color;
        int distancfromtop = y + (v->walstrph / 2) - (WINDOW_HEIGHT / 2);
        textur_ofs_Y = distancfromtop * ((double)64 / v->walstrph);
        if (cub->map[((int)(v->Wally / 64))][(((int)(v->Wallx / 64)))] == 'D')
            color = cub->txts->data_txt_dor[(64 * textur_ofs_Y) + textur_ofs_X];
        else
        {
            if (cub->distanc_if_v_or_h)
            {

                if (cub->player.right)
                    color = cub->txts->data_txt_ea[(64 * textur_ofs_Y) + textur_ofs_X];
                else
                    color = cub->txts->data_txt_we[(64 * textur_ofs_Y) + textur_ofs_X];
            }
            else
            {
                if (cub->player.up)
                    color = cub->txts->data_txt_no[(64 * textur_ofs_Y) + textur_ofs_X];
                else
                    color = cub->txts->data_txt_so[(64 * textur_ofs_Y) + textur_ofs_X];
            }
            // cub->data_image[(cub->win_width * y) + v->i] = color;
        }
        cub->data_image[(WINDOW_WIDTH * y) + v->i] = color;
    }
}
