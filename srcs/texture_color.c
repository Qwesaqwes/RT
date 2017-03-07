/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:37:04 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/07 17:59:42 by jichen-m         ###   ########.fr       */
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

	int p[512] = {151,160,137,91,90,15,
		131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
         190,6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
         88,237,149,56,87,174,20,125,136,171,168,68,175,74,165,71,134,139,48,27,166,
         77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
         102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208,89,18,169,200,196,
         135,130,116,188,159,86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,
         5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
         23,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167,43,172,9,
         129,22,39,253,19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
         251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,
         49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127,4,150,254,
         138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180};
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
		return (color_add(color_fact(no.obj.tex.tex_col1, (float)(n - v1) / (float)(v2 - v1)),
			color_fact(no.obj.tex.tex_col2, (float)(v2 - n) / (float)(v2 - v1))));
	}
	else if (v2 < n && n < v3)
	{
		return (color_add(color_fact(no.obj.tex.tex_col2, (float)(n - v2) / (float)(v3 - v2)),
			color_fact(no.obj.tex.tex_col3, (float)(v3 - n) / (float)(v3 - v2))));
	}
	else
		return (no.obj.tex.tex_col3);
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
		return(procedural_texture(no));
	return(no.obj.color);
}
