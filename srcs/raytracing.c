/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:22:46 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:59:53 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		set_camera(t_camera *cam)
{
	cam->vectorU = rota_vect(cam->baseU, cam->rot);
	cam->vectorV = rota_vect(cam->baseV, cam->rot);
	cam->vectorW = rota_vect(cam->baseW, cam->rot);
}

t_vec3d		vector_add3(t_vec3d a, t_vec3d b, t_vec3d c)
{
	return (vector_add(vector_add(a, b), c));
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
	tmp2 = vector_add3(vector_fact(cam.vectorU, tmp.x),
		vector_fact(cam.vectorV, tmp.y), vector_fact(cam.vectorW, tmp.z));
	ray.origin = vector_add(tmp2, cam.origin);
	ray.origin.w = 1;
	ray.dir = normalizevec(tmp2);
	return (ray);
}

t_rgb		color_to_rgb(t_color old)
{
	t_rgb	new;

	new.red = old.red * 255;
	new.green = old.green * 255;
	new.blue = old.blue * 255;
	return (new);
}

void		raytracing_column_aa(t_env *e, t_list *first_el, int h_start)
{
	t_ray		ray;
	t_color		color;
	t_values	v;
	int			i;
	int			j;
	int			k;

	i = 0;
	color = set_black_color();
	while (i < W)
	{
		j = -1;
		while (++j < e->scene.antialiasing)
		{
			k = -1;
			while (++k < e->scene.antialiasing)
			{
				ray = set_ray(e->camera, e->vp,
					i - 0.5 + (1.0f / (float)(e->scene.antialiasing - 1)) * j,
					h_start - 0.5 + (1.0f /
						(float)(e->scene.antialiasing - 1)) * k);
				v.depth = 0;
				v.id_refl = -1;
				first_el = ft_lstnew(&e->scene.refr_index, sizeof(float));
				v.refr_index = &first_el;
				v.enter = 0;
				color = color_add_no_limit(compute_ray(ray, e->scene, v),
				color);
			}
		}
		color = color_fact(color, 1.0f /
			(float)(e->scene.antialiasing * e->scene.antialiasing));
		ft_pixel_put(i, h_start, color_to_rgb(color), *e);
		i++;
	}
}

void		raytracing_column(t_env *e, t_list *first_el, int h_start)
{
	t_ray		ray;
	t_rgb		color;
	t_values	v;
	int			i;

	i = 0;
	while (i < W)
	{
		ray = set_ray(e->camera, e->vp, i, h_start);
		v.depth = 0;
		v.id_refl = -1;
		first_el = ft_lstnew(&e->scene.refr_index, sizeof(float));
		v.refr_index = &first_el;
		v.enter = 0;
		color = color_to_rgb(compute_ray(ray, e->scene, v));
		ft_pixel_put(i, h_start, color, *e);
		i++;
	}
}

static void	*ft_task(void *p_data)
{
	t_thread_data		*data;
	t_list				*first_el;

	data = p_data;
	first_el = NULL;
	while (data->h_start < data->h_end)
	{
		if (data->e->scene.antialiasing == 1)
			raytracing_column(data->e, first_el, data->h_start);
		else if (data->e->scene.antialiasing > 1)
			raytracing_column_aa(data->e, first_el, data->h_start);
		else
			return (NULL);
		data->h_start++;
	}
	return (NULL);
}

void		data_for_thread(t_thread_data *data, t_env *e)
{
	int	i;
	int	h_start;
	int	h_end;
	int h_part;

	i = 0;
	h_start = 0;
	h_part = H / NB_THREAD;
	h_end = h_part;
	while (i < NB_THREAD)
	{
		data[i].h_start = h_start;
		data[i].h_end = h_end;
		data[i].e = e;
		h_start += h_part;
		h_end += h_part;
		i++;
	}
}

void		check_effect(t_env *e)
{
	if (e->gtk.nb_effect == 0)
		no_effect(e);
	else if (e->gtk.nb_effect == 1)
		sepia_effect(e);
	else if (e->gtk.nb_effect == 2)
		greyscale_effect(e);
	else if (e->gtk.nb_effect == 3)
		sobel_effect(e);
	else if (e->gtk.nb_effect == 4)
		cartoon_effect(e);
	else if (e->gtk.nb_effect == 5)
		motion_effec(e);
	else if (e->gtk.nb_effect == 6)
		blur_effec(e);
}

void		set_camera_stereo(t_camera *cam_origin, float fac)
{
	cam_origin->origin = vector_add(cam_origin->origin,
	vector_fact(cam_origin->vectorW, fac));
}

void		raytracing(t_env *e)
{
	pthread_t			*task;
	t_thread_data		*data;
	int					i;

	i = -1;
	task = (pthread_t *)malloc(sizeof(pthread_t) * NB_THREAD);
	data = (t_thread_data *)malloc(sizeof(t_thread_data) * NB_THREAD);
	set_camera(&(e->camera));
	if (e->gtk.nb_effect == 7)
	{
		e->gtk.tmp_buf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, W, H);
		set_camera_stereo(&e->camera, -0.2);
	}
	data_for_thread(data, e);
	while (++i < NB_THREAD)
		pthread_create(&task[i], NULL, ft_task, &data[i]);
	i = -1;
	while (++i < NB_THREAD)
		pthread_join(task[i], NULL);
	check_effect(e);
	if (e->gtk.nb_effect == 7)
		set_camera_stereo(&e->camera, 0.2);
	free(data);
	free(task);
}
