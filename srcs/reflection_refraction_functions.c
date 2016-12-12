/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_refraction_functions.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 04:32:56 by opandolf          #+#    #+#             */
/*   Updated: 2016/12/12 13:23:43 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_lstdelfirst(t_list **alst)
{
	t_list	*tmp;

	tmp = *alst;
	if (tmp == NULL)
		return;
	*alst = tmp->next;
	free (tmp);
}

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
	cv->sinT2 = cv->n * cv->n * (1 - cv->cosI * cv->cosI);
	if (cv->sinT2 > 1.0)
	{
		cv->cosT = 0;
		cv->TIR = 1;
	}
	else
	{
		cv->cosT = sqrt(1 - cv->sinT2);
		cv->TIR = 0;
	}
}

t_ray		reflect(t_vec3d normal, t_vec3d incident, t_vec3d ip, t_cv cv)
{
	t_ray	ret;

	ret.origin = vector_add(ip, vector_fact(normal, SHADOW_BIAS));
	ret.dir = vector_add(incident, vector_fact(normal, 2 * cv.cosI));
	return (ret);
}

t_ray		refract(t_vec3d normal, t_vec3d incident, t_vec3d ip, t_cv cv)
{
	t_ray	ret;

	ret.origin = vector_sub(ip, vector_fact(normal, SHADOW_BIAS));
	ret.dir = vector_add(vector_fact(incident, cv.n), vector_fact(normal, cv.n * cv.cosI - cv.cosT));
	return (ret);
}

float		fresnel(t_cv cv)
{
	float	ror;
	float	rpa;

	ror = (float)(cv.n1 * cv.cosI - cv.n2 * cv.cosT) / (float)(cv.n1 * cv.cosI + cv.n2 * cv.cosT);
	rpa = (float)(cv.n2 * cv.cosI - cv.n1 * cv.cosT) / (float)(cv.n2 * cv.cosI + cv.n1 * cv.cosT);
	return ((float)(ror * ror + rpa * rpa) / (float)(2));
}

float		schlick(t_cv cv)
{
	float	r0;
	float	x;

	r0 = (float)(cv.n1 - cv.n2) / (float)(cv.n1 + cv.n2);
	r0 *= r0;
	if (cv.n > 1.0)
		x = 1.0 - cv.cosT;
	else
		x = 1.0 - cv.cosI;
	return (r0 + (1.0 - r0) * x * x * x * x * x);
}
