/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:37:04 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 18:04:35 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		get_pixel(int tmp, GdkPixbuf *map)
{
	t_color		ret;
	guchar		*pixel;

	pixel = gdk_pixbuf_get_pixels(map);
	ret.red = (float)pixel[tmp] / (float)255;
	ret.green = (float)pixel[tmp + 1] / (float)255;
	ret.blue = (float)pixel[tmp + 2] / (float)255;
	return (ret);
}

t_color		texture_mapping(t_no no)
{
	float		u;
	float		v;
	t_vec3d		rot_angle;

	if (no.obj.type == 0)
	{
		uv_sphere(no, &u, &v, &rot_angle);
		return (get_pixel(map_value(u, v, no.obj.map_buf), no.obj.map_buf));
	}
	else if (no.obj.type == 5)
	{
		uv_polygone(no, &u, &v, &rot_angle);
		return (get_pixel(map_value(u, v, no.obj.map_buf), no.obj.map_buf));
	}
	return (set_black_color());
}

t_color		procedural_texture(t_no no)
{
	if (no.obj.tex.texture == 1)
		return (checker(no));
	return (perlin_deriv(no));
}

t_color		texture_color(t_no no)
{
	if (no.obj.tex.texture == 1 || no.obj.tex.texture == 2 ||
		no.obj.tex.texture == 3 || no.obj.tex.texture == 4)
		return (procedural_texture(no));
	else if (no.obj.tex.texture == 5)
		return (texture_mapping(no));
	return (no.obj.color);
}
