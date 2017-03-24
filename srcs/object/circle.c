/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <dsusheno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:03:13 by dsusheno          #+#    #+#             */
/*   Updated: 2017/03/24 16:55:30 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	circle_dist(t_ray ray, t_obj obj)
{
	float		t;
	float		y_2;
	float		z_2;
	t_vec3d		zero_ip;

	t = plane_dist(obj, ray);
	zero_ip = set_inter_point(t, ray);
	zero_ip = inter_point_to_zero(obj, zero_ip);
	y_2 = zero_ip.y * zero_ip.y;
	z_2 = zero_ip.x * zero_ip.x;
	if (sqrt(y_2 + z_2) <= obj.radius)
		return (t);
	else
		return (-1);
}
