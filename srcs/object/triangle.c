/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:36:52 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 18:15:29 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			inside_outside_test(t_vertex *vertex, int sign, t_vec3d point,
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
		sign = 1;
		if ((sign * vector_dot(normal, vector_cross(edge, c))) < 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

float		triangle_dist(t_ray ray, t_face obj)
{
	float		dist;
	t_vec3d		point;
	int			sign;

	sign = 1;
	dist = plane_dist2(obj, ray);
	if (dist < SHADOW_BIAS)
		return (dist);
	point = set_inter_point(dist, ray);
	if (vector_dot(obj.normal, ray.dir) > 0)
		sign = -1;
	if (inside_outside_test(obj.vertex, sign, point, obj.normal)
		== 1)
		return (dist);
	return (-1);
}
