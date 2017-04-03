/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:36:23 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/03 23:19:40 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		fil_values(t_values *v)
{
	v->depth = 0;
	v->id_refl = -1;
	v->enter = 0;
}

void		raytracing_column_aa(t_env *e, t_list *first_el, int h_start,
	t_color color)
{
	t_values	v;
	int			p[4];

	p[0] = -1;
	p[3] = e->scene.antialiasing;
	while (++p[0] < W)
	{
		p[1] = -1;
		while (++p[1] < p[3])
		{
			p[2] = -1;
			while (++p[2] < p[3])
			{
				fil_values(first_el, &v, e);
				first_el = ft_lstnew(&e->scene.refr_index, sizeof(float));
				v.refr_index = &first_el;
				color = color_add_no_limit(compute_ray(set_ray(e->camera, e->vp,
				p[0] - 0.5 + (1.0f / (float)(p[3] - 1)) * p[1], h_start - 0.5 +
				(1.0f / (float)(p[3] - 1)) * p[2]), e->scene, v), color);
				ft_lstdel(v.refr_index, ft_free_float);
			}
		}
		color = color_fact(color, 1.0f / (float)(p[3] * p[3]));
		ft_pixel_put(p[0], h_start, color_to_rgb(color), *e);
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
		ft_lstdel(v.refr_index, ft_free_float);
		ft_pixel_put(i, h_start, color, *e);
		i++;
	}
}

void		*ft_task(void *p_data)
{
	t_thread_data		*data;
	t_list				*first_el;
	t_color				color;

	data = p_data;
	first_el = NULL;
	color = set_black();
	while (data->h_start < data->h_end)
	{
		if (data->e->scene.antialiasing == 1)
			raytracing_column(data->e, first_el, data->h_start);
		else if (data->e->scene.antialiasing > 1)
			raytracing_column_aa(data->e, first_el, data->h_start, color);
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
