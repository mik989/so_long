#include "so_long.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

char *ft_get_map(char *path_ber)
{
	int fd;	
	char *str;		
	char *buff;
	
	str = ft_calloc(1,1);
	fd = open(path_ber, O_RDONLY);	

	while(1)
	{
		buff = get_next_line(fd);		
		if(buff == NULL)
				{				
					close(fd);	
					free(buff);	
					break;
				}
		str = ft_strjoinf(str, buff);
		free(buff);
	}

	return(str);
}

void ft_freemap(t_mlx *init)
{
	int y;
	y = init->y;
	while (init->map[y--])
	{
		free(init->map[y]);
	}
	//free(init->map);
}
int ft_close(t_mlx *init)
{
	mlx_destroy_window(init->mlx, init->win);
	//ft_freemap(init);
	exit(0);
	return (0);
}
int	key_input(int keycode, t_mlx *init)
{
	int x;
	int y;

	x = init->kingo.x;
	y = init->kingo.y;
	if (keycode == 65307)
		ft_close(init);
	if (keycode == 65362 || keycode == 119)
	{
		if (init->map[y][x].up->type == '0')
		{
			init->map[y][x].up->type = 'P';
			init->map[y][x].type = '0';
		}
	}
	else if (keycode == 65364 || keycode == 115)
	{
		if (init->map[y][x].down->type == '0')
		{
			init->map[y][x].down->type = 'P';
			init->map[y][x].type = '0';
		}
	}
	else if (keycode == 65361 || keycode == 97)
	{
		if (init->map[y][x].left->type == '0')
		{
			init->map[y][x].left->type = 'P';
			init->map[y][x].type = '0';
		}
	}
	else if (keycode == 65363 || keycode == 100)
				{
					if (init->map[y][x].right->type == '0')
			{
			init->map[y][x].right->type = 'P';
			init->map[y][x].type = '0';
			}
		}
	ft_map_render(init, init->map, init->x, init->y);
	return (0);
}

int main(void)
{
	t_mlx	init;
	//t_tile	**map;
	char *path_ber;
	char *array_map;

	//map = ft_calloc(1, 1);
	init.mlx = mlx_init();
	path_ber = "test.ber";
	array_map = ft_get_map(path_ber);
	init.map = ft_tilemap_alloc(array_map, &init);
	ft_init_map(init, array_map);
	//init.img = mlx_xpm_to_image(init.mlx, init.relative_path, &init.img_width, &init.img_height);
	init.win = mlx_new_window(init.mlx, init.x * SIZE, init.y * SIZE, "so_long");
	//mlx_put_image_to_window(init.mlx, init.win, init.img, 0, 0);

	mlx_key_hook(init.win, key_input, &init);
	mlx_hook(init.win, 17, 0, ft_close, (void *)0);
	ft_map_render(&init, init.map, init.x, init.y);

	mlx_loop(init.mlx);

	//free(array_map);
	//free(map);
	return(0);
}

