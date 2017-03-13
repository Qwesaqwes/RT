/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:21:31 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 17:22:18 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		complete_vec(float a, float b, float c, t_vec3d *ret)
{
	ret->x = a;
	ret->y = b;
	ret->z = c;
	ret->w = 0;
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
