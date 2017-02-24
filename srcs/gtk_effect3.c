/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:59:41 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/24 15:55:49 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		limit_color(int col)
{
	if (col <= 0)
		return (0);
	else if (col > 0 && col <= 50)
		return (25);
	else if (col > 50 && col <= 100)
		return (75);
	else if (col > 100 && col <= 200)
		return (150);
	else if (col > 200 && col <= 250)
		return (225);
	else if ((col > 250 && col <= 255) || col > 255)
		return (255);
	else
		return (col);
}

void	cartoon_effect1(t_gtk *gtk, GdkPixbuf *buf, int line, int col)
{
	guchar	*pixel;
	int		sum;
	t_rgb	color;

	pixel = gdk_pixbuf_get_pixels(buf);
	color = get_color_pixel(pixel, gtk, line, col);
	sum = abs(xgrad(pixel, line, col, gtk)) + abs(ygrad(pixel, line, col, gtk));
	sum = 255 - sum;
	sum = sum > 255 ? 255 : sum;
	sum = sum < 0 ? 0 : sum;
	if (sum > 100)
	{
		color.red = limit_color(color.red);
		color.green = limit_color(color.green);
		color.blue = limit_color(color.blue);
		pixel[get_pos(line, col, gtk)] = color.red;
		pixel[get_pos(line, col, gtk) + 1] = color.green;
		pixel[get_pos(line, col, gtk) + 2] = color.blue;
	}
	else
	{
		pixel[get_pos(line, col, gtk)] = sum;
		pixel[get_pos(line, col, gtk) + 1] = sum;
		pixel[get_pos(line, col, gtk) + 2] = sum;
	}
}

void	cartoon_effect(t_env *e)
{
	GdkPixbuf	*buf;
	int			line;
	int			col;

	line = 0;
	buf = gdk_pixbuf_copy(e->gtk.buffer);
	while (++line < H - 1)
	{
		col = 0;
		while(++col < W - 1)
			cartoon_effect1(&e->gtk, buf, line, col);
	}
	g_signal_connect(e->gtk.save, "clicked", G_CALLBACK(gtk_s_img),
	buf);
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), buf);
}

void	sobel_effect1(t_gtk *gtk, GdkPixbuf *buf, int line, int col)
{
	guchar	*pixel;
	int		sum;
	int		xgradi;
	int		ygradi;

	pixel = gdk_pixbuf_get_pixels(buf);
	xgradi = xgrad(pixel, line, col, gtk);
	ygradi = ygrad(pixel, line, col, gtk);
	sum = sqrt((xgradi * xgradi) + (ygradi * ygradi));
	sum = sum > 255 ? 255 : sum;
	sum = sum < 0 ? 0 : sum;
	pixel[get_pos(line, col, gtk)] = sum;
	pixel[get_pos(line, col, gtk) + 1] = sum;
	pixel[get_pos(line, col, gtk) + 2] = sum;
}

void	sobel_effect(t_env *e)
{
	GdkPixbuf	*buf;
	int			line;
	int			col;

	line = 0;
	buf = gdk_pixbuf_copy(e->gtk.buffer);
	while (++line < H - 1)
	{
		col = 0;
		while(++col < W - 1)
			sobel_effect1(&e->gtk, buf, line, col);
	}
	g_signal_connect(e->gtk.save, "clicked", G_CALLBACK(gtk_s_img),
	buf);
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), buf);
}
