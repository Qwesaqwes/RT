/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 03:32:59 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 20:23:39 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrix		rotation_x(float angle)
{
	t_matrix	matrix;

	angle = angle * (M_PI / 180);
	matrix.a = 1;
	matrix.b = 0;
	matrix.c = 0;
	matrix.d = 0;
	matrix.e = 0;
	matrix.f = cos(angle);
	matrix.g = -sin(angle);
	matrix.h = 0;
	matrix.i = 0;
	matrix.j = sin(angle);
	matrix.k = cos(angle);
	matrix.l = 0;
	matrix.m = 0;
	matrix.n = 0;
	matrix.o = 0;
	matrix.p = 1;
	return (matrix);
}

t_matrix		rotation_y(float angle)
{
	t_matrix	matrix;

	angle = angle * (M_PI / 180);
	matrix.a = cos(angle);
	matrix.b = 0;
	matrix.c = sin(angle);
	matrix.d = 0;
	matrix.e = 0;
	matrix.f = 1;
	matrix.g = 0;
	matrix.h = 0;
	matrix.i = -sin(angle);
	matrix.j = 0;
	matrix.k = cos(angle);
	matrix.l = 0;
	matrix.m = 0;
	matrix.n = 0;
	matrix.o = 0;
	matrix.p = 1;
	return (matrix);
}

t_matrix		rotation_z(float angle)
{
	t_matrix	matrix;

	angle = angle * (M_PI / 180);
	matrix.a = cos(angle);
	matrix.b = -sin(angle);
	matrix.c = 0;
	matrix.d = 0;
	matrix.e = sin(angle);
	matrix.f = cos(angle);
	matrix.g = 0;
	matrix.h = 0;
	matrix.i = 0;
	matrix.j = 0;
	matrix.k = 1;
	matrix.l = 0;
	matrix.m = 0;
	matrix.n = 0;
	matrix.o = 0;
	matrix.p = 1;
	return (matrix);
}

t_vec3d			mult_matrix(t_matrix mat, t_vec3d old)
{
	t_vec3d		new;

	new.x = mat.a * old.x + mat.b * old.y + mat.c * old.z + mat.d * old.w;
	new.y = mat.e * old.x + mat.f * old.y + mat.g * old.z + mat.h * old.w;
	new.z = mat.i * old.x + mat.j * old.y + mat.k * old.z + mat.l * old.w;
	new.w = 1;
	return (new);
}

t_vec3d			rota_vect(t_vec3d old, t_vec3d rot)
{
	t_vec3d		new;

	new = mult_matrix(rotation_x(rot.x), old);
	new = mult_matrix(rotation_y(rot.y), new);
	new = mult_matrix(rotation_z(rot.z), new);
	new = normalizevec(new);
	return (new);
}
