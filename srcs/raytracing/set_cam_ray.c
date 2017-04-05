/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:50:12 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/03 18:52:03 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d		vector_add3(t_vec3d a, t_vec3d b, t_vec3d c)
{
	return (vector_add(vector_add(a, b), c));
}

void		set_camera(t_camera *cam)
{
	cam->vector_u = rota_vect(cam->base_u, cam->rot);
	cam->vector_v = rota_vect(cam->base_v, cam->rot);
	cam->vector_w = rota_vect(cam->base_w, cam->rot);
}

t_ray		set_ray(t_camera cam, t_vp vp, float i, float j)
{
	t_vec3d		tmp;
	t_vec3d		tmp2;
	t_ray		ray;

	tmp.z = -((float)vp.width / 2.0f) + (float)(vp.width * i) / (float)(W - 1);
	tmp.y = -((float)vp.height / 2.0f) +
		(float)(vp.height * (H - j)) / (float)(H - 1);
	tmp.x = vp.dist;
	tmp2 = vector_add3(vector_fact(cam.vector_u, tmp.x),
		vector_fact(cam.vector_v, tmp.y), vector_fact(cam.vector_w, tmp.z));
	ray.origin = vector_add(tmp2, cam.origin);
	ray.origin.w = 1;
	ray.dir = normalizevec(tmp2);
	return (ray);
}

void		set_camera_stereo(t_camera *cam_origin, float fac)
{
	cam_origin->origin = vector_add(cam_origin->origin,
	vector_fact(cam_origin->vector_w, fac));
}
