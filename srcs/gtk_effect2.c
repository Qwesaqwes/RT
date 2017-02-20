/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:59:13 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/20 21:59:25 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	greyscale_effect1(t_gtk *gtk, GdkPixbuf *buf, int line, int col)
{
	int		i;
	guchar	*pixel;
	t_rgb	color;

	pixel = gdk_pixbuf_get_pixels(buf);
	color = get_color_pixel(pixel, gtk, line, col);
	i = (color.red * 0.333) + (color.green * 0.333) + (color.blue * 0.333);
	pixel[get_pos(line, col, gtk)] = i > 255 ? 255 : i;
	pixel[get_pos(line, col, gtk) + 1] = i > 255 ? 255 : i;
	pixel[get_pos(line, col, gtk) + 2] = i > 255 ? 255 : i;
}

void	greyscale_effect(t_env *e)
{
	GdkPixbuf	*buf;
	int			line;
	int			col;

	line = -1;
	buf = gdk_pixbuf_copy(e->gtk.buffer);
	while (++line < H)
	{
		col = -1;
		while(++col < W)
			greyscale_effect1(&e->gtk, buf, line, col);
	}
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), buf);
}

void	sepia_effect1(t_gtk *gtk, GdkPixbuf *buf, int line, int col)
{
	int		i;
	guchar	*pixel;
	t_rgb	color;

	pixel = gdk_pixbuf_get_pixels(buf);
	color = get_color_pixel(pixel, gtk, line, col);
	i = (color.red * 0.189) + (color.green * 0.769) + (color.blue * 0.393);
	pixel[get_pos(line, col, gtk)] = i > 255 ? 255 : i;
	i = (color.red * 0.168) + (color.green * 0.686) + (color.blue * 0.349);
	pixel[get_pos(line, col, gtk) + 1] = i > 255 ? 255 : i;
	i = (color.red * 0.131) + (color.green * 0.534) + (color.blue * 0.272);
	pixel[get_pos(line, col, gtk) + 2] = i > 255 ? 255 : i;
}

void	sepia_effect(t_env *e)
{
	GdkPixbuf	*buf;
	int			line;
	int			col;

	line = -1;
	buf = gdk_pixbuf_copy(e->gtk.buffer);
	while (++line < H)
	{
		col = -1;
		while(++col < W)
			sepia_effect1(&e->gtk, buf, line, col);
	}
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), buf);
}
