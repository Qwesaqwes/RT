/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:00:51 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 15:32:14 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb	get_color_pixel(guchar *pixel, t_gtk *gtk, int line, int col)
{
	t_rgb	color;

	color.red = pixel[get_pos(line, col, gtk)];
	color.green = pixel[get_pos(line, col, gtk) + 1];
	color.blue = pixel[get_pos(line, col, gtk) + 2];
	return (color);
}

int		get_pos1(guchar *pixel, int line, int col, t_gtk *gtk)
{
	int				tmp;
	unsigned int	rowstride;
	unsigned int	n_channels;

	n_channels = gdk_pixbuf_get_n_channels(gtk->buffer);
	rowstride = gdk_pixbuf_get_rowstride(gtk->buffer);
	tmp = line * rowstride + col * n_channels;
	return ((pixel[tmp] + pixel[tmp + 1] + pixel[tmp + 2]) / 3);
}

int		xgrad(guchar *pixel, int line, int col, t_gtk *gtk)
{
	int		j;
	int		i;
	int		res;
	int		width[3][3];

	j = -1;
	res = 0;
	width[0][0] = -1;
	width[0][1] = 0;
	width[0][2] = 1;
	width[1][0] = -2;
	width[1][1] = 0;
	width[1][2] = 2;
	width[2][0] = -1;
	width[2][1] = 0;
	width[2][2] = 1;
	while (++j < 3)
	{
		i = -1;
		while (++i < 3)
			res += width[j][i] * get_pos1(pixel, line + j, col + i, gtk);
	}
	return (res);
}

int		ygrad(guchar *pixel, int line, int col, t_gtk *gtk)
{
	int		j;
	int		i;
	int		res;
	int		height[3][3];

	j = -1;
	res = 0;
	height[0][0] = -1;
	height[0][1] = -2;
	height[0][2] = -1;
	height[1][0] = 0;
	height[1][1] = 0;
	height[1][2] = 0;
	height[2][0] = 1;
	height[2][1] = 2;
	height[2][2] = 1;
	while (++j < 3)
	{
		i = -1;
		while (++i < 3)
			res += height[j][i] * get_pos1(pixel, line + j, col + i, gtk);
	}
	return (res);
}
