#include "so_long.h"

void	ft_error(char *error, t_mlx *init)
{
	mlx_destroy_display(init->mlx);
	free(init->mlx);
	ft_putstr_fd(error, 2);
	exit (0);
}

t_tile	**ft_tilemap_alloc(char *map, t_mlx *init)
{
	t_tile	**tilemap;
	t_check	check;
	int		y;
	int		x;
	int		i;

	check.exit = 0;
	check.player = 0;
	y = 1;
	x = 0;
	i = 0;
	while (map[i])
	{
		if (y == 1)
			x++;
		if (map[i] == '\n' && map[i + 1] != '\0')
			y++;
		if (map[i] == 'C')
			init->collectible += 1;
		if (map[i] == 'E')
			check.exit += 1;
		if (map[i] == 'P')
			check.player += 1;
		i++;
	}
	init->x = x - 1;
	init->y = y;
	if ((check.exit > 1 || check.player > 1) || (check.exit == 0 || check.player == 0))
	{
		free(map);
		ft_error("Error! Invalid map\n", init);
	}
	tilemap = (t_tile **)malloc(sizeof(t_tile *) * (y + 1));
	while (y--)
		tilemap[y] = (t_tile *)malloc(sizeof(t_tile) * (x));
	return (tilemap);
}

void	ft_init_map(t_mlx init, char *map)
{
	int	x;
	int	y;
	int	i;
	int	xbuff;
	int	ybuff;

	x = 0;
	y = 0;
	i = 0;
	xbuff = 20;
	ybuff = 20;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			ybuff += SIZE;
			y++;
			xbuff = 20;
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
	free(map);
}
