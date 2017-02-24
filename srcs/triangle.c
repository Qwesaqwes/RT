/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:36:52 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/24 20:35:36 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		inside_outside_test(t_vertex *vertex, int sign, t_vec3d point)
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
		if ((sign * vector_dot(c, edge)) < 0)
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
	// printf("dist: %f\n", dist);
	if (dist < SHADOW_BIAS)
		return (dist);
	point = set_inter_point(dist, ray);
	if (vector_dot(obj.faces->normal, ray.dir) > 0)
		sign = -1;
	if (inside_outside_test(obj.faces->vertex, sign, point) == 1)
	{
		printf("dist: %f\n", dist);
		printf("img_rayx: %f\nimg_rayy: %f\nimg_rayz: %f\n\n", point.x, point.y, point.z);

		return(dist);
	}
	return (-1);
}
