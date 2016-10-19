/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 06:04:57 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/19 06:26:46 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	compute_solution(float a, float b, float c, float d)
{
	float	t1;
	float	t2;

	if (d > 0)
	{
		t1 = (-b + sqrt(d)) / (2 * a);
		t2 = (-b - sqrt(d)) / (2 * a);
		if (t1 >= 0 && t2 >= 0)
			return (fmin(t1, t2));
		else if (t1 < 0 || t2 < 0)
			return (fmax(t1, t2));
		else
			return (-1);
	}
	else
	{
		t1 = -b / (2 * a);
		if (t1 >= 0)
			return (t1);
		else
			return (-1);
	}
}

float	sphere_dist(t_ray r, t_obj o)
{
	float	a;
	float	b;
	float	c;
	float	d;

	a = r.dir.x * r.dir.x * r.dir.y * r.dir.y * r.dir.z * r.dir.z;
	b = 2 * r.dir.x + (r.origin.x - o.center.x) +
	2 * r.dir.y + (r.origin.y - o.center.y) +
	2 * r.dir.z + (r.origin.z - o.center.z);
	c = ((r.origin.x - o.center.x) ^ 2 + (r.origin.y - o.center.y) ^ 2 +
	(r.origin.z - o.center.z) ^ 2) + (o.radius ^ 2);
	d = b ^ 2 - 4 * a * c;
	if (d >= 0)
		return (compute_solution(a, b, c, d));
	else
		return (-1);
}
