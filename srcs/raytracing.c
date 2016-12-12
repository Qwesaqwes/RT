/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:22:46 by jichen-m          #+#    #+#             */
/*   Updated: 2016/12/12 17:34:41 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_camera(t_camera *cam)
{
	cam->vectorU = rota_vect(cam->baseU, cam->rot);
	cam->vectorV = rota_vect(cam->baseV, cam->rot);
	cam->vectorW = rota_vect(cam->baseW, cam->rot);
}

t_vec3d	vector_add3(t_vec3d a, t_vec3d b, t_vec3d c)
{
	return (vector_add(vector_add(a, b), c));
}

t_ray	set_ray(t_camera cam, t_vp vp, int i, int j)
{
	t_vec3d		tmp;
	t_vec3d		tmp2;
	t_ray		ray;

	tmp.z = -((float)vp.width / 2.0f) + (float)(vp.width * i) / (float)(W - 1);
	tmp.y = -((float)vp.height / 2.0f) + (float)(vp.height * j) / (float)(H - 1);
	tmp.x = vp.dist;
	tmp2 = vector_add3(vector_fact(cam.vectorU, tmp.x), vector_fact(cam.vectorV, tmp.y), vector_fact(cam.vectorW, tmp.z));
	ray.origin = vector_add(tmp2, cam.origin);
	// ray.origin.x = tmp.x + cam.origin.x;
	// ray.origin.y = tmp.y + cam.origin.y;
	// ray.origin.z = tmp.z + cam.origin.z;
	ray.origin.w = 1;
	ray.dir = normalizevec(tmp2);
	return (ray);
}

t_rgb	color_to_rgb(t_color old)
{
	t_rgb	new;

	// new.red = (int)(old.red * 256);
	// new.green = (int)(old.green * 256);
	// new.blue = (int)(old.blue * 256);
	new.red = old.red * 255;
	new.green = old.green * 255;
	new.blue = old.blue * 255;
	return (new);
}

void	raytracing(t_env *e)
{
	int			i;
	int			j;
	t_ray		ray;
	t_rgb		color;
	t_values	v;
	t_list		*first_el;
	// appel de la fonction set_camera(...) qui renvoi un struct camera
	set_camera(&(e->camera));
	j = -1;
	while (++j < H)
	{
		i = -1;
		while (++i < W)
		{
			ray = set_ray(e->camera, e->vp, i, j);
			v.depth = 0;
			v.id_refl = -1;
			first_el = ft_lstnew(&e->scene.refr_index, sizeof(float));
			v.refr_index = &first_el;
			v.enter = 0;
			color = color_to_rgb(compute_ray(ray, e->scene, v));
			ft_pixel_put(i, j, color, *e);
		}
	}
}
