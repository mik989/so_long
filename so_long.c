#include "so_long.h"

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
	t_tile **map;

	map = init->map;
	
	while (*init->map != NULL)
	{
		free(*init->map);
		init->map++;
	}
	free(map);
}

int ft_close(t_mlx *init)
{
	mlx_destroy_window(init->mlx, init->win);
	mlx_destroy_display(init->mlx);
	free(init->mlx);
	//free(init->win);
	//free(init->img);
	ft_freemap(init);
	exit(0);
	return (0);
}

int main()
{
	t_mlx	init;
	char *path_ber;
	char *array_map;
	//char *move;
	//char *col;
	init.collectible = 0;
	init.moves = 0;
	init.mlx = mlx_init();
	path_ber = "test.ber";
	array_map = ft_get_map(path_ber);
	init.map = ft_tilemap_alloc(array_map, &init);
	ft_init_map(init, array_map);
	init.win = mlx_new_window(init.mlx, (init.x * SIZE) + 40, (init.y * SIZE) + 40, "so_long");
	mlx_hook(init.win, 17, 0, ft_close, (void *)0);
	ft_map_render(&init, init.map, init.x, init.y);
	mlx_string_put(init.mlx, init.win, 20, 15, 0xffffffff, "Moves :");
	//move = ft_itoa(init.moves);
	//mlx_string_put(init.mlx, init.win, 80, 15, 0xffffffff, ft_itoa(init.moves));
	//free(move);
	mlx_string_put(init.mlx, init.win, 150, 15, 0xffffffff, "Collectible :");
	//col = ft_itoa(init.moves);
	//mlx_string_put(init.mlx, init.win, 250, 15, 0xffffffff, ft_itoa(init.collectible));
	//free(col);
	mlx_key_hook(init.win, key_input, &init);
	mlx_loop(init.mlx);

	//free(array_map);
	//free(map);
	return(0);
}

