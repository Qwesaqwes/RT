/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:48:03 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/11 21:09:24 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		map_value(float u, float v, GdkPixbuf *map)
{
	int		map_w;
	int		map_h;
	int		n_channels;
	int		rowstride;

	map_w = gdk_pixbuf_get_width(map);
	map_h = gdk_pixbuf_get_height(map);
	n_channels = gdk_pixbuf_get_n_channels(map);
	rowstride = gdk_pixbuf_get_rowstride (map);

	return ((map_h - (int)(v * map_h)) * rowstride +
	(map_w - (int)(u * map_w)) * n_channels);
}

int		map_value_right(float u, float v, GdkPixbuf *map)
{
	int		map_w;
	int		map_h;
	int		n_channels;
	int		rowstride;

	map_w = gdk_pixbuf_get_width(map);
	map_h = gdk_pixbuf_get_height(map);
	n_channels = gdk_pixbuf_get_n_channels(map);
	rowstride = gdk_pixbuf_get_rowstride (map);
	return ((map_h - (int)(v * map_h)) * rowstride +
	(map_w - (int)((u + 1) * map_w)) * n_channels);
}

int		map_value_down(float u, float v, GdkPixbuf *map)
{
	int		map_w;
	int		map_h;
	int		n_channels;
	int		rowstride;

	map_w = gdk_pixbuf_get_width(map);
	map_h = gdk_pixbuf_get_height(map);
	n_channels = gdk_pixbuf_get_n_channels(map);
	rowstride = gdk_pixbuf_get_rowstride (map);
	return ((map_h - (int)((v + 1) * map_h)) * rowstride +
	(map_w - (int)(u * map_w)) * n_channels);
}

t_vec3d		bump_mapping(t_no no)
{
	float u;
	float v;
	t_vec3d		rot_angle;
	guchar		*pixel;

	// t_vec3d		pu; //0, 0, 1
	// t_vec3d		pv; //0, -1, 0

	float		bu;
	float		bv;

	t_vec3d		n;

	if (no.obj.tex.bump == 0)
		return (no.normal);
	uv_polygone(no, &u, &v, &rot_angle);
	pixel = gdk_pixbuf_get_pixels(no.obj.bump_buf);
	bu = (float)(pixel[map_value_right(u, v, no.obj.bump_buf)] -
		pixel[map_value(u, v, no.obj.bump_buf)]) / 255.0f;
	bv = (float)(pixel[map_value_down(u, v, no.obj.bump_buf)] -
		pixel[map_value(u, v, no.obj.bump_buf)]) / 255.0f;
	n = vector_add(no.normal, vector_add(vector_fact(
		vector_cross(no.normal, (t_vec3d){0, -1, 0, 1}), bv * 100),
		vector_fact(vector_cross(no.normal, (t_vec3d){0, 0, 1, 1}), bu * 100)));
	n = mult_matrix(rotationX(rot_angle.x), n);
	n = mult_matrix(rotationY(rot_angle.y), n);
	n = mult_matrix(rotationZ(rot_angle.z), n);
	n = vector_add(n, no.poly_face->vertex->coord);
	printf("n.x: %f, n.y: %f, n.z: %f, bu: %f, bv: %f\n", n.x, n.y, n.z, bu, bv);
	return (n);
}
