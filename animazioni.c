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

int	animazioni(t_mlx *init)
{
	collect_animation(&init->collect_img);
	ft_map_render(init, init->map, init->x, init->y);
	return (1);
}