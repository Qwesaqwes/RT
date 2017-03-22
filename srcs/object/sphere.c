/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 06:04:57 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/22 21:38:16 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float 	t1_search(t_dist dist, t_obj obj, t_ray r)
{
	float 		t1;
	t_vec3d		ip1;

	t1 = (double)(-dist.b + sqrt(dist.d)) / (double)(2 * dist.a);
	ip1 = set_inter_point(t1, r);
	if ((obj.limit.exist.z_min == 1 && ip1.z < obj.limit.z_min)
	|| (obj.limit.exist.z_max == 1 && ip1.z > obj.limit.z_max)
	|| (obj.limit.exist.y_min == 1 && ip1.y < obj.limit.y_min)
	|| (obj.limit.exist.y_max == 1 && ip1.y > obj.limit.y_max)
	|| (obj.limit.exist.x_min == 1 && ip1.x < obj.limit.x_min)
	|| (obj.limit.exist.x_max == 1 && ip1.x > obj.limit.x_max))
		return(-1);
	return (t1);
}

float 	t2_search(t_dist dist, t_obj obj, t_ray r)
{
	float 		t2;
	t_vec3d		ip2;

	t2 = (double)(-dist.b - sqrt(dist.d)) / (double)(2 * dist.a);
	ip2 = set_inter_point(t2, r);
	if ((obj.limit.exist.z_min == 1 && ip2.z < obj.limit.z_min)
	|| (obj.limit.exist.z_max == 1 && ip2.z > obj.limit.z_max)
	|| (obj.limit.exist.y_min == 1 && ip2.y < obj.limit.y_min)
	|| (obj.limit.exist.y_max == 1 && ip2.y > obj.limit.y_max)
	|| (obj.limit.exist.x_min == 1 && ip2.x < obj.limit.x_min)
	|| (obj.limit.exist.x_max == 1 && ip2.x > obj.limit.x_max))
		return(-1);
	return (t2);
}

float	compute_solution(t_dist dist, t_ray r, t_obj obj)
{
	float		t1;
	float		t2;

	if (dist.d > 0)
	{
		t1 = t1_search(dist, obj, r);
		t2 = t2_search(dist, obj, r);
		if (t1 >= 0 && t2 >= 0)
			return (fmin(t1, t2));
		else if (t1 < 0 || t2 < 0)
			return (fmax(t1, t2));
		else
			return (-1);
	}
	else
	{
		t1 = (double)-dist.b / (double)(2 * dist.a);
		if (t1 >= 0)
				return (t1);
		else
			return (-1);
	}
}

float	sphere_dist(t_ray r, t_obj obj)
{
	t_dist		dist;
	double 		t;

	dist.a = r.dir.x * r.dir.x + r.dir.y * r.dir.y + r.dir.z * r.dir.z;
	dist.b = 2 * (r.origin.x * r.dir.x) + 2 * (r.origin.y * r.dir.y) + 2 *
	(r.origin.z * r.dir.z);
	dist.c = (r.origin.x * r.origin.x) + (r.origin.y * r.origin.y) +
	(r.origin.z * r.origin.z) - 1;
	dist.d = (dist.b * dist.b) - (4 * dist.a * dist.c);
	if (dist.d >= 0)
	{
		t = compute_solution(dist, r, obj);
		return (t);
	}
	else
		return (-1);
}

t_vec3d	sphere_normal_vec(t_vec3d ip, t_vec3d t)
{
	t_vec3d normal;

	normal = vector_sub(ip, t);
	return (normal);
}
