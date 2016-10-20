/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 04:57:58 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 05:10:30 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	ft_pixel_put(int i, int j, t_rgb color, t_env e)
{
	int		tmp;

	if (e.img.endian == 0)
		tmp = ((color.red) << 16) + ((color.green) << 8) + (color.blue);
	else
		tmp = ((color.blue) << 16) + ((color.green) << 8) + (color.red);
	*((int *)&e.img.buffer[(j * e.img.bpl) + (i * (e.img.bpp / 8))]) = tmp;
}
