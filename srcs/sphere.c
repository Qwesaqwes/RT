/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 06:04:57 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 04:14:19 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	compute_solution(double a, double b, double d)
{
	double	t1;
	double	t2;

	if (d > 0)
	{
		t1 = (double)(-b + sqrt(d)) / (double)(2 * a);
		t2 = (double)(-b - sqrt(d)) / (double)(2 * a);
		if (t1 >= 0 && t2 >= 0)
			return (fmin(t1, t2));
		else if (t1 < 0 || t2 < 0)
			return (fmax(t1, t2));
		else
			return (-1);
	}
	else
	{
		t1 = (double)-b / (double)(2 * a);
		if (t1 >= 0)
			return (t1);
		else
			return (-1);
	}
}

float	sphere_dist(t_ray r, t_obj o)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = r.dir.x * r.dir.x + r.dir.y * r.dir.y + r.dir.z * r.dir.z;
	b = 2 * (r.origin.x - o.center.x) * r.dir.x +
	2 * (r.origin.y - o.center.y) * r.dir.y +
	2 * (r.origin.z - o.center.z) * r.dir.z;
	c = (r.origin.x - o.center.x) * (r.origin.x - o.center.x) +
	(r.origin.y - o.center.y) * (r.origin.y - o.center.y) +
	(r.origin.z - o.center.z) * (r.origin.z - o.center.z) -
	(o.radius * o.radius);
	d = b * b - 4 * a * c;
	printf("b = %f\n", b);
	printf("OX = %f, DX = %f\n", r.origin.x, r.dir.x);
	printf("OY = %f, DY = %f\n", r.origin.y, r.dir.y);
	printf("OZ = %f, DZ = %f\n\n\n", r.origin.z, r.dir.z);
	if (d >= 0)
		return (compute_solution(a, b, d));
	else
		return (-1);
}
