
#ifndef SO_LONG_H
# define SO_LONG_H

//LIBRARIES

# include "mlx/mlx.h"
# include "libft/libft.h"

// STRUCTS
typedef struct struct_mlx
{
	void	*mlx;
	void	*win;
    void    *img;
    char	**relative_path;
    int		img_width;
	int		img_height;

}t_mlx;

#endif