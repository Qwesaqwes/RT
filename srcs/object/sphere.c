/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 06:04:57 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 16:08:03 by jichen-m         ###   ########.fr       */
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

float	sphere_dist(t_ray r)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = r.dir.x * r.dir.x + r.dir.y * r.dir.y + r.dir.z * r.dir.z;
	b = 2 * (r.origin.x * r.dir.x) + 2 * (r.origin.y * r.dir.y) + 2 *
	(r.origin.z * r.dir.z);
	c = (r.origin.x * r.origin.x) + (r.origin.y * r.origin.y) +
	(r.origin.z * r.origin.z) - 1;
	d = (b * b) - (4 * a * c);
	if (d >= 0)
		return (compute_solution(a, b, d));
	else
		return (-1);
}

t_vec3d	sphere_normal_vec(t_vec3d ip, t_vec3d t)
{
	t_vec3d normal;

	normal = vector_sub(ip, t);
	return (normal);
}
