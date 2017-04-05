/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_angles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:36:29 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 18:38:01 by jichen-m         ###   ########.fr       */
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

t_matrix	axe_angle_to_matrix(float angle, t_vec3d axe)
{
	t_matrix	ret;
	float		j;
	float		sint;

	j = 1 - cos(angle);
	sint = sin(angle);
	ret.a = cos(angle) + axe.x * axe.x * j;
	ret.b = axe.x * axe.y * j - axe.z * sint;
	ret.c = axe.x * axe.z * j + axe.y * sint;
	ret.d = 0;
	ret.e = axe.y * axe.x * j + axe.z * sint;
	ret.f = cos(angle) + axe.y * axe.y * j;
	ret.g = axe.y * axe.z * j - axe.x * sint;
	ret.h = 0;
	ret.i = axe.x * axe.z * j - axe.y * sint;
	ret.j = axe.y * axe.z * j + axe.x * sint;
	ret.k = cos(angle) + axe.z * axe.z * j;
	ret.l = 0;
	ret.m = 0;
	ret.n = 0;
	ret.o = 0;
	ret.p = 1;
	return (ret);
}

t_vec3d		euler_angles(t_matrix m)
{
	t_vec3d		ret;

	if (m.c < 1)
	{
		if (m.c > -1)
			ret = (t_vec3d){atan2(-m.g, m.k), asin(m.c), atan2(-m.b, m.a), 0};
		else
			ret = (t_vec3d){-atan2(m.e, m.f), -M_PI / 2, 0, 0};
	}
	else
		ret = (t_vec3d){atan2(m.e, m.f), M_PI / 2, 0, 0};
	ret = vector_fact(ret, 180.0f / M_PI);
	return (ret);
}
