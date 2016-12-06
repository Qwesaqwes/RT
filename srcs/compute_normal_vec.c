/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_normal_vec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:56:33 by opandolf          #+#    #+#             */
/*   Updated: 2016/12/06 09:00:32 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d	compute_normal_vec(t_no no)
{
	t_vec3d	normal;

	if (no.obj.type == 0)
	{
		normal = sphere_normal_vec(no.ip, no.obj.transform.transl);
	}
	else
	{
		normal.x = 0;
		normal.y = 0;
		normal.z = 0;
		normal.w = 1;
	}
	//calcul normal_vec (N = R * NI)
	normal = mult_matrix(rotationX(no.obj.transform.rot.x), normal);
	normal = mult_matrix(rotationY(no.obj.transform.rot.y), normal);
	normal = mult_matrix(rotationZ(no.obj.transform.rot.z), normal);
	normal = normalizevec(normal);
	return (normal);
}