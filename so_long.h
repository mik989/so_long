#ifndef SO_LONG_H
# define SO_LONG_H

//LIBRARIES

# include "libft/libft.h"
# include "mlx/mlx.h"

// STRUCTS
# define SIZE 64

typedef struct s_coord
{
	int					x;
	int					y;

}						t_coord;

typedef struct s_anim
{
	int					exit;
	int					coll;

}						t_anim;

typedef struct struct_tile
{
	t_coord				position;
	char				type;
	char				ori_type;
	struct struct_tile	*up;
	struct struct_tile	*down;
	struct struct_tile	*left;
	struct struct_tile	*right;
}						t_tile;

typedef struct struct_mlx
{
	void				*mlx;
	void				*win;
	t_tile				**map;
	void				*img;
	t_coord				kingo;
	int					collectible;
	int					moves;
	t_anim				anim;
	int					x;
	int					y;
}						t_mlx;

void					ft_map_render(t_mlx *init, t_tile **tile_map, int x,
							int y);
void					ft_init_map(t_mlx init, char *map);
t_tile					**ft_tilemap_alloc(char *map, t_mlx *init);
int ft_close(t_mlx *init);
int	key_input(int keycode, t_mlx *init);
void ft_counter(t_mlx *init);
void ft_print_and_destroy(t_mlx *init, char *path, int x, int y);

#endif
