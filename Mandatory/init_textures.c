#include "include/cub3d.h"

void init_textures(t_cub *cub)
{
    int arr[3];
    char *str;

    cub->txts->txt_ea = mlx_xpm_file_to_image(cub->mlx, cub->file_ea, &(arr[0]), &(arr[1]));
    cub->txts->txt_no = mlx_xpm_file_to_image(cub->mlx, cub->file_no, &(arr[0]), &(arr[1]));
    cub->txts->txt_so = mlx_xpm_file_to_image(cub->mlx, cub->file_so, &(arr[0]), &(arr[1]));
    cub->txts->txt_we = mlx_xpm_file_to_image(cub->mlx, cub->file_we, &(arr[0]), &(arr[1]));
    str = mlx_xpm_file_to_image(cub->mlx, "textures/DOOR_1A.xpm", &(arr[0]), &(arr[1]));
    if (!cub->txts->txt_ea || !cub->txts->txt_no || !cub->txts->txt_so || !cub->txts->txt_we || !str)
    {
        printf("textures : error1");
        exit(1);
    }
    cub->txts->data_txt_ea = (int *)mlx_get_data_addr(cub->txts->txt_ea, &(arr[0]), &(arr[1]), &(arr[2]));
    cub->txts->data_txt_no = (int *)mlx_get_data_addr(cub->txts->txt_no, &(arr[0]), &(arr[1]), &(arr[2]));
    cub->txts->data_txt_so = (int *)mlx_get_data_addr(cub->txts->txt_so, &(arr[0]), &(arr[1]), &(arr[2]));
    cub->txts->data_txt_we = (int *)mlx_get_data_addr(cub->txts->txt_we, &(arr[0]), &(arr[1]), &(arr[2]));
    cub->txts->data_txt_dor = (int *)mlx_get_data_addr(str, &(arr[0]), &(arr[1]), &(arr[2]));
    if (!cub->txts->data_txt_ea || !cub->txts->data_txt_no || !cub->txts->data_txt_so || !cub->txts->data_txt_we || !cub->txts->data_txt_dor)
    {
        printf("textures : error2");
        exit(1);
    }
    cub->txts->sprite = malloc(sizeof(char *) * 6);
    cub->txts->game_over = mlx_xpm_file_to_image(cub->mlx, "game_over.xmp", &arr[0], &arr[1]);
    cub->txts->sprite[0] = mlx_xpm_file_to_image(cub->mlx, "sprite/sprite_1.xpm", &arr[0], &arr[1]);
    cub->txts->sprite[1] = mlx_xpm_file_to_image(cub->mlx, "sprite/sprite_2.xpm", &arr[0], &arr[1]);
    cub->txts->sprite[2] = mlx_xpm_file_to_image(cub->mlx, "sprite/sprite_3.xpm", &arr[0], &arr[1]);
    cub->txts->sprite[3] = mlx_xpm_file_to_image(cub->mlx, "sprite/sprite_4.xpm", &arr[0], &arr[1]);
    cub->txts->sprite[4] = mlx_xpm_file_to_image(cub->mlx, "sprite/sprite_5.xpm", &arr[0], &arr[1]);
    cub->txts->sprite[5] = mlx_xpm_file_to_image(cub->mlx, "sprite/sprite_6.xpm", &arr[0], &arr[1]);
}