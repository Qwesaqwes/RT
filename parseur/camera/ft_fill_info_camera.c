/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:12:00 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 21:12:03 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static void			ft_fill_info_camera_next(t_env *rt, t_e *e)
{
	if (ft_strcmp(e->split[0], "rotation_xyz") == 0 && e->split[1] != NULL \
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		if (e->split[4] != NULL)
			ft_puterror(e, "Wrong Info in Camera - rotation_xyz");
		e->vcamera.rotation_xyz++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Camera - rotation_x");
		rt->camera.rot.x = (e->tmp);
		e->tmp = atof(e->split[2]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Camera - rotation_y");
		rt->camera.rot.y = (e->tmp);
		e->tmp = atof(e->split[3]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Camera - rotation_z");
		rt->camera.rot.z = (e->tmp);
	}
	else
		ft_puterror(e, ft_strjoin("Wrong Info Object line ",
			ft_itoa(e->save_i + 1)));
}

void				ft_fill_info_camera(t_env *rt, t_e *e)
{
	if (ft_strcmp(e->split[0], "origin_xyz") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vcamera.origin_xyz++;
		e->tmp = atof(e->split[1]);
		rt->camera.origin.x = (e->tmp);
		e->tmp = atof(e->split[2]);
		rt->camera.origin.y = (e->tmp);
		e->tmp = atof(e->split[3]);
		rt->camera.origin.z = (e->tmp);
	}
	else if (ft_strcmp(e->split[0], "distance_viewplane") == 0
		&& e->split[1] != NULL)
	{
		e->vcamera.distance_viewplane++;
		e->tmp = atof(e->split[1]);
		if (e->tmp <= 0)
			ft_puterror(e, "Wrong Info in Camera - distance_viewplane");
		rt->vp.dist = (e->tmp);
		rt->vp.width = 1;
		rt->vp.height = (float)H / (float)W;
	}
	else
		ft_fill_info_camera_next(rt, e);
}
