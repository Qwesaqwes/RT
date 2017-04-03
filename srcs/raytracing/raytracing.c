/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:22:46 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/03 18:52:06 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb		color_to_rgb(t_color old)
{
	t_rgb	new;

	new.red = old.red * 255;
	new.green = old.green * 255;
	new.blue = old.blue * 255;
	return (new);
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
