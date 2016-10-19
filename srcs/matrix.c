/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 03:32:59 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/19 04:04:19 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_matrix		rotationX(float angle)
{
	t_matrix	matrix;

	angle = angle * (M_PI / 180);
	matrix.a = 1;
	matrix.b = 0;
	matrix.c = 0;
	matrix.d = 0;
	matrix.e = cos(angle);
	matrix.f = -sin(angle);
	matrix.g = 0;
	matrix.h = sin(angle);
	matrix.i = cos(angle);
	return (matrix);
}

static t_matrix		rotationY(float angle)
{
	t_matrix	matrix;

	angle = angle * (M_PI / 180);
	matrix.a = cos(angle);
	matrix.b = 0;
	matrix.c = sin(angle);
	matrix.d = 0;
	matrix.e = 1;
	matrix.f = 0;
	matrix.g = -sin(angle);
	matrix.h = 0;
	matrix.i = cos(angle);
	return (matrix);
}

static t_matrix		rotationZ(float angle)
{
	t_matrix	matrix;

	angle = angle * (M_PI / 180);
	matrix.a = cos(angle);
	matrix.b = -sin(angle);
	matrix.c = 0;
	matrix.d = sin(angle);
	matrix.e = cos(angle);
	matrix.f = 0;
	matrix.g = 0;
	matrix.h = 0;
	matrix.i = 1;
	return (matrix);
}

static t_vec3d		mult_matrix(t_matrix mat, t_vec3d old)
{
	t_vec3d		new;

	new.x = mat.a * old.x + mat.b * old.y + mat.c * old.z;
	new.y = mat.d * old.x + mat.e * old.y + mat.f * old.z;
	new.z = mat.g * old.x + mat.h * old.y + mat.i * old.z;
	return (new);
}

t_vec3d				rota_vect(t_vec3d old, float angleX, float angleY, float angleZ)
{
	t_vec3d		new;

	new = mult_matrix(rotationX(angleX), old);
	new = mult_matrix(rotationY(angleY), new);
	new = mult_matrix(rotationZ(angleZ), new);
	new = normalizevec(new);
	return (new);
}
