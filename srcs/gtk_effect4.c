/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:00:10 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/21 16:52:41 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_kernel(float kernel[MOTION_KERNEL][MOTION_KERNEL])
{
	int		j;
	int		i;
	int		k;

	j = -1;
	k = 0;
	while (++j < MOTION_KERNEL)
	{
		i = -1;
		while (++i < MOTION_KERNEL)
		{
			if (i == k)
				kernel[j][i] = 0.111;
			else
				kernel[j][i] = 0;
		}
		k++;
	}
}

void	motion_effec1(t_gtk *gtk, GdkPixbuf *buf, int line, int col)
{
	guchar	*pixel;
	t_rgb	color;
	int		j;
	int		i;
	// float	kernel[MOTION_KERNEL][MOTION_KERNEL];

	j = -1;
	// init_kernel(kernel);
	pixel = gdk_pixbuf_get_pixels(buf);
	color = get_color_pixel(pixel, gtk, line, col);
	while (++j < MOTION_KERNEL)
	{
		i = -1;
		while (++i < MOTION_KERNEL)
		{
			color.red += gtk->kernel[j][i] * pixel[get_pos(line +
			j, col + i, gtk)];
			color.green += gtk->kernel[j][i] * pixel[get_pos(line +
			j, col + i, gtk) + 1];
			color.blue += gtk->kernel[j][i] * pixel[get_pos(line +
			j, col + i, gtk) + 2];
		}
	}
	// printf("ERROR3\n");
	pixel[get_pos(line, col, gtk)] = (color.red) > 255 ? 255 : color.red;
	pixel[get_pos(line, col, gtk) + 1] = (color.green) > 255 ? 255 : color.green;
	pixel[get_pos(line, col, gtk) + 2] = (color.blue) > 255 ? 255 : color.blue;
}

void	motion_effec(t_env *e)
{
	GdkPixbuf	*buf;
	int			line;
	int			col;

	line = (MOTION_KERNEL / 2) - 1 ;
	init_kernel(e->gtk.kernel);
	buf = gdk_pixbuf_copy(e->gtk.buffer);
	while (++line < (H - (MOTION_KERNEL) - 1))
	{
		col = (MOTION_KERNEL / 2) - 1;
		while(++col < W - ((MOTION_KERNEL) - 1))
			motion_effec1(&e->gtk, buf, line, col);
	}
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), buf);
}
