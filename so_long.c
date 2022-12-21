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
	t_tile **map;
	map = init->map;
	int y;
	y = init->y;
	while (map[y--])
	{
		free(map[y]);
	}
	free(map);
}
int ft_close(t_mlx *init)
{
	mlx_destroy_window(init->mlx, init->win);
	free(init->mlx);
	//free(init->win);
	//free(init->img);
	//ft_freemap(init);
	exit(0);
	return (0);
}
int	key_input(int keycode, t_mlx *init)
{
	int x;
	int y;
	//char *move;
	//char *col;

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
			init->moves += 1;
		}
		else if (init->map[y][x].up->type == 'C')
		{
			init->map[y][x].up->type = 'P';
			init->map[y][x].type = '0';
			init->moves += 1;
			init->collectible -= 1;
		}
		else if (init->map[y][x].up->type == 'E' && init->collectible == 0)
			ft_close(init);
	}
	else if (keycode == 65364 || keycode == 115)
	{
		if (init->map[y][x].down->type == '0')
		{
			init->map[y][x].down->type = 'P';
			init->map[y][x].type = '0';
			init->moves += 1;
		}	
		else if (init->map[y][x].down->type == 'C')
		{
			init->map[y][x].down->type = 'P';
			init->map[y][x].type = '0';
			init->moves += 1;
			init->collectible -= 1;
		}
		else if (init->map[y][x].down->type == 'E' && init->collectible == 0)
			ft_close(init);
	}
	else if (keycode == 65361 || keycode == 97)
	{
		if (init->map[y][x].left->type == '0')
		{
			init->map[y][x].left->type = 'P';
			init->map[y][x].type = '0';
			init->moves += 1;
		}
		else if (init->map[y][x].left->type == 'C')
		{
			init->map[y][x].left->type = 'P';
			init->map[y][x].type = '0';
			init->moves += 1;
			init->collectible -= 1;
		}
		else if (init->map[y][x].left->type == 'E' && init->collectible == 0)
			ft_close(init);
	}
	else if (keycode == 65363 || keycode == 100)
	{
		if (init->map[y][x].right->type == '0')
		{
			init->map[y][x].right->type = 'P';
			init->map[y][x].type = '0';
			init->moves += 1;
		}	
		else if (init->map[y][x].right->type == 'C')
		{
			init->map[y][x].right->type = 'P';
			init->map[y][x].type = '0';
			init->moves = init->moves + 1;
			init->collectible -= 1;
		}
		else if (init->map[y][x].right->type == 'E' && init->collectible == 0)
			ft_close(init);
	}
	//mlx_clear_window(init->mlx, init->win);
	//mlx_put_image_to_window(init->mlx, init->win, init->img, 20, 15);
	ft_map_render(init, init->map, init->x, init->y);
	mlx_string_put(init->mlx, init->win, 20, 15, 255, "Moves :");
	//move = ft_itoa(init->moves);
	//mlx_string_put(init->mlx, init->win, 80, 15, 255, move);
	//free(move);
	mlx_string_put(init->mlx, init->win, 150, 15, 255, "Collectible :");
	//col = ft_itoa(init->collectible);
	//mlx_string_put(init->mlx, init->win, 250, 15, 255, col);
	//free(col);
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
	mlx_string_put(init.mlx, init.win, 20, 15, 255, "Moves :");
	//move = ft_itoa(init.moves);
	//mlx_string_put(init.mlx, init.win, 80, 15, 255, ft_itoa(init.moves));
	//free(move);
	mlx_string_put(init.mlx, init.win, 150, 15, 255, "Collectible :");
	//col = ft_itoa(init.moves);
	//mlx_string_put(init.mlx, init.win, 250, 15, 255, ft_itoa(init.collectible));
	//free(col);
	mlx_key_hook(init.win, key_input, &init);
	mlx_loop(init.mlx);

	//free(array_map);
	//free(map);
	return(0);
}

