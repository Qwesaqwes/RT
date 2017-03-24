/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:59:01 by dsusheno          #+#    #+#             */
/*   Updated: 2017/03/24 14:59:12 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		cone_dist(t_ray r, t_obj obj)
{
	t_dist		dist;
	double		t;

	dist.a = r.dir.x * r.dir.x + r.dir.y * r.dir.y - r.dir.z * r.dir.z;
	dist.b = 2 * (r.origin.x * r.dir.x) + 2 * (r.origin.y * r.dir.y)
	- 2 * (r.origin.z * r.dir.z);
	dist.c = (r.origin.x * r.origin.x) + (r.origin.y * r.origin.y)
	- (r.origin.z * r.origin.z);
	dist.d = (dist.b * dist.b) - (4 * dist.a * dist.c);
	if (dist.d >= 0)
	{
		t = compute_solution(dist, r, obj);
		return (t);
	}
	else
		return (-1);
}

t_vec3d		cone_normal_vec(t_no no)
{
	t_vec3d	normal;
	t_vec3d	zero_ip;
	double	centre_z;

	zero_ip = inter_point_to_zero(no.obj, no.ip);
	centre_z = (zero_ip.x * zero_ip.x + zero_ip.y * zero_ip.y) /
	zero_ip.z + zero_ip.z;
	normal.x = zero_ip.x;
	normal.y = zero_ip.y;
	normal.z = zero_ip.z - centre_z;
	normal.w = 1;
	normal = mult_matrix(rotationX(no.obj.transform.rot.x), normal);
	normal = mult_matrix(rotationY(no.obj.transform.rot.y), normal);
	normal = mult_matrix(rotationZ(no.obj.transform.rot.z), normal);
	return (normal);
}
