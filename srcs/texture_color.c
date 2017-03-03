/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:37:04 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/03 20:23:14 by jichen-m         ###   ########.fr       */
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

t_color		procedural_texture(t_no no)
{
	return(checker(no));
}

t_color		texture_color(t_no no)
{
	if (no.obj.tex.texture == 1)
		return(procedural_texture(no));
	return(no.obj.color);
}
