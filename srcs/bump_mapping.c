/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:48:03 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:55:54 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			get_pos2(int line, int col, GdkPixbuf *buf)
{
	int				tmp;
	unsigned int	rowstride;
	unsigned int	n_channels;

	n_channels = gdk_pixbuf_get_n_channels(buf);
	rowstride = gdk_pixbuf_get_rowstride(buf);
	tmp = line * rowstride + col * n_channels;
	return (tmp);
}

t_rgb		get_color_pixel1(guchar *pixel, GdkPixbuf *buf, int line, int col)
{
	t_rgb	color;

	color.red = pixel[get_pos2(line, col, buf)];
	color.green = pixel[get_pos2(line, col, buf) + 1];
	color.blue = pixel[get_pos2(line, col, buf) + 2];
	return (color);
}

void		gray_scale1(GdkPixbuf *old, GdkPixbuf *new, int line, int col)
{
	int		i;
	guchar	*pixel;
	t_rgb	color;

	pixel = gdk_pixbuf_get_pixels(new);
	color = get_color_pixel1(pixel, old, line, col);
	i = (color.red * 0.333) + (color.green * 0.333) + (color.blue * 0.333);
	pixel[get_pos2(line, col, new)] = i > 255 ? 255 : i;
	pixel[get_pos2(line, col, new) + 1] = i > 255 ? 255 : i;
	pixel[get_pos2(line, col, new) + 2] = i > 255 ? 255 : i;
}

GdkPixbuf	*gray_scale(GdkPixbuf *old)
{
	GdkPixbuf	*new;
	int			line;
	int			col;

	new = gdk_pixbuf_copy(old);
	line = -1;
	while (++line < gdk_pixbuf_get_height(old))
	{
		col = -1;
		while (++col < gdk_pixbuf_get_width(old))
			gray_scale1(old, new, line, col);
	}
	return (new);
}

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
	{
		return ((map_h - (int)(v * map_h)) * rowstride +
			(map_w - (int)(u * map_w)) * n_channels);
	}
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
	{
		return ((map_h - (int)(v * map_h)) * rowstride +
			(map_w - (int)(u * map_w)) * n_channels);
	}
	return ((map_h - (int)(v * map_h + 1)) * rowstride +
		(map_w - (int)(u * map_w)) * n_channels);
}

t_vec3d		bump_mapping(t_no no)
{
	float		u;
	float		v;
	t_vec3d		rot_angle;
	guchar		*pixel;
	float		bu;
	float		bv;
	t_vec3d		n;

	if (no.obj.tex.bump == 0)
		return (no.normal);
	if (no.obj.type == 0)
		uv_sphere(no, &u, &v, &rot_angle);
	else
		uv_polygone(no, &u, &v, &rot_angle);
	pixel = gdk_pixbuf_get_pixels(no.obj.bump_buf);
	bu = (float)(pixel[map_value_right(u, v, no.obj.bump_buf)] -
		pixel[map_value(u, v, no.obj.bump_buf)]) / 255.0f;
	bv = (float)(pixel[map_value_down(u, v, no.obj.bump_buf)] -
		pixel[map_value(u, v, no.obj.bump_buf)]) / 255.0f;
	n = no.normal;
	n = mult_matrix(rotationX(-rot_angle.x), n);
	n = mult_matrix(rotationY(-rot_angle.y), n);
	n = mult_matrix(rotationZ(-rot_angle.z), n);
	n = vector_add(n, vector_add(
		vector_fact(vector_cross(n, (t_vec3d){0, 1, 0, 1}), -bv * 10),
		vector_fact(vector_cross(n, (t_vec3d){0, 0, 1, 1}), -bu * 10)));
	n = mult_matrix(rotationX(rot_angle.x), n);
	n = mult_matrix(rotationY(rot_angle.y), n);
	n = mult_matrix(rotationZ(rot_angle.z), n);
	return (n);
}
