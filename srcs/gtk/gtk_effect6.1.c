/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect6.1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:05:42 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 15:30:56 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		get_lr_pix_c(int line, int col, GdkPixbuf *buf, GdkPixbuf *buf1)
{
	guchar		*l_pixel;
	guchar		*r_pixel;
	t_rgb		l_color;
	t_rgb		r_color;

	l_pixel = gdk_pixbuf_get_pixels(buf);
	r_pixel = gdk_pixbuf_get_pixels(buf1);
	l_color = get_color_pixel1(l_pixel, buf, line, col);
	r_color = get_color_pixel1(r_pixel, buf, line, col);
	l_color.red += r_color.red;
	l_color.red = l_color.red < 0 ? 0 : l_color.red;
	l_pixel[get_pos2(line, col, buf)] = l_color.red > 255 ? 255 :
	l_color.red;
	l_color.green += r_color.green;
	l_color.green = l_color.green < 0 ? 0 : l_color.green;
	l_pixel[get_pos2(line, col, buf) + 1] = l_color.green > 255 ? 255 :
	l_color.green;
	l_color.blue += r_color.blue;
	l_color.blue = l_color.blue < 0 ? 0 : l_color.blue;
	l_pixel[get_pos2(line, col, buf) + 2] = l_color.blue > 255 ? 255 :
	l_color.blue;
}

void		merge_image(GdkPixbuf *buf, GdkPixbuf *buf1)
{
	int			line;
	int			col;

	line = -1;
	while (++line < H)
	{
		col = -1;
		while (++col < W)
			get_lr_pix_c(line, col, buf, buf1);
	}
}
