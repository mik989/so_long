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
int ft_close()
{
	exit(0);
	return (0);
}
int	key_input(int keycode, t_mlx *vars)
{
	vars = vars;
	if (keycode == 65307)
		ft_close();
	else if (keycode == 65362 || keycode == 119)
		printf("UP\n");
	else if (keycode == 65364 || keycode == 115)
		printf("DOWN\n");
	else if (keycode == 65361 || keycode == 97)
		printf("LEFT\n");
	else if (keycode == 65363 || keycode == 100)
		printf("RIGHT\n");
	return (0);
}

int main(void)
{
	t_mlx	init;
	t_tile	**map;
	char *path_ber;
	char *array_map;

	//map = ft_calloc(1, 1);
	init.mlx = mlx_init();
	path_ber = "test.ber";
	array_map = ft_get_map(path_ber);
	map = ft_tilemap_alloc(array_map);
	ft_init_map(map, array_map);
	//init.img = mlx_xpm_to_image(init.mlx, init.relative_path, &init.img_width, &init.img_height);
	init.win = mlx_new_window(init.mlx, 500, 500, "so_long");
	//mlx_put_image_to_window(init.mlx, init.win, init.img, 0, 0);

	mlx_key_hook(init.win, key_input, &init);
	mlx_hook(init.win, 17, 0, ft_close, (void *)0);
		ft_map_render('1', &init);

	mlx_loop(init.mlx);
	//free(array_map);
	//free(map);
	return(0);
}

