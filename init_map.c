#include "so_long.h"

t_tile	**ft_tilemap_alloc(char *map, t_mlx *init)
{
	t_tile	**tilemap;
	int		y;
	int		x;
	int		i;

	y = 1;
	x = 0;
	i = 0;
	while (map[i])
	{
		if (y == 1)
			x++;
		if (map[i] == '\n' && map[i + 1] != '\0')
			y++;
		i++;
	}
	init->x = x - 1;
	init->y = y;
    
	tilemap = (t_tile**)malloc(sizeof(t_tile *) * (y + 1));
	//t_tile tilemap[(y-1)*y+(x-1)];
    //tilemap = malloc(sizeof(t_tile) * (y + 1)*(x));
    
	//tilemap[y] = 0;
	//tilemap[x] = 0;

	while (y--)
	{
		tilemap[y] = (t_tile *)malloc(sizeof(t_tile) * (x));
		//tilemap[y][x] = (t_tile **)0;
	//	y--;
		//tilemap[y] = ft_calloc(sizeof(t_tile), x );
		// tilemap[] = NULL;
	}
	return (tilemap);
}

void	ft_init_map(t_mlx init, char *map)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int xbuff = 0;
	int ybuff = 0;

	while (map[i])
	{
		if (map[i] == '\n')
		{
			ybuff += SIZE;
			y++;
			xbuff = 0;
			x = 0;
			i++;
		}

		init.map[y][x].position.x = xbuff;
		init.map[y][x].position.y = ybuff;
		init.map[y][x].type = map[i];
		init.map[y][x].ori_type = map[i];
		if (x > 0)
			init.map[y][x].left = &init.map[y][x - 1];
		if (y > 0)
			init.map[y][x].up = &init.map[y - 1][x];
		if (x < init.x)
			init.map[y][x].right = &init.map[y][x + 1];
		if (y < init.y)
			init.map[y][x].down = &init.map[y + 1][x];
		xbuff += SIZE;
		x++;
		i++;
	}
}