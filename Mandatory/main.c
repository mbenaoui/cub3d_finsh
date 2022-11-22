#include "include/cub3d.h"

void number_d(t_cub *cub)
{
    int i;
    int k;
    int j;

    i = 0;
    k = 0;
    while (cub->map[i])
    {
        j = 0;
        while (cub->map[i][j])
        {
            if (cub->map[i][j] == 'D')
                cub->size_d++;
            j++;
        }
        i++;
    }
}
int t_key;
int stepx;
int stepy;

int draw(t_cub *cub)
{
    cub->player.angle_of_player += cub->player.rotation_angle;
    stepx = round(cub->player.beg_x + (cos(cub->player.angle_of_player) * cub->player.walkDirection + sin(cub->player.angle_of_player) * cub->player.walk_side_Direction));
    stepy = round(cub->player.beg_y + (sin(cub->player.angle_of_player) * cub->player.walkDirection - cos(cub->player.angle_of_player) * cub->player.walk_side_Direction));
     cub->player.angle_of_player = fix_angle(cub->player.angle_of_player);
    if (!hasWallat(stepx + 0*stepx, stepy + 0*stepy, cub, t_key))
    {
        cub->player.beg_x = stepx;
        cub->player.beg_y = stepy;
    }
    int arr[3];
    mlx_clear_window(cub->mlx, cub->window);
    cub->player.ry_angle = cub->player.angle_of_player - 30 * (M_PI / 180);
    cub->image = mlx_new_image(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    cub->data_image = (int *)mlx_get_data_addr(cub->image, &arr[0], &arr[1], &arr[2]);
    drawing_floors_and_ceilings(cub);
    ray_casting(cub);
    mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
    mlx_destroy_image(cub->mlx, cub->image);
    return 0;
}

int move_t(int key, t_cub *cub)
{

    if (key == UP_W)
        cub->player.walkDirection = 0;
    if (key == DOWN_S)
        cub->player.walkDirection = 0;
    if (key == UP_A)
        cub->player.walk_side_Direction = 0;
    if (key == UP_D)
        cub->player.walk_side_Direction = 0;
    if (key == RIGHT)
        cub->player.rotation_angle = 0;
    if (key == LEFT)
        cub->player.rotation_angle = 0;
    return 0;
}

int move(int key, t_cub *cub)
{
    t_key = key;
    stepx = 0;
    stepy = 0;
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
        cub->player.walkDirection = MOVE;
    if (key == DOWN_S)
        cub->player.walkDirection = -MOVE;
    if (key == UP_A)
        cub->player.walk_side_Direction = MOVE;
    if (key == UP_D)
        cub->player.walk_side_Direction = -MOVE;
    if (key == RIGHT)
    {
        cub->player.rotation_angle = 0.05;
        //cub->player.angle_of_player = fix_angle(cub->player.angle_of_player);
    }
    if (key == LEFT)
    {
        cub->player.rotation_angle = -0.05;
        //cub->player.angle_of_player = fix_angle(cub->player.angle_of_player);
    }

    // stepx = round(cub->player.beg_x + (cos(cub->player.angle_of_player) * cub->player.walkDirection + sin(cub->player.angle_of_player) * cub->player.walk_side_Direction));
    // stepy = round(cub->player.beg_y + (sin(cub->player.angle_of_player) * cub->player.walkDirection - cos(cub->player.angle_of_player) * cub->player.walk_side_Direction));

    // if (!hasWallat(stepx, stepy, cub, key))
    // {
    //     cub->player.beg_x = stepx;
    //     cub->player.beg_y = stepy;
    // }
    return 0;
}
int main(int agrc, char **argv)
{

    if (agrc != 2)
        return 1;
    t_cub *cub;
    cub = int_cub();

    check_map_valid(cub, argv[1]);
    ft_init_mlx(cub);
    number_d(cub);
    // mlx_loop_hook(cub->mlx, game_over, cub);
    mlx_hook(cub->window, 2, 0, move, cub);
    mlx_loop_hook(cub->mlx, draw, cub);
    mlx_hook(cub->window, 3, 1L << 1, move_t, cub);

    mlx_loop(cub->mlx);
    free_tab(cub->lines);

    return 0;
}
