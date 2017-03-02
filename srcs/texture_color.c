/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:37:04 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/02 22:14:42 by jichen-m         ###   ########.fr       */
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
	t_color		white;
	t_color		black;
	float		length;
	// int			j,k, i;
	t_vec3d		point;

	white = set_white_color();
	black = set_black_color();
	length = 0.3;
	// i = (int)(no.ip.x / length) % 2;
	// j = (int)(no.ip.y / length) % 2;
	// k = (int)(no.ip.z / length) % 2;
	// if (i ^ j ^ k)
	// 	return (white);
	// else
	// 	return (black);
	point = vector_sub(no.ip, no.obj.transform.transl);
	point = mult_matrix(rotationX(no.obj.transform.rot.x), point);
	point = mult_matrix(rotationY(no.obj.transform.rot.y), point);
	point = mult_matrix(rotationZ(no.obj.transform.rot.z), point);
	point = vector_add(point, no.obj.transform.transl);

	if (pair(point.z, length))
	{
		if (pair(point.y, length))
			return (white);
		else
			return (black);
	}
	else
	{
		if (pair(point.y, length))
			return (black);
		else
			return (white);
	}

	// if (pair(point.z, length))
	// {
	// 	if ((pair(point.x, length) && pair(point.y, length)) ||
	// 		(!pair(point.x, length) && !pair(point.y, length)))
	// 		return (white);
	// 	else
	// 		return (black);
	// }
	// else
	// {
	// 	if ((pair(point.x, length) && pair(point.y, length)) ||
	// 		(!pair(point.x, length) && !pair(point.y, length)))
	// 		return (black);
	// 	else
	// 		return (white);
	// }

	// i = ((no.ip.x  * length + no.ip.y * length + no.ip.z * length)) / 2;
	// if (i % 2 == 0)
	// 	return (white);
	// else
	// 	return (black);


}

t_color		procedural_texture(t_no no)
{
	return(checker(no));
}

t_color		texture_color(t_no no)
{
	return(procedural_texture(no));
}
