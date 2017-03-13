/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:01:32 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 18:02:08 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			map_value(float u, float v, GdkPixbuf *map)
{
	int		map_w;
	int		map_h;
	int		n_channels;
	int		rowstride;

	map_w = gdk_pixbuf_get_width(map);
	map_h = gdk_pixbuf_get_height(map);
	n_channels = gdk_pixbuf_get_n_channels(map);
	rowstride = gdk_pixbuf_get_rowstride(map);
	return ((map_h - (int)(v * map_h)) * rowstride +
	(map_w - (int)(u * map_w)) * n_channels);
}

int			map_value_right(float u, float v, GdkPixbuf *map)
{
	int		map_w;
	int		map_h;
	int		n_channels;
	int		rowstride;

	map_w = gdk_pixbuf_get_width(map);
	map_h = gdk_pixbuf_get_height(map);
	n_channels = gdk_pixbuf_get_n_channels(map);
	rowstride = gdk_pixbuf_get_rowstride(map);
	if (u * map_w + 1 > map_w)
		return ((map_h - (int)(v * map_h)) * rowstride +
		(map_w - (int)(u * map_w)) * n_channels);
		return ((map_h - (int)(v * map_h)) * rowstride +
	(map_w - (int)(u * map_w + 1)) * n_channels);
}

int			map_value_down(float u, float v, GdkPixbuf *map)
{
	int		map_w;
	int		map_h;
	int		n_channels;
	int		rowstride;

	map_w = gdk_pixbuf_get_width(map);
	map_h = gdk_pixbuf_get_height(map);
	n_channels = gdk_pixbuf_get_n_channels(map);
	rowstride = gdk_pixbuf_get_rowstride(map);
	if (v * map_h + 1 > map_h)
		return ((map_h - (int)(v * map_h)) * rowstride +
		(map_w - (int)(u * map_w)) * n_channels);
		return ((map_h - (int)(v * map_h + 1)) * rowstride +
	(map_w - (int)(u * map_w)) * n_channels);
}
