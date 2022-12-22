#include "so_long.h"

void	ft_wall_render(t_mlx *init, t_tile **tile_map, int size, int x, int y)
{
	if (x == 0 && y == 0)
	{		
		init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/corner_ul.xpm", &size, &size);
		mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
		mlx_destroy_image(init->mlx, init->img);
	}
	else if (x == (init->x) - 1 && y == 0)
	{		
		init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/corner_ur.xpm", &size, &size);
		mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
		mlx_destroy_image(init->mlx, init->img);
	}
	else if (x == 0 && (y + 1) == (init->y))
	{		
		init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/corner_ld.xpm", &size, &size);
		mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
		mlx_destroy_image(init->mlx, init->img);
	}
	else if (x == (init->x) - 1 && (y + 1) == (init->y))
	{		
		init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/corner_rd.xpm", &size, &size);
		mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
		mlx_destroy_image(init->mlx, init->img);
	}
	else if (y == 0)
	{		
		init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/wall_up.xpm", &size, &size);
		mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
		mlx_destroy_image(init->mlx, init->img);
	}
	else if (x == 0)
	{		
		init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/wall_l.xpm", &size, &size);
		mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
		mlx_destroy_image(init->mlx, init->img);
	}
	else if (x == (init->x) - 1)
	{		
		init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/wall_r.xpm", &size, &size);
		mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
		mlx_destroy_image(init->mlx, init->img);
	}
	else if (y == init->y)
	{		
		init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/wall_down.xpm", &size, &size);
		mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
		mlx_destroy_image(init->mlx, init->img);
	}
	else
	{		
		init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/wall_down.xpm", &size, &size);
		mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
		mlx_destroy_image(init->mlx, init->img);
	}
	return;

}
void	ft_map_render(t_mlx *init, t_tile **tile_map, int x, int y)
{
	int	size;

	size = SIZE;
	while (y--)
	{
		x = init->x;
		while (x--)
		{
			if (tile_map[y][x].type == '1')
				ft_wall_render(init, tile_map, size, x, y);
			else if (tile_map[y][x].type == '0')
			{
                init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/floor.xpm", &size,	&size);
                mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
				mlx_destroy_image(init->mlx, init->img);
			}
			else if (tile_map[y][x].type == 'P')
			{
                init->img = mlx_xpm_file_to_image(init->mlx, "personaggio/ReUmanoFloor.xpm", &size,	&size);
                mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
				mlx_destroy_image(init->mlx, init->img);
				init->kingo.x=x;
				init->kingo.y=y;
			}
			else if (tile_map[y][x].type == 'E')
			{
                if (init->collectible > 0)
				{
					init->img = mlx_xpm_file_to_image(init->mlx, "door/door_closed.xpm", &size,	&size);
                	mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
					mlx_destroy_image(init->mlx, init->img);
				}
				else
				{
					init->img = mlx_xpm_file_to_image(init->mlx, "door/door_open.xpm", &size,	&size);
                	mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
					mlx_destroy_image(init->mlx, init->img);
				}
			}
			else if (tile_map[y][x].type == 'C')
			{
                init->img = mlx_xpm_file_to_image(init->mlx, "wall_tiles/wall_down.xpm", &size,	&size);
                mlx_put_image_to_window(init->mlx, init->win, init->img, tile_map[y][x].position.x, tile_map[y][x].position.y);
				mlx_destroy_image(init->mlx, init->img);
			}
		}
	}
}
