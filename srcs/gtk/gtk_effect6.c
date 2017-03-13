/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 21:06:55 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 15:21:32 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		right_image1(t_gtk *gtk, guchar *pixel, int line, int col)
{
	t_rgb		color;
	int			i;

	color = get_color_pixel(pixel, gtk, line, col);
	i = (color.red * -0.011) + (color.green * -0.036) + (color.blue * -0.006);
	i = i < 0 ? 0 : i;
	pixel[get_pos(line, col, gtk)] = i > 255 ? 255 : i;
	i = (color.red * 0.375) + (color.green * 0.733) + (color.blue * 0.011);
	pixel[get_pos(line, col, gtk) + 1] = i > 255 ? 255 : i;
	i = (color.red * -0.065) + (color.green * -0.128) + (color.blue * 1.297);
	i = i < 0 ? 0 : i;
	pixel[get_pos(line, col, gtk) + 2] = i > 255 ? 255 : i;
}

GdkPixbuf	*right_image(t_gtk *gtk)
{
	int			line;
	int			col;
	guchar		*pixel;
	GdkPixbuf	*buf;

	line = -1;
	buf = gdk_pixbuf_copy(gtk->tmp_buf);
	pixel = gdk_pixbuf_get_pixels(buf);
	while (++line < H)
	{
		col = -1;
		while (++col < W)
			right_image1(gtk, pixel, line, col);
	}
	return (buf);
}

void		stereo_effect1(t_gtk *gtk, GdkPixbuf *buf, int line, int col)
{
	t_rgb		color;
	guchar		*pixel;
	int			i;

	pixel = gdk_pixbuf_get_pixels(buf);
	color = get_color_pixel(pixel, gtk, line, col);
	i = (color.red * 0.415) + (color.green * 0.471) + (color.blue * 0.166);
	pixel[get_pos(line, col, gtk)] = i > 255 ? 255 : i;
	i = (color.red * -0.045) + (color.green * -0.048) + (color.blue * -0.025);
	i = i < 0 ? 0 : i;
	pixel[get_pos(line, col, gtk) + 1] = i > 255 ? 255 : i;
	i = (color.red * -0.054) + (color.green * -0.062) + (color.blue * 0.012);
	i = i < 0 ? 0 : i;
	pixel[get_pos(line, col, gtk) + 2] = i > 255 ? 255 : i;
}

void		stereo_effect(t_env *e)
{
	GdkPixbuf	*buf;
	GdkPixbuf	*buf1;
	int			line;
	int			col;

	line = -1;
	buf = gdk_pixbuf_copy(e->gtk.buffer);
	while (++line < H)
	{
		col = -1;
		while (++col < W)
			stereo_effect1(&e->gtk, buf, line, col);
	}
	raytracing(e);
	buf1 = right_image(&e->gtk);
	merge_image(buf, buf1);
	g_signal_connect(e->gtk.save, "clicked", G_CALLBACK(gtk_s_img),
	buf);
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), buf);
}
