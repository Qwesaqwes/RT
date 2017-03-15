/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_normal_vec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:56:33 by opandolf          #+#    #+#             */
/*   Updated: 2017/02/27 17:39:59 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d	compute_normal_vec(t_no no)
{
	t_vec3d	normal;

	if (no.obj.type == 0)
		normal = sphere_normal_vec(no.ip, no.obj.transform.transl);
	else if (no.obj.type == 1)
		normal = cylindre_normal_vec(no);
	else if (no.obj.type == 2)
		normal = rota_vect(no.obj.normal, no.obj.transform.rot);
	else if (no.obj.type == 3)
		normal = cone_normal_vec(no);
	else if (no.obj.type == 4)
		normal = no.obj.faces->normal;
	else if (no.obj.type == 5 || no.obj.type == 6)
		normal = no.poly_face->normal;
	else
	{
		normal.x = 0;
		normal.y = 0;
		normal.z = 0;
		normal.w = 1;
	}
	//calcul normal_vec (N = R * NI)
	//normal = mult_matrix(rotationX(no.obj.transform.rot.x), normal);
	//normal = mult_matrix(rotationY(no.obj.transform.rot.y), normal);
	//normal = mult_matrix(rotationZ(no.obj.transform.rot.z), normal);
	normal = normalizevec(normal);
	return (normal);
}
