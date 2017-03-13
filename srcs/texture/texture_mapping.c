/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:58:33 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 17:22:22 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d		euler_angles(t_matrix m)
{
	t_vec3d		ret;

	if (m.c < 1)
	{
		if (m.c > -1)
			complete_vec(atan2(-m.g, m.k), asin(m.c), atan2(-m.b, m.a), &ret);
		else
			complete_vec(-atan2(m.e, m.f), -M_PI / 2, 0, &ret);
	}
	else
	{
		complete_vec(atan2(m.e, m.f), M_PI / 2, 0, &ret);
	}
	ret = vector_fact(ret, 180.0f / M_PI);
	return (ret);
}

void		mapping2(t_mapping *ret, t_vec3d point, t_vertex *tmp, t_vertex *v)
{
	if (tmp == v)
	{
		ret->y_min = point.y;
		ret->y_max = point.y;
		ret->z_min = point.z;
		ret->z_max = point.z;
	}
	else
	{
		if (point.y < ret->y_min)
			ret->y_min = point.y;
		if (point.y > ret->y_max)
			ret->y_max = point.y;
		if (point.z < ret->z_min)
			ret->z_min = point.z;
		if (point.z > ret->z_max)
			ret->z_max = point.z;
	}
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
		mapping2(&ret, point, tmp, face.vertex);
		tmp = tmp->next;
	}
	return (ret);
}

void		uv_sphere(t_no no, float *u, float *v, t_vec3d *rot_angle)
{
	t_vec3d		n;

	*rot_angle = no.obj.transform.rot;
	n = normalizevec(vector_sub(no.obj.transform.transl, no.ip));
	*u = 0.5 + (float)atan2(n.z, n.x) / (float)(2 * M_PI);
	*v = 0.5 - (float)asin(n.y) / (float)M_PI;
}

void		uv_polygone(t_no no, float *u, float *v, t_vec3d *rot_angle)
{
	float		angle;
	t_vec3d		unit_vec;
	t_mapping	map;
	t_vec3d		n;

	angle = acos(vector_dot(no.poly_face->normal, (t_vec3d){1, 0, 0, 1}));
	unit_vec = vector_cross(no.poly_face->normal, (t_vec3d){1, 0, 0, 1});
	*rot_angle = euler_angles(axe_angle_to_matrix(angle, unit_vec));
	map = mapping(*no.poly_face, *rot_angle);
	n = vector_sub(no.ip, no.poly_face->vertex->coord);
	n = mult_matrix(rotationX(-rot_angle->x), n);
	n = mult_matrix(rotationY(-rot_angle->y), n);
	n = mult_matrix(rotationZ(-rot_angle->z), n);
	*u = (float)(n.z - map.z_min) / (float)(map.z_max - map.z_min);
	*v = (float)(n.y - map.y_min) / (float)(map.y_max - map.y_min);
}
