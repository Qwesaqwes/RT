/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 04:57:58 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:43:44 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		get_pos(int line, int col, t_gtk *gtk)
{
	int				tmp;
	unsigned int	rowstride;
	unsigned int	n_channels;

	n_channels = gdk_pixbuf_get_n_channels(gtk->buffer);
	rowstride = gdk_pixbuf_get_rowstride(gtk->buffer);
	tmp = line * rowstride + col * n_channels;
	return (tmp);
}

void	ft_pixel_put(int i, int j, t_rgb color_dec, t_env e_dec)
{
	t_env	e;
	t_rgb	color;
	guchar	*pixel;
	int		tmp;

	e = e_dec;
	color = color_dec;
	if (e.gtk.nb_effect == 7)
		pixel = gdk_pixbuf_get_pixels(e.gtk.tmp_buf);
	else
		pixel = gdk_pixbuf_get_pixels(e.gtk.buffer);
	tmp = get_pos(j, i, &e.gtk);
	pixel[tmp] = color.red;
	pixel[tmp + 1] = color.green;
	pixel[tmp + 2] = color.blue;
}
