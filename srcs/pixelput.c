/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 04:57:58 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/13 18:36:22 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	ft_pixel_put(int i, int j, t_rgb color, t_env e)
{
	int				tmp;
	unsigned int	rowstride;
	unsigned int	n_channels;
	guchar			*pixel;

	pixel = NULL;
	pixel = gdk_pixbuf_get_pixels(e.gtk.buffer);
	n_channels = gdk_pixbuf_get_n_channels(e.gtk.buffer);
	rowstride = gdk_pixbuf_get_rowstride (e.gtk.buffer);
	tmp = j * rowstride + i * n_channels;
	if (e.gtk.nb_effect == 0)
	{
		pixel[tmp] = (color.red);
		pixel[tmp + 1] = (color.green);
		pixel[tmp + 2] = (color.blue);
	}
	else if(e.gtk.nb_effect == 1)
	{

		if(((color.red * 0.189) + (color.green * 0.769) + (color.blue * 0.393)) > 255)
			pixel[tmp] = 255;
		else
			pixel[tmp] = (color.red * 0.189) + (color.green * 0.769) + (color.blue * 0.393);
		if(((color.red * 0.168) + (color.green * 0.686) + (color.blue * 0.349)) > 255)
			pixel[tmp + 1] = 255;
		else
			pixel[tmp + 1] = (color.red * 0.168) + (color.green * 0.686) + (color.blue * 0.349);
		if(((color.red * 0.131) + (color.green * 0.534) + (color.blue * 0.272)) > 255)
			pixel[tmp + 2] = 255;
		else
			pixel[tmp + 2] = (color.red * 0.131) + (color.green * 0.534) + (color.blue * 0.272);
	}
	else if(e.gtk.nb_effect == 2)
	{

		if(((color.red * 0.333) + (color.green * 0.333) + (color.blue * 0.333)) > 255)
			pixel[tmp] = 255;
		else
			pixel[tmp] = (color.red * 0.333) + (color.green * 0.333) + (color.blue * 0.333);
		if(((color.red * 0.333) + (color.green * 0.333) + (color.blue * 0.333)) > 255)
			pixel[tmp + 1] = 255;
		else
			pixel[tmp + 1] = (color.red * 0.333) + (color.green * 0.333) + (color.blue * 0.333);
		if(((color.red * 0.333) + (color.green * 0.333) + (color.blue * 0.333)) > 255)
			pixel[tmp + 2] = 255;
		else
			pixel[tmp + 2] = (color.red * 0.333) + (color.green * 0.333) + (color.blue * 0.333);
	}
}
