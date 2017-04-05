/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:17:23 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/05 19:29:11 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		coord_mapping(t_vertex *tmp, t_face face, t_vec3d point,
t_mapping *ret)
{
	if (tmp == face.vertex)
		*ret = (t_mapping){point.y, point.y, point.z, point.z};
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
		point = mult_matrix(rotation_x(-rot.x), point);
		point = mult_matrix(rotation_y(-rot.y), point);
		point = mult_matrix(rotation_z(-rot.z), point);
		coord_mapping(tmp, face, point, &ret);
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
	n = mult_matrix(rotation_x(-rot_angle->x), n);
	n = mult_matrix(rotation_y(-rot_angle->y), n);
	n = mult_matrix(rotation_z(-rot_angle->z), n);
	*u = (float)(n.z - map.z_min) / (float)(map.z_max - map.z_min);
	*v = (float)(n.y - map.y_min) / (float)(map.y_max - map.y_min);
}

t_color		texture_mapping(t_no no)
{
	float		u;
	float		v;
	t_vec3d		rot_angle;

	if (no.obj.type == 0)
	{
		uv_sphere(no, &u, &v, &rot_angle);
		return (get_pixel(map_value(u, v, no.obj.map_buf), no.obj.map_buf));
	}
	else if (no.obj.type == 5 || no.obj.type == 6)
	{
		uv_polygone(no, &u, &v, &rot_angle);
		return (get_pixel(map_value(u, v, no.obj.map_buf), no.obj.map_buf));
	}
	return (set_black());
}
