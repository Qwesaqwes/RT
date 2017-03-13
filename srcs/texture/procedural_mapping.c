/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:10:53 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 16:52:52 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		wood_coef(float x, float y, float z)
{
	float v;

	v = 20 * perlin_coef(x, y, z);
	return (v - floor(v));
}

float		marble_coef(float x, float y, float z)
{
	return (cos(x + perlin_coef(x, y, z)));
}

t_color		color_for_perlin(t_no no, float n)
{
	float	v1;
	float	v2;
	float	v3;

	v1 = -0.5;
	v2 = 0;
	v3 = 0.5;
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

float		choose_perlin(t_no no)
{
	float	n;

	n = 0;
	if (no.obj.tex.texture == 2)
		n = perlin_coef(no.ip.x, no.ip.y, no.ip.z);
	else if (no.obj.tex.texture == 3)
		n = wood_coef(no.ip.x, no.ip.y, no.ip.z);
	else if (no.obj.tex.texture == 4)
		n = marble_coef(no.ip.x * 20, no.ip.y * 20, no.ip.z * 20);
	return (n);
}

t_color		perlin_deriv(t_no no)
{
	float	n;

	n = 0;
	n = choose_perlin(no);
	return (color_for_perlin(no, n));
}
