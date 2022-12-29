#include "so_long.h"

void    ft_enemy_mov(t_mlx *init)
{
    int x;
    int y;
    x = init->enemy.x;
    y = init->enemy.y;
    if (x != init->kingo.x)
    {
        if (init->map[y][x].left->type == '0' && x > init->kingo.x)
        {
            init->map[y][x].left->type = 'F';
            ft_print_and_destroy(init, init->enemy_img.current_img, x - 1, y);
            init->enemy.x = init->kingo.x + 1;
            init->map[y][x].type = '0';
            ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
        }
        else if (init->map[y][x].right->type == '0' && x < init->kingo.x)
        {
            init->map[y][x].right->type = 'F';
            ft_print_and_destroy(init, init->enemy_img.current_img, x + 1, y);
            init->enemy.x = init->kingo.x - 1;
            init->map[y][x].type = '0';
            ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
        }
    }
    else if (y != init->kingo.y)
    {
        if (init->map[y][x].up->type == '0' && y > init->kingo.y)
        {
            init->map[y][x].up->type = 'F';
            ft_print_and_destroy(init, init->enemy_img.current_img, x, y - 1);
            init->enemy.y = init->kingo.y + 1;
            init->map[y][x].type = '0';
            ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
        }
        else if (init->map[y][x].down->type == '0' && y < init->kingo.y)
        {
            init->map[y][x].down->type = 'F';
            ft_print_and_destroy(init, init->enemy_img.current_img, x, y + 1);
            init->enemy.y = init->kingo.y - 1;
            init->map[y][x].type = '0';
            ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
        }
    }
    if (init->enemy.x == init->kingo.x && init->enemy.y == init->kingo.y)
        ft_close(init);
}

void	ft_move_up(t_mlx *init, int x, int y)
{
	if (init->map[y][x].up->type == '0')
	{
		init->map[y][x].up->type = 'P';
		ft_print_and_destroy(init, init->kingo_img.current_img, x, y - 1);
		init->kingo.y = y - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
		init->moves += 1;
		
	}
	else if (init->map[y][x].up->type == 'C')
	{
		init->map[y][x].up->type = 'P';
		ft_print_and_destroy(init, init->kingo_img.current_img, x, y - 1);
		init->kingo.y = y - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
		init->moves += 1;
		init->collectible -= 1;
		
	}
	else if (init->map[y][x].up->type == 'E' && init->collectible == 0)
		ft_close(init);
	else if (init->map[y][x].up->type == 'F')
        ft_close(init);
	if(init->check.enemy > 0)
		ft_enemy_mov(init);
	return ;
}

void	ft_move_down(t_mlx *init, int x, int y)
{
	if (init->map[y][x].down->type == '0')
	{
		init->map[y][x].down->type = 'P';
		ft_print_and_destroy(init, init->kingo_img.current_img, x, y + 1);
		init->kingo.y = y + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
		init->moves += 1;
	}	
	else if (init->map[y][x].down->type == 'C')
	{
		init->map[y][x].down->type = 'P';
		ft_print_and_destroy(init, init->kingo_img.current_img, x, y + 1);
		init->kingo.y = y + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
		init->moves += 1;
		init->collectible -= 1;
		
	}
	else if (init->map[y][x].down->type == 'E' && init->collectible == 0)
		ft_close(init);
	else if (init->map[y][x].down->type == 'F')
        ft_close(init);	
	if(init->check.enemy > 0)
		ft_enemy_mov(init);
	return ;
}

void	ft_move_left(t_mlx *init, int x, int y)
{
	if (init->map[y][x].left->type == '0')
	{
		init->map[y][x].left->type = 'P';
		ft_print_and_destroy(init, init->kingo_img.current_img, x - 1, y);
		init->kingo.x = x - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
		init->moves += 1;
	}
	else if (init->map[y][x].left->type == 'C')
	{
		init->map[y][x].left->type = 'P';
		ft_print_and_destroy(init, init->kingo_img.current_img, x - 1, y);
		init->kingo.x = x - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
		init->moves += 1;
		init->collectible -= 1;
		
	}
	else if (init->map[y][x].left->type == 'E' && init->collectible == 0)
		ft_close(init);
	else if (init->map[y][x].left->type == 'F')
        ft_close(init);
	if(init->check.enemy > 0)
		ft_enemy_mov(init);
	return ;
}

void	ft_move_right(t_mlx *init, int x, int y)
{
	if (init->map[y][x].right->type == '0')
	{
		init->map[y][x].right->type = 'P';
		ft_print_and_destroy(init, init->kingo_img.current_img, x + 1, y);
		init->kingo.x = x + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
		init->moves += 1;
	}	
	else if (init->map[y][x].right->type == 'C')
	{
		init->map[y][x].right->type = 'P';
		ft_print_and_destroy(init, init->kingo_img.current_img, x + 1, y);
		init->kingo.x = x + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
		init->moves = init->moves + 1;
		init->collectible -= 1;
	}
	else if (init->map[y][x].right->type == 'E' && init->collectible == 0)
		ft_close(init);
	else if (init->map[y][x].right->type == 'F')
        ft_close(init);
	if(init->check.enemy > 0)
		ft_enemy_mov(init);
	return ;
}

int	key_input(int keycode, t_mlx *init)
{
	int	x;
	int	y;
/*aggiungere animazione collexionabile ex=1*/
	x = init->kingo.x;
	y = init->kingo.y;
	if (keycode == 65307)
		ft_close(init);
	if (keycode == 65362 || keycode == 119)
	{
		ft_move_up(init, x, y);
		write(1, "UP\n", 3);
	}
	else if (keycode == 65364 || keycode == 115)
	{
		ft_move_down(init, x, y);
		write(1, "DOWN\n", 5);
	}
	else if (keycode == 65361 || keycode == 97)
	{
		ft_move_left(init, x, y);
		write(1, "LEFT\n", 5);
	}
	else if (keycode == 65363 || keycode == 100)
	{
		ft_move_right(init, x, y);
		write(1, "RIGHT\n", 6);
	}
	else if (keycode == 114)
		ft_restart(init);
	init->img = mlx_new_image(init->mlx, (init->x * SIZE) + 40, 20);
	mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
	mlx_destroy_image(init->mlx, init->img);
	ft_counter(init);
	return (0);
}
