/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:27:08 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 20:46:13 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			get_pos2(int line, int col, GdkPixbuf *buf)
{
	int				tmp;
	unsigned int	rowstride;
	unsigned int	n_channels;

	n_channels = gdk_pixbuf_get_n_channels(buf);
	rowstride = gdk_pixbuf_get_rowstride(buf);
	tmp = line * rowstride + col * n_channels;
	return (tmp);
}

t_rgb		get_color_pixel1(guchar *pixel, GdkPixbuf *buf, int line, int col)
{
	t_rgb	color;

	color.red = pixel[get_pos2(line, col, buf)];
	color.green = pixel[get_pos2(line, col, buf) + 1];
	color.blue = pixel[get_pos2(line, col, buf) + 2];
	return (color);
}

void		gray_scale1(GdkPixbuf *old, GdkPixbuf *new, int line, int col)
{
	int		i;
	guchar	*pixel;
	t_rgb	color;

	pixel = gdk_pixbuf_get_pixels(new);
	color = get_color_pixel1(pixel, old, line, col);
	i = (color.red * 0.333) + (color.green * 0.333) + (color.blue * 0.333);
	pixel[get_pos2(line, col, new)] = i > 255 ? 255 : i;
	pixel[get_pos2(line, col, new) + 1] = i > 255 ? 255 : i;
	pixel[get_pos2(line, col, new) + 2] = i > 255 ? 255 : i;
}

GdkPixbuf	*gray_scale(GdkPixbuf *old)
{
	GdkPixbuf	*new;
	int			line;
	int			col;

	new = gdk_pixbuf_copy(old);
	line = -1;
	while (++line < gdk_pixbuf_get_height(old))
	{
		col = -1;
		while (++col < gdk_pixbuf_get_width(old))
			gray_scale1(old, new, line, col);
	}
	return (new);
}
