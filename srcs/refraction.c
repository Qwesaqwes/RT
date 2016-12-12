/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 06:52:16 by opandolf          #+#    #+#             */
/*   Updated: 2016/12/09 07:03:24 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"



t_color		refraction(t_no no, t_scene s, t_vec3d n, t_values v)
{
	float	r;
	float	cosT;
	float	cosP;
	t_ray	refracted;

	refracted.origin = vector_sub(no.ip, vector_fact(n, SHADOW_BIAS));
	cosT = vector_scalar_product(n, vector_fact(no.origin.dir, -1));
	//si je rentre dans un objet cosT > 0.0
	if (cosT > 0.0)
	{
		//n1 = derniere valueur ajoutée dans la liste
		//n2 = valeur no.obj
		r = (float)(*(float*)v.refr_index->content) / (float)no.obj.refr_index;
		//ajouter n2 dans la liste;
	}
	//si je sors
	else
	{
		//n1 = valeur no.obj
		//n2 = derniere valeur liste
		r = (float)no.obj.refr_index / (float)(*(float*)v.refr_index->content);
		//supprimer n2 liste
		cosT = -cosT;
	}
	cosP = sqrt(1 - r * r * (1 - cosT * cosT));
	refracted.dir = vector_add(vector_fact(no.origin.dir, r), vector_fact(n, r * cosT - cosP));
	v.depth = v.depth + 1;
	return(compute_ray(refracted, s, v));
}
