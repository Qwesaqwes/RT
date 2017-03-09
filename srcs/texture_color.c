/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:37:04 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/09 20:17:40 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			pair(float x, float l)
{
	if (x < 0)
	{
		if ((int)(x / l) % 2 != 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if ((int)(x / l) % 2 == 0)
			return (1);
		else
			return (0);
	}
}

t_color		checker(t_no no)
{
	float		length;
	t_vec3d		point;

	length = no.obj.tex.square;
	point = vector_sub(no.ip, no.obj.transform.transl);
	point = mult_matrix(rotationX(no.obj.transform.rot.x), point);
	point = mult_matrix(rotationY(no.obj.transform.rot.y), point);
	point = mult_matrix(rotationZ(no.obj.transform.rot.z), point);
	point = vector_add(point, no.obj.transform.transl);
	if (pair(point.z, length))
		return((pair(point.y, length) == 1 ? no.obj.tex.tex_col1 :
		no.obj.tex.tex_col2));
	else
		return((pair(point.y, length) == 1 ? no.obj.tex.tex_col2 :
		no.obj.tex.tex_col1));
}

float		fade(float t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

float		lerp(float t, float a, float b)
{
	return (a + t * (b - a));
}

float		grad(int hash, float x, float y, float z)
{
	int h;
	float u;
	float v;

	h = hash & 15;
	u = h < 8 || h == 12 || h == 13 ? x : y;
	v = h < 4 || h == 12 || h == 13 ? y : z;
	return (((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v));
}

float		perlin_coef(float x, float y, float z)
{
	int i;
	t_vec3d		unit_cube;
	t_vec3d		fade_curves;
	int		A;
	int		AA;
	int		AB;
	int		B;
	int		BA;
	int		BB;

	int p[512] = {151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53,
	194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
	190, 6, 148,
	247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57,
	177, 33,  88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74,
	165, 71, 134, 139, 48, 27, 166, 77, 146, 158, 231, 83, 111, 229, 122, 60,
	211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244, 102, 143, 54,  65,
	25, 63, 161,  1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196,
	135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217,
	226, 250, 124, 123, 5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206,
	59, 227, 47, 16, 58, 17, 182, 189, 28, 42, 23, 183, 170, 213, 119, 248, 152,
	2, 44, 154, 163,  70, 221, 153, 101, 155, 167, 43, 172, 9, 129, 22, 39, 253,
	19, 98, 108, 110, 79, 113, 224, 232, 178, 185,  112, 104, 218, 246, 97, 228,
	251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235,
	249, 14, 239, 107, 49, 192, 214,  31, 181, 199, 106, 157, 184,  84, 204,
	176, 115, 121, 50, 45, 127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67,
	29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180};
	i = -1;
	while(++i < 256)
		p[256 + i] = p[i];
	unit_cube.x = (int)floor(x) & 255;
	unit_cube.y = (int)floor(y) & 255;
	unit_cube.z = (int)floor(z) & 255;

	x -= floor(x);
	y -= floor(y);
	z -= floor(z);

	fade_curves.x = fade(x);
	fade_curves.y = fade(y);
	fade_curves.z = fade(z);

	A = p[(int)unit_cube.x] + (int)unit_cube.y;
	AA = p[A] + (int)unit_cube.z;
	AB = p[A + 1] + (int)unit_cube.z;
	B = p[(int)unit_cube.x + 1] + (int)unit_cube.y;
	BA = p[B] + (int)unit_cube.z;
	BB = p[B + 1] + (int)unit_cube.z;
	return (lerp(fade_curves.z, lerp(fade_curves.y, lerp(fade_curves.x,
			grad(p[AA], x, y, z), grad(p[BA], x - 1, y, z)), lerp(fade_curves.x,
			grad(p[AB], x, y - 1, z), grad(p[BB], x - 1, y - 1, z))),
			lerp(fade_curves.y, lerp(fade_curves.x,
			grad(p[AA + 1], x, y, z - 1), grad(p[BA + 1], x - 1, y, z - 1)),
			lerp(fade_curves.x, grad(p[AB + 1], x, y - 1, z - 1),
			grad(p[BB + 1], x - 1, y - 1, z - 1)))));
}

float 		wood_coef(float x, float y, float z)
{
	float v;

	v = 20 * perlin_coef(x, y, z);
	return (v - floor(v));
}

float	marble_coef(float x, float y, float z)
{
	return (cos(x + perlin_coef(x, y, z)));
}

t_color		perlin_deriv(t_no no)
{
	float	n;
	float	v1;
	float	v2;
	float	v3;

	v1 = -0.5;
	v2 = 0;
	v3 = 0.5;
	n = 0;
	if (no.obj.tex.texture == 2)
		n = perlin_coef(no.ip.x, no.ip.y, no.ip.z);
	else if (no.obj.tex.texture == 3)
		n = wood_coef(no.ip.x, no.ip.y, no.ip.z);
	else if (no.obj.tex.texture == 4)
		n = marble_coef(no.ip.x * 20, no.ip.y * 20, no.ip.z * 20);
	if (n < v1)
		return (no.obj.tex.tex_col1);
	else if (v1 < n && n < v2)
	{
		return (color_add(color_fact(no.obj.tex.tex_col1, (float)(n - v1) /
		(float)(v2 - v1)), color_fact(no.obj.tex.tex_col2, (float)(v2 - n) /
		(float)(v2 - v1))));
	}
	else if (v2 < n && n < v3)
	{
		return (color_add(color_fact(no.obj.tex.tex_col2, (float)(n - v2) /
		(float)(v3 - v2)), color_fact(no.obj.tex.tex_col3, (float)(v3 - n) /
		(float)(v3 - v2))));
	}
	else
		return (no.obj.tex.tex_col3);
}

t_color		get_pixel(int tmp, GdkPixbuf *map)
{
	t_color		ret;
	guchar		*pixel;

	pixel = gdk_pixbuf_get_pixels(map);

	ret.red = (float)pixel[tmp] / (float)255;
	// printf("%f\n", ret.red);
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
		{
			ret.x = atan2(-m.g, m.k);
			ret.y = asin(m.c);
			ret.z = atan2(-m.b, m.a);
			ret.w = 0;
		}
		else
		{
			ret.x = -atan2(m.e, m.f);
			ret.y = -M_PI / 2;
			ret.z = 0;
			ret.w = 0;
		}
	}
	else
	{
		ret.x = atan2(m.e, m.f);
		ret.y = M_PI / 2;
		ret.z = 0;
		ret.w = 0;
	}
	ret = vector_fact(ret, 180.0f / M_PI);
	return (ret);
}

t_mapping	mapping(t_face face, t_vec3d rot)
{
	t_vertex	*tmp;
	t_mapping	ret;
	t_vec3d		point;

	tmp = face.vertex;
	while (tmp)
	{
		point = vector_sub(tmp->coord, face.vertex->coord);
		point = mult_matrix(rotationX(-rot.x), point);
		point = mult_matrix(rotationY(-rot.y), point);
		point = mult_matrix(rotationZ(-rot.z), point);
		if (tmp == face.vertex)
		{
			ret.y_min = point.y;
			ret.y_max = point.y;
			ret.z_min = point.z;
			ret.z_max = point.z;
		}
		else
		{
			if (point.y < ret.y_min)
				ret.y_min = point.y;
			if (point.y >ret.y_max)
				ret.y_max = point.y;
			if (point.z < ret.z_min)
				ret.z_min = point.z;
			if (point.z > ret.z_max)
				ret.z_max = point.z;
		}
		// printf("min: %f,  max: %f\n", ret.y_min, ret.y_max);
		tmp = tmp->next;
	}
	return (ret);
}

t_color		texture_mapping(t_no no)
{
	int		map_w;
	int		map_h;
	t_vec3d	n;
	int		n_channels;
	int		rowstride;
	float		u;
	float		v;

	float		angle;
	t_vec3d		unit_vec;
	t_vec3d		rot_angle;
	t_mapping	map;

	map_w = gdk_pixbuf_get_width(no.obj.map_buf);
	map_h = gdk_pixbuf_get_height(no.obj.map_buf);
	// printf("W: %d, H: %d\n", map_w, map_h);
	n_channels = gdk_pixbuf_get_n_channels(no.obj.map_buf);
	rowstride = gdk_pixbuf_get_rowstride (no.obj.map_buf);
	if (no.obj.type == 0)
	{
		n = normalizevec(vector_sub(no.obj.transform.transl, no.ip));
		u = 0.5 + (float)atan2(n.z, n.x) / (float)(2 * M_PI);
		v = 0.5 - (float)asin(n.y) / (float)M_PI;
		return (get_pixel((map_h - (int)(v * map_h)) * rowstride +
		(map_w - (int)(u * map_w)) * n_channels, no.obj.map_buf));
	}
	else if (no.obj.type == 5)
	{
		angle = acos(vector_dot(no.poly_face->normal, (t_vec3d){1, 0, 0, 1}));
		unit_vec = vector_cross(no.poly_face->normal, (t_vec3d){1, 0, 0, 1});
		rot_angle = euler_angles(axe_angle_to_matrix(angle, unit_vec));
		map = mapping(*no.poly_face, rot_angle);
		n = vector_sub(no.ip, no.poly_face->vertex->coord);
		n = mult_matrix(rotationX(-rot_angle.x), n);
		n = mult_matrix(rotationY(-rot_angle.y), n);
		n = mult_matrix(rotationZ(-rot_angle.z), n);
		u = (float)(n.z - map.z_min) / (float)(map.z_max - map.z_min);
		v = (float)(n.y - map.y_min) / (float)(map.y_max - map.y_min);
		return (get_pixel((map_h - (int)(v * map_h)) * rowstride +
		(map_w - (int)(u * map_w)) * n_channels, no.obj.map_buf));
	}
	return (set_black_color());
}

t_color		procedural_texture(t_no no)
{
	if (no.obj.tex.texture == 1)
		return(checker(no));
	return (perlin_deriv(no));
}

t_color		texture_color(t_no no)
{
	if (no.obj.tex.texture == 1 || no.obj.tex.texture == 2 ||
		no.obj.tex.texture == 3 || no.obj.tex.texture == 4)
		return (procedural_texture(no));
	else if (no.obj.tex.texture == 5)
		return (texture_mapping(no));
	return(no.obj.color);
}
