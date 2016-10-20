/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:22:46 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 04:15:59 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_camera(t_camera *cam)
{
	cam->vectorU = rota_vect(cam->baseU, cam->angleX, cam->angleY, cam->angleZ);
	cam->vectorV = rota_vect(cam->baseV, cam->angleX, cam->angleY, cam->angleZ);
	cam->vectorW = rota_vect(cam->baseW, cam->angleX, cam->angleY, cam->angleZ);
}

t_ray	set_ray(t_camera cam, t_vp vp, int i, int j)
{
	t_vec3d		tmp;
	t_ray		ray;

	tmp.z = (float)-(vp.width / 2) + (float)(vp.width * i) / (W - 1);
	tmp.y = -(vp.height / 2) + (vp.height * j) / (H - 1);
	tmp.x = vp.dist;
	ray.origin.x = tmp.x + cam.origin.x;
	ray.origin.y = tmp.y + cam.origin.y;
	ray.origin.z = tmp.z + cam.origin.z;
	ray.dir = normalizevec(tmp);
	return (ray);
}

t_rgb	color_to_rgb(t_color old)
{
	t_rgb	new;

	new.red = (int)(old.red * 256);
	new.green = (int)(old.green * 256);
	new.blue = (int)(old.blue * 256);
	return (new);
}

void	raytracing(t_env *e)
{
	int i;
	int j;
	t_ray	ray;
	t_rgb	color;
	// appel de la fonction init_camera(...) qui renvoi un struct camera
	set_camera(&(e->camera));
	j = -1;
	while (++j < H)
	{
		i = -1;
		while (++i < W)
		{
			ray = set_ray(e->camera, e->vp, i, j);
			color = color_to_rgb(compute_ray(ray, e->scene));
			ft_pixel_put(i, j, color, *e);
		}
	}
}
