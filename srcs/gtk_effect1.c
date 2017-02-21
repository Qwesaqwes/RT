/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:16:51 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/21 15:15:17 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	no_effect1(t_gtk *gtk, GdkPixbuf *buf, int line, int col)
{
	guchar	*pixel;
	t_rgb	color;

	pixel = gdk_pixbuf_get_pixels(buf);
	color = get_color_pixel(pixel, gtk, line, col);
	pixel[get_pos(line, col, gtk)] = color.red;
	pixel[get_pos(line, col, gtk) + 1] = color.green;
	pixel[get_pos(line, col, gtk) + 2] = color.blue;
}

void	no_effect(t_env *e)
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
			no_effect1(&e->gtk, buf, line, col);
	}
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), buf);
}

void	gtk_effect1(t_env *e, int active)
{
	if (active == 3)
	{
		e->gtk.nb_effect = active;
		sobel_effect(e);
	}
	else if (active == 4)
	{
		e->gtk.nb_effect = active;
		cartoon_effect(e);
	}
	else if (active == 5)
	{
		e->gtk.nb_effect = active;
		motion_effec(e);
	}
	else if (active ==  6)
	{
		e->gtk.nb_effect = active;
		blur_effec(e);
	}
}

void	gtk_effect(GtkWidget *button, t_env *e)
{
	int		active;

	(void)button;
	active = gtk_combo_box_get_active(GTK_COMBO_BOX(e->gtk.n_effect));
	if (active > -1)
	{
		if (active == 0)
		{
			e->gtk.nb_effect = active;
			no_effect(e);
		}
		else if (active == 1)
		{
			e->gtk.nb_effect = active;
			sepia_effect(e);
		}
		else if (active == 2)
		{
			e->gtk.nb_effect = active;
			greyscale_effect(e);
		}
		gtk_effect1(e, active);
	}
}
