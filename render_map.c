#include "so_long.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void ft_map_render(char c, t_mlx *init)
{
    int size;
    size = SIZE;
    c = '1';
    if (c == '1')
        {
            init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/corner_ld.xpm", &size, &size);
            mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
           // init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/corner_ld.xpm", &size, &size);
            mlx_put_image_to_window(init->mlx, init->win, init->img, 32, 32);
        }	
}

