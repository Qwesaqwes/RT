/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:14:28 by opandolf          #+#    #+#             */
/*   Updated: 2017/04/02 17:45:06 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cal_quadrics_dist(t_dist *dist, t_obj obj, t_ray r)
{
	dist->a = obj.quadrics.a * r.dir.x * r.dir.x +
		obj.quadrics.b * r.dir.y * r.dir.y +
		obj.quadrics.c * r.dir.z * r.dir.z +
		obj.quadrics.d * r.dir.x * r.dir.y +
		obj.quadrics.e * r.dir.x * r.dir.z +
		obj.quadrics.f * r.dir.y * r.dir.z;
	dist->b = 2 * (obj.quadrics.a * r.origin.x * r.dir.x +
		obj.quadrics.b * r.origin.y * r.dir.y +
		obj.quadrics.c * r.origin.z * r.dir.z) +
		obj.quadrics.d * (r.origin.x * r.dir.y + r.origin.y * r.dir.x) +
		obj.quadrics.e * (r.origin.x * r.dir.z + r.origin.z * r.dir.x) +
		obj.quadrics.f * (r.origin.y * r.dir.z + r.dir.y * r.origin.z) +
		obj.quadrics.g * r.dir.x + obj.quadrics.h * r.dir.y +
		obj.quadrics.i * r.dir.z;
	dist->c = obj.quadrics.a * r.origin.x * r.origin.x +
		obj.quadrics.c * r.origin.y * r.origin.y +
		obj.quadrics.c * r.origin.z * r.origin.z +
		obj.quadrics.d * r.origin.x * r.origin.y +
		obj.quadrics.e * r.origin.x * r.origin.z +
		obj.quadrics.f * r.origin.y * r.origin.z +
		obj.quadrics.g * r.origin.x +
		obj.quadrics.h * r.origin.y +
		obj.quadrics.i * r.origin.z + obj.quadrics.j;
	dist->d = (dist->b * dist->b) - (4 * dist->a * dist->c);
}

float		quadrics_dist(t_ray r, t_obj obj)
{
	t_dist		dist;
	double		t;

	cal_quadrics_dist(&dist, obj, r);
	if (dist.d >= 0)
	{
		t = compute_solution(dist, r, obj);
		return (t);
	}
	else
		return (-1);
}

t_vec3d		quadrics_normal_vec(t_vec3d ip, t_quadrics q)
{
	t_vec3d		normal;

	normal.x = 2 * q.a * ip.x + q.d * ip.y + q.e * ip.z + q.g;
	normal.y = 2 * q.b * ip.y + q.d * ip.x + q.f * ip.z + q.h;
	normal.z = 2 * q.c * ip.z + q.e * ip.x + q.f * ip.y + q.i;
	normal.w = 1;
	normal = normalizevec(normal);
	return (normal);
}
