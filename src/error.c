/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:04:26 by mgirardi          #+#    #+#             */
/*   Updated: 2023/01/17 21:10:03 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_map(char *error, char *map)
{
	free(map);
	ft_putstr_fd(error, 2);
	exit (0);
}

int	ft_close_error(t_mlx *init)
{
	ft_freemap(init);
	exit(0);
	return (0);
}

void	ft_error_border(t_mlx *init)
{
	ft_putstr_fd("Error! Invalid map\n", 2);
	ft_close_error(init);
}
