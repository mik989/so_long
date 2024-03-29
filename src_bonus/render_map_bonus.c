/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:12:20 by mgirardi          #+#    #+#             */
/*   Updated: 2023/01/17 21:12:22 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_and_destroy(t_mlx *init, char *path, int x, int y)
{
	int	size;

	size = SIZE;
	init->img = mlx_xpm_file_to_image(init->mlx, path, &size, &size);
	mlx_put_image_to_window(init->mlx, init->win, init->img,
		init->map[y][x].position.x, init->map[y][x].position.y);
	mlx_destroy_image(init->mlx, init->img);
}

void	ft_wall_render(t_mlx *init, int x, int y)
{
	if (x == 0 && y == 0)
		ft_print_and_destroy(init, "sprites/wall/corner_ul.xpm", x, y);
	else if (x == (init->x) - 1 && y == 0)
		ft_print_and_destroy(init, "sprites/wall/corner_ur.xpm", x, y);
	else if (x == 0 && (y + 1) == (init->y))
		ft_print_and_destroy(init, "sprites/wall/corner_ld.xpm", x, y);
	else if (x == (init->x) - 1 && (y + 1) == (init->y))
		ft_print_and_destroy(init, "sprites/wall/corner_rd.xpm", x, y);
	else if (y == 0)
		ft_print_and_destroy(init, "sprites/wall/wall_up.xpm", x, y);
	else if (x == 0)
		ft_print_and_destroy(init, "sprites/wall/wall_l.xpm", x, y);
	else if (x == (init->x) - 1)
		ft_print_and_destroy(init, "sprites/wall/wall_r.xpm", x, y);
	else if ((y + 1) == init->y)
		ft_print_and_destroy(init, "sprites/wall/wall_down.xpm", x, y);
	else
		ft_print_and_destroy(init, "sprites/wall/colonna.xpm", x, y);
	return ;
}

void	ft_map_render_logic(t_mlx *init, t_tile **tile_map, int x, int y)
{
	if (tile_map[y][x].type == '1')
		ft_wall_render(init, x, y);
	else if (tile_map[y][x].type == '0')
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
	else if (tile_map[y][x].type == 'P')
	{
		ft_print_and_destroy(init, init->kingo_img.current_img, x, y);
		init->kingo.x = x;
		init->kingo.y = y;
	}
	else if (tile_map[y][x].type == 'F')
	{
		ft_print_and_destroy(init, init->enemy_img.current_img, x, y);
		init->enemy.x = x;
		init->enemy.y = y;
	}
	else if (tile_map[y][x].type == 'E')
	{
		ft_print_and_destroy(init, init->door_img.current_img, x, y);
		init->door.x = x;
		init->door.y = y;
	}
	else if (tile_map[y][x].type == 'C')
		ft_print_and_destroy(init, init->collect_img.current_img, x, y);
}

void	ft_map_render(t_mlx *init, t_tile **tile_map, int x, int y)
{
	while (y--)
	{
		x = init->x;
		while (x--)
		{
			ft_map_render_logic(init, tile_map, x, y);
		}
	}
}
