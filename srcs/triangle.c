/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:36:52 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/25 01:35:00 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d		vector_cross(t_vec3d a, t_vec3d b)
{
	t_vec3d		ret;

	ret.x = a.y * b.z - a.z * b.y;
	ret.y = a.z * b.x - a.x * b.z;
	ret.z = a.x * b.y - a.y * b.x;
	ret.w = 1;
	return (ret);
}

int		inside_outside_test(t_vertex *vertex, int sign, t_vec3d point,
		t_vec3d normal)
{
	t_vertex	*tmp;
	t_vec3d		edge;
	t_vec3d		c;

	tmp = vertex;
	while (tmp)
	{
		c = vector_sub(point, tmp->coord);
		if (tmp->next == NULL)
			edge = vector_sub(vertex->coord, tmp->coord);
		else
			edge = vector_sub(tmp->next->coord, tmp->coord);
		if ((sign * vector_dot(normal, vector_cross(edge, c))) < 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

float	triangle_dist(t_ray ray, t_obj obj)
{
	float		dist;
	t_vec3d		point;
	int			sign;

	sign = 1;
	dist = plane_dist(obj, ray);
	if (dist < SHADOW_BIAS)
		return (dist);
	point = set_inter_point(dist, ray);
	if (vector_dot(obj.faces->normal, ray.dir) > 0)
		sign = -1;
	if (inside_outside_test(obj.faces->vertex, sign, point, obj.faces->normal)
		== 1)
		return(dist);
	return (-1);
}
