#ifndef SO_LONG_H
# define SO_LONG_H

//LIBRARIES

# include "mlx/mlx.h"
# include "libft/libft.h"

// STRUCTS
# define SIZE 32

typedef struct s_coord
{
	int	x;
	int	y;

}	t_coord;

typedef struct struct_tile
{
    t_coord position;
    char type; 
}t_tile;

typedef struct struct_mlx
{
	void	*mlx;
	void	*win;   
  	t_tile	**map;
    void	*img;
	char	*addr;
    int		lines;
	int		columns;
}t_mlx;





void ft_map_render(t_mlx *init, t_tile **tile_map, int x, int y);
void	ft_init_map(t_tile **tilemap, char *map);
t_tile **ft_tilemap_alloc( char *map, t_mlx *init);



#endif