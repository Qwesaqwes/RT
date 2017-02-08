/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:48:35 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/03 14:48:38 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	cone_dist(t_ray r)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = r.dir.x * r.dir.x + r.dir.y * r.dir.y - r.dir.z * r.dir.z;
	b = 2 * (r.origin.x * r.dir.x) + 2 * (r.origin.y * r.dir.y) - 2 * (r.origin.z * r.dir.z);
	c = (r.origin.x * r.origin.x) + (r.origin.y * r.origin.y) - (r.origin.z * r.origin.z);
	d = (b * b) - (4 * a * c);

	if (d >= 0)
		return (compute_solution(a, b, d));
	else
		return (-1);
}

t_vec3d		cone_normal_vec(t_no no)
{
	t_vec3d normal;
	t_vec3d zero_ip;
	double	centre_z;

	zero_ip = inter_point_to_zero(no.obj, no.ip);

	centre_z = (zero_ip.x * zero_ip.x + zero_ip.y * zero_ip.y) / zero_ip.z + zero_ip.z; //zero.ip^2 car cord de vect = cord de inter_point

	normal.x = zero_ip.x;
	normal.y = zero_ip.y;
	normal.z = zero_ip.z - centre_z;
	normal.w = 1;

	normal = mult_matrix(rotationX(no.obj.transform.rot.x), normal);
	normal = mult_matrix(rotationY(no.obj.transform.rot.y), normal);
	normal = mult_matrix(rotationZ(no.obj.transform.rot.z), normal);
	return (normal);
}
