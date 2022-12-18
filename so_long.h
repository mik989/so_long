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

typedef struct struct_tile
{
    t_coord position;
    char type; 
}t_tile;

typedef struct s_coord
{
	int	x;
	int	y;

}	t_coord;

void ft_map_render(char c, t_mlx *init);



#endif