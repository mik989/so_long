#include "so_long.h"

static void	collect_animation(t_c_img_anim *img)
{
	static int	frame;

	if (img->anim_frames == 0)
		return ;
	if (frame == img->anim_frames)
	{
		img->current_img = img->img_0;
	}
	else if (frame >= img->anim_frames * 2)
	{
		img->current_img = img->img_1;
		frame = 0;
	}
	frame += 1;
}

static void	door_animation(t_mlx *init, t_door_anim *img)
{
	if (init->collectible == 0)
			img->current_img = img->img_1;
	return ;
}

int	animazioni(t_mlx *init)
{
	collect_animation(&init->collect_img);
	door_animation(init, &init->door_img);
	ft_map_render(init, init->map, init->x, init->y);
	return (1);
}