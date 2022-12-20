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
	init->lines = x - 1;
	init->columns = y;
	tilemap = malloc(sizeof(t_tile *) * (y + 1));
	tilemap[y] = 0;
	tilemap[x] = 0;

	while (y--)
	{
		//tilemap[y] = malloc(sizeof(t_tile) * (x));
		//tilemap[y] = NULL;
	//	y--;
		tilemap[y] = ft_calloc(sizeof(t_tile), x );
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
		if (x > 0)
			init.map[y][x].left = &init.map[y][x - 1];
		if (y > 0)
			init.map[y][x].up = &init.map[y - 1][x];
		if (x < init.lines)
			init.map[y][x].right = &init.map[y][x + 1];
		if (y < init.columns)
			init.map[y][x].down = &init.map[y + 1][x];
		xbuff += SIZE;
		x++;
		i++;
	}
}