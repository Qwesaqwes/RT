/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inver_origin_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:22:51 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/04 16:23:03 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d	set_inter_point(float dist, t_ray ray)
{
	t_vec3d new;

	new.x = ray.origin.x + ray.dir.x * dist;
	new.y = ray.origin.y + ray.dir.y * dist;
	new.z = ray.origin.z + ray.dir.z * dist;
	new.w = 1;
	return (new);
}

t_vec3d	inver_origin(t_vec3d origin, t_transform t)
{
	t_vec3d	new;

	new = mult_matrix(inver_transl_matrix(trans_matrix(t.transl)), origin);
	new = mult_matrix(inver_rot_matrix(rotation_x(t.rot.x)), new);
	new = mult_matrix(inver_rot_matrix(rotation_y(t.rot.y)), new);
	new = mult_matrix(inver_rot_matrix(rotation_z(t.rot.z)), new);
	new = mult_matrix(inver_scale_matrix(scale_matrix(t.scale)), new);
	return (new);
}

t_vec3d	inver_dir(t_vec3d dir, t_transform t)
{
	t_vec3d new;

	new = mult_matrix(inver_rot_matrix(rotation_x(t.rot.x)), dir);
	new = mult_matrix(inver_rot_matrix(rotation_y(t.rot.y)), new);
	new = mult_matrix(inver_rot_matrix(rotation_z(t.rot.z)), new);
	new = mult_matrix(inver_scale_matrix(scale_matrix(t.scale)), new);
	return (new);
}
