/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:13:41 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/21 16:45:59 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_kernel1(float kernel[BLUR_KERNEL][BLUR_KERNEL])
{
	int		j;
	int		i;

	j = -1;
	while (++j < BLUR_KERNEL)
	{
		i = -1;
		while (++i < BLUR_KERNEL)
		{
			if (j == 0 && i == BLUR_KERNEL - 1)
				kernel[j][i] = 0.8;
			else if (j == 19 && i == 0)
				kernel[j][i] = 0.5;
			else
				kernel[j][i] = 0;
		}
	}
}

void	blur_effec1(t_gtk *gtk, GdkPixbuf *buf, int line, int col)
{
	guchar	*pixel;
	t_rgb	color;
	int		j;
	int		i;

	j = -1;
	pixel = gdk_pixbuf_get_pixels(buf);
	color = get_color_pixel(pixel, gtk, line, col);
	while (++j < BLUR_KERNEL)
	{
		i = -1;
		while (++i < BLUR_KERNEL)
		{
			color.red += gtk->kernel1[j][i] * pixel[get_pos(line +
			j, col + i, gtk)];
			color.green += gtk->kernel1[j][i] * pixel[get_pos(line +
			j, col + i, gtk) + 1];
			color.blue += gtk->kernel1[j][i] * pixel[get_pos(line +
			j, col + i, gtk) + 2];
		}
	}
	pixel[get_pos(line, col, gtk)] = (color.red) > 255 ? 255 : color.red;
	pixel[get_pos(line, col, gtk) + 1] = (color.green) > 255 ? 255 : color.green;
	pixel[get_pos(line, col, gtk) + 2] = (color.blue) > 255 ? 255 : color.blue;
}

void	blur_effec(t_env *e)
{
	GdkPixbuf	*buf;
	int			line;
	int			col;

	line = (BLUR_KERNEL / 2) - 1 ;;
	buf = gdk_pixbuf_copy(e->gtk.buffer);
	init_kernel1(e->gtk.kernel1);
	while (++line < (H - (BLUR_KERNEL) - 1))
	{
		col = (BLUR_KERNEL / 2) - 1 ;;
		while(++col < (W - (BLUR_KERNEL) - 1))
			blur_effec1(&e->gtk, buf, line, col);
	}
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), buf);
}
