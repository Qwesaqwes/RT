/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_refraction_functions.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 04:32:56 by opandolf          #+#    #+#             */
/*   Updated: 2017/04/03 18:02:24 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_calculed_values(t_cv *cv, float n1, float n2)
{
	cv->n1 = n1;
	cv->n2 = n2;
	if (cv->sign < 0)
	{
		cv->n1 = n2;
		cv->n2 = n1;
	}
	cv->n = (float)cv->n1 / (float)cv->n2;
	cv->sint2 = cv->n * cv->n * (1 - cv->cosi * cv->cosi);
	if (cv->sint2 > 1.0)
	{
		cv->cost = 0;
		cv->tir = 1;
	}
	else
	{
		cv->cost = sqrt(1 - cv->sint2);
		cv->tir = 0;
	}
}

t_ray		reflect(t_vec3d normal, t_vec3d incident, t_vec3d ip, t_cv cv)
{
	t_ray	ret;

	ret.origin = vector_add(ip, vector_fact(normal, SHADOW_BIAS));
	ret.dir = vector_add(incident, vector_fact(normal, 2 * cv.cosi));
	return (ret);
}

t_ray		refract(t_vec3d normal, t_vec3d incident, t_vec3d ip, t_cv cv)
{
	t_ray	ret;

	ret.origin = vector_sub(ip, vector_fact(normal, SHADOW_BIAS));
	ret.dir = vector_add(vector_fact(incident, cv.n), vector_fact(normal,
		cv.n * cv.cosi - cv.cost));
	return (ret);
}

float		fresnel(t_cv cv)
{
	float	ror;
	float	rpa;

	ror = (float)(cv.n1 * cv.cosi - cv.n2 * cv.cost) /
		(float)(cv.n1 * cv.cosi + cv.n2 * cv.cost);
	rpa = (float)(cv.n2 * cv.cosi - cv.n1 * cv.cost) /
		(float)(cv.n2 * cv.cosi + cv.n1 * cv.cost);
	return ((float)(ror * ror + rpa * rpa) / (float)(2));
}

float		schlick(t_cv cv)
{
	float	r0;
	float	x;

	r0 = (float)(cv.n1 - cv.n2) / (float)(cv.n1 + cv.n2);
	r0 *= r0;
	if (cv.n > 1.0)
		x = 1.0 - cv.cost;
	else
		x = 1.0 - cv.cosi;
	return (r0 + (1.0 - r0) * x * x * x * x * x);
}
