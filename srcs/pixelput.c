/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 04:57:58 by jichen-m          #+#    #+#             */
/*   Updated: 2017/01/18 16:36:58 by jichen-m         ###   ########.fr       */
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
	pixel[tmp] = (color.red);
	pixel[tmp + 1] = (color.green);
	pixel[tmp + 2] = (color.blue);
}
