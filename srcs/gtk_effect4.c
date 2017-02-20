/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:00:10 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/20 22:00:21 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	motion_effec1(t_gtk *gtk, GdkPixbuf *buf, int line, int col)
{
	guchar	*pixel;
	t_rgb	color;
	float kernel[20][20];
	int		j;
	int		i;
	int k;

	j = -1;
	k = 0;

	while (++j < 20)
	{
		i = -1;
		while (++i < 20)
		{
			if (i == k)
				kernel[j][i] = 0.111;
			else
				kernel[j][i] = 0;
			// if (j == 0 && i == 19)
			// 	kernel[j][i] = 0.8;
			// else if (j == 19 && i == 0)
			// 	kernel[j][i] = 0.5;
			// else
			// 	kernel[j][i] = 0;
		}
		k++;
	}
	j = -1;
	pixel = gdk_pixbuf_get_pixels(buf);
	color = get_color_pixel(pixel, gtk, line, col);
	while (++j < 20)
	{
		i = -1;
		while (++i < 20)
		{
			color.red += kernel[j][i] * pixel[get_pos(line +
			j, col + i, gtk)];
			color.green += kernel[j][i] * pixel[get_pos(line +
			j, col + i, gtk) + 1];
			color.blue += kernel[j][i] * pixel[get_pos(line +
			j, col + i, gtk) + 2];
		}
	}
	pixel[get_pos(line, col, gtk)] = (color.red) > 255 ? 255 : color.red;
	pixel[get_pos(line, col, gtk) + 1] = (color.green) > 255 ? 255 : color.green;
	pixel[get_pos(line, col, gtk) + 2] = (color.blue) > 255 ? 255 : color.blue;
}

void	motion_effec(t_env *e)
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
			motion_effec1(&e->gtk, buf, line, col);
	}
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), buf);
}
