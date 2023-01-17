/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:22:17 by mgirardi          #+#    #+#             */
/*   Updated: 2023/01/17 21:22:26 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *str, char *buff)
{
	char	*temporaneo;

	temporaneo = ft_strjoin(str, buff);
	free(str);
	return (temporaneo);
}
