#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_map_render(t_mlx *init, t_tile **tile_map, int x, int y)
{
	int	size;

	size = SIZE;
	while (y--)
	{
		x = init->lines;
		while (x--)
		{
			if (tile_map[y][x].type == '1')
			{
				init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/corner_ld.xpm", &size, &size);
				mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
			}
			else if (tile_map[y][x].type == '0')
			{
                init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/floor.xpm", &size,	&size);
                mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
			}
			else if (tile_map[y][x].type == 'P')
			{
                init->img = mlx_xpm_file_to_image(init->mlx, "personaggio/ReUmanoFloor.xpm", &size,	&size);
                mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
				init->kingo.x=x;
				init->kingo.y=y;
			}
		}
	}
}
