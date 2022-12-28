#include "so_long.h"

void    ft_init_collect(t_mlx *init)
{
        init->collectible = 0;
        init->moves = 0;
		init->collect_img.anim_frames = 25;		
		init->collect_img.img_0 = "sprites/col/key_star.xpm";
		init->collect_img.img_1 = "sprites/col/key.xpm";	
		init->collect_img.current_img = "sprites/col/key.xpm";
    return ;
}
void    ft_init_exit(t_mlx *init)
{
		
		init->door_img.current_img = "sprites/door/door_c.xpm";
		init->door_img.img_1 = "sprites/door/door_o.xpm";	
    return ;
}
/*void    ft_init_enemy(t_mlx *init)
{
    return ;
}*/
		



void    ft_init_img(t_mlx *init)
{
    ft_init_collect(init);
    ft_init_exit(init);
    //ft_init_enemy(init);
    return ;
}
