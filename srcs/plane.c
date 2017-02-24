/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:51:08 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/24 20:16:17 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float    plane_dist(t_obj obj, t_ray r)
{
	float	dist;
	float	normal_to_ray;
	t_vec3d vect_to_point;

	dist = -1;
	normal_to_ray = vector_dot(obj.normal, r.dir);

	if (normal_to_ray != 0)
	{
		vect_to_point = vector_sub(obj.transform.transl, r.origin);
		dist = (float)vector_dot(obj.normal, vect_to_point) / (float)normal_to_ray;
	}
	if (dist > 0)
		return (dist);
	else
		return (-1);
}
