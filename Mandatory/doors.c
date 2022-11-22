#include "include/cub3d.h"
int check_arry(int *b, int x, t_cub *cub)
{
    int i;

    i = 0;
    while (i < cub->k)
    {
        if (b[i] == x)
            return 0;
        i++;
    }
    return 1;
}

void up_to_fault(t_cub *cub, int x, int y, int i)
{
    // printf("%c | %d | %d \n", cub->map[y][x], y, x);
    if (cub->map[y][x] == 'D')
    {
        cub->map[y][x] = '0';
        if (check_arry(cub->xx_D, x, cub) || check_arry(cub->yy_D, y, cub))
        {
            cub->xx_D[cub->k] = x;
            cub->yy_D[cub->k] = y;
            cub->k++;
        }
        // exit(3);
    }
    else if (cub->map[y][x] == '0')
    {
        i = 0;
        printf("hna walh ta hna\n");
        while (i < cub->k)
        {
            printf("%d | %d", cub->yy_D[i], cub->xx_D[i]);
            if (cub->map[cub->yy_D[i]][cub->xx_D[i]] == '0')
            {

                if (x == cub->xx_D[i] && y == cub->yy_D[i])
                {
                    cub->map[cub->yy_D[i]][cub->xx_D[i]] = 'D';
                    break;
                }
            }
            i++;
        }
        // printf("hna harna\n");
    }
    printf("%d\n", cub->k);
}

void open_and_close_doors(t_cub *cub)
{
    double mapGrindIndexX;
    double mapGrindIndexY;
    int x = 0;
    int y = 0;
    int i = 0;
    int bk = 0;
    cub->player.x_D = 0;
    cub->player.angle_of_player = fix_angle(cub->player.angle_of_player);
    // if (cub->player.angle_of_player == 0)
    // {
    //     mapGrindIndexX = cub->player.beg_x + 64;
    //     mapGrindIndexY = cub->player.beg_y;
    //     x = mapGrindIndexX / 64;
    //     y = mapGrindIndexY / 64;
    // }
    // if (cub->player.angle_of_player == 1.5 * M_PI)
    // {
    //     printf("simo\n");
    //     mapGrindIndexX = cub->player.beg_x;
    //     mapGrindIndexY = cub->player.beg_y;
    //     x = mapGrindIndexX / 64;
    //     y = mapGrindIndexY / 64 - 1;
    //     printf("%d | %d \n", x , y);
    // }
    // if (cub->player.angle_of_player == M_PI)
    // {
    //     mapGrindIndexX = cub->player.beg_x;
    //     mapGrindIndexY = cub->player.beg_y - 64;
    //     x = mapGrindIndexX / 64;
    //     y = mapGrindIndexY / 64;
    // }

    // if (cub->player.angle_of_player > 0 && cub->player.angle_of_player < M_PI_2)
    // {

    //     mapGrindIndexX = cub->player.beg_x + 40;
    //     mapGrindIndexY = cub->player.beg_y + 40;
    //     x = mapGrindIndexX / 64;
    //     y = mapGrindIndexY / 64;
    //     printf(" pr %c\n", cub->map[y][x]);
    // }
    if (cub->player.angle_of_player < M_PI && cub->player.angle_of_player > M_PI_2)
    {

        mapGrindIndexX = cub->player.beg_x;
        mapGrindIndexY = cub->player.beg_y;
        x = mapGrindIndexX / 64;
        y = mapGrindIndexY / 64 + 1;
        while (bk <= cub->k)
        {
            if (cub->yy_D[bk] == y && cub->xx_D[bk] == x)
                cub->player.x_D = 1;
            bk++;
        }
        if (cub->map[y][x] == 'D')
            ;
        else if (cub->player.x_D == 1)
            ;
        else
        {
            y -= 1;
            x -= 1;
        }
        bk = 0;
        cub->player.x_D = 0;
        printf(" sd %c\n", cub->map[y][x]);
    }
    if (cub->player.angle_of_player > M_PI && cub->player.angle_of_player < 1.5 * M_PI)
    {

        mapGrindIndexX = cub->player.beg_x;
        mapGrindIndexY = cub->player.beg_y;
        x = mapGrindIndexX / 64;
        y = mapGrindIndexY / 64 - 1;
        while (bk <= cub->k)
        {
            if (cub->yy_D[bk] == y && cub->xx_D[bk] == x)
                cub->player.x_D = 1;
            bk++;
        }
        if (cub->map[y][x] == 'D')
            ;
        else if (cub->player.x_D == 1)
            ;
        else
        {
            x -= 1;
            y += 1;
        }
        bk = 0;
        cub->player.x_D = 0;

    }
    if (cub->player.angle_of_player > 1.5 * M_PI)
    {
        mapGrindIndexX = cub->player.beg_x;
        mapGrindIndexY = cub->player.beg_y;
        x = mapGrindIndexX / 64 + 1;
        y = mapGrindIndexY / 64;
        while (bk <= cub->k)
        {
            if (cub->yy_D[bk] == y && cub->xx_D[bk] == x)
                cub->player.x_D = 1;
            bk++;
        }
        if (cub->map[y][x] == 'D')
            ;
        else if (cub->player.x_D == 1)
            ;
        else
        {
            y -= 1;
            x -= 1;
        }
        bk = 0;
        cub->player.x_D = 0;
    }
    if (cub->player.angle_of_player > 0 && cub->player.angle_of_player < M_PI_2)
    {

        mapGrindIndexX = cub->player.beg_x;
        mapGrindIndexY = cub->player.beg_y;
        x = mapGrindIndexX / 64;
        y = mapGrindIndexY / 64 + 1;
        while (bk <= cub->k)
        {
            if (cub->yy_D[bk] == y && cub->xx_D[bk] == x)
                cub->player.x_D = 1;
            bk++;
        }
        if (cub->map[y][x] == 'D')
            ;
        else if (cub->player.x_D == 1)
            ;
        else
        {
            y -= 1;
            x += 1;
        }
        bk = 0;
        cub->player.x_D = 0;
    }
    up_to_fault(cub, x, y, i);
}
