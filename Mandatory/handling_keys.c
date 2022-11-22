#include "include/cub3d.h"
void next_step_is_not_wall(t_cub *cub, int stepx, int stepy)
{
    if (cub->map[(cub->player.beg_y + stepy) / 64][(cub->player.beg_x + stepx) / 64] != '1' && cub->map[(cub->player.beg_y + stepy) / 64][(cub->player.beg_x + stepx) / 64] != 'D')
    {
        cub->player.beg_x += stepx;
        cub->player.beg_y += stepy;
    }
}
int hasWallat(double x, double y, t_cub *cub, int key)
{
    if (x < 0 || x > cub->win_width || y < 0 || y > cub->win_height)
        return 1;
    int mapGrindIndexX = x / 64;
    int mapGrindIndexY = y / 64;
    if (cub->map[mapGrindIndexY][mapGrindIndexX] != '1')
    {
        if (cub->map[mapGrindIndexY][mapGrindIndexX] == 'D')
            return 1;
        return 0;
    }
    return (1);
}
int handling_keys(t_cub *cub, int key)
{
    int stepx = 0;
    int stepy = 0;
    int x = 0;
    int y = 0;
    double mapGrindIndexX;
    double mapGrindIndexY;
    if (key == ESC)
        exit(ESC);
    if (key == 125)
        cub->index++;
    if (key == 126)
        cub->index--;

    if (key == 49)
        open_and_close_doors(cub);

    if (key == UP_W)
    {
        stepx = MOVE * cos(cub->player.angle_of_player);
        stepy = MOVE * sin(cub->player.angle_of_player);
    }
    if (key == DOWN_S)
    {
        stepx = -MOVE * cos(cub->player.angle_of_player);
        stepy = -MOVE * sin(cub->player.angle_of_player);
    }
    if (key == UP_A)
    {
        stepx = MOVE * cos(cub->player.angle_of_player - M_PI_2);
        stepy = MOVE * sin(cub->player.angle_of_player - M_PI_2);
    }
    if (key == UP_D)
    {
        stepx = -MOVE * cos(cub->player.angle_of_player - M_PI_2);
        stepy = -MOVE * sin(cub->player.angle_of_player - M_PI_2);
    }
    if (key == RIGHT)
        cub->player.angle_of_player += ROTAIONA_SPEED;
    if (key == LEFT)
        cub->player.angle_of_player -= ROTAIONA_SPEED;
        stepx += cub->player.beg_x;
        stepy += cub->player.beg_y;
    cub->player.angle_of_player = fix_angle(cub->player.angle_of_player);
   // next_step_is_not_wall(cub, stepx, stepy);
    if (!hasWallat(stepx, stepy, cub, key))
    {
        cub->player.beg_x = stepx;
        cub->player.beg_y = stepy;
    }
    return 0;
}
