#include "so_long.h"

void	ft_move_up(t_mlx *init, int x, int y)
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
	return ;
}

void	ft_move_down(t_mlx *init, int x, int y)
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
void	ft_move_left(t_mlx *init, int x, int y)
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
void	ft_move_right(t_mlx *init, int x, int y)
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
		ft_move_up(init, x, y);
	else if (keycode == 65364 || keycode == 115)
		ft_move_down(init, x, y);
	else if (keycode == 65361 || keycode == 97)
		ft_move_left(init, x, y);
	else if (keycode == 65363 || keycode == 100)
		ft_move_right(init, x, y);
	//mlx_clear_window(init->mlx, init->win);
	//mlx_put_image_to_window(init->mlx, init->win, init->img, 20, 15);
	ft_map_render(init, init->map, init->x, init->y);
	//init->img = mlx_new_image(init->mlx, (init->x * SIZE) + 40, 20);
	//mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
	//mlx_destroy_image(init->mlx, init->img);
	mlx_string_put(init->mlx, init->win, 20, 15, 0xffffffff, "Moves :");
	//move = ft_itoa(init->moves);
	//mlx_string_put(init->mlx, init->win, 80, 15, 0xffffffff, move);
	//free(move);
	mlx_string_put(init->mlx, init->win, 150, 15, 0xffffffff, "Collectible :");
	//col = ft_itoa(init->collectible);
	//mlx_string_put(init->mlx, init->win, 250, 15, 0xffffffff, col);
		//free(col);
	return (0);
}
