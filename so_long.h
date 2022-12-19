#ifndef SO_LONG_H
# define SO_LONG_H

//LIBRARIES

# include "mlx/mlx.h"
# include "libft/libft.h"

// STRUCTS
# define SIZE 32
typedef struct struct_mlx
{
	void	*mlx;
	void	*win;   
  	char	*map;
    void	*img;
	char	*addr;
    int		img_width;
	int		img_height;
}t_mlx;

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


void	ft_map_render(char c, t_mlx *init);
void	ft_init_map(t_tile **tilemap, char *map);
t_tile **ft_tilemap_alloc( char *map);



#endif