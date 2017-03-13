/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:14:15 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 18:16:54 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d		vector_add(t_vec3d a, t_vec3d b)
{
	t_vec3d	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	ret.w = 1;
	return (ret);
}

t_vec3d		vector_sub(t_vec3d a, t_vec3d b)
{
	t_vec3d	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	ret.w = 1;
	return (ret);
}

t_vec3d		vector_fact(t_vec3d a, float k)
{
	t_vec3d	ret;

	ret.x = a.x * k;
	ret.y = a.y * k;
	ret.z = a.z * k;
	ret.w = a.w;
	return (ret);
}

float		vector_dot(t_vec3d a, t_vec3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float		vector_length(t_vec3d a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}
