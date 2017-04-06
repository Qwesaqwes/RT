/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:04:07 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 21:05:44 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void			ft_verif_nbr_camera(t_e *e)
{
	if (e->vcamera.origin_xyz != 1)
		ft_puterror(e, "Wrong Info Camera - origin_xyz");
	if (e->vcamera.rotation_xyz != 1)
		ft_puterror(e, "Wrong Info Camera - rotation_xyz");
	if (e->vcamera.distance_viewplane != 1)
		ft_puterror(e, "Wrong Info Camera - distance_camera");
}

static void			ft_fill_info_brut(t_env *rt, t_e *e, int i)
{
	if (i == 1)
	{
		rt->camera.base_u.x = 1;
		rt->camera.base_u.y = 0;
		rt->camera.base_u.z = 0;
		rt->camera.base_u.w = 1;
		rt->camera.base_v.x = 0;
		rt->camera.base_v.y = 1;
		rt->camera.base_v.z = 0;
		rt->camera.base_v.w = 1;
		rt->camera.base_w.x = 0;
		rt->camera.base_w.y = 0;
		rt->camera.base_w.z = 1;
		rt->camera.base_w.w = 1;
		rt->camera.origin.z = 1;
		rt->camera.rot.w = 1;
	}
	else if (i == 2)
	{
		e->vcamera.origin_xyz = 0;
		e->vcamera.rotation_xyz = 0;
		e->vcamera.distance_viewplane = 0;
	}
}

static void			ft_free_parse(t_e *e)
{
	int				j;

	j = -1;
	while (e->split && e->split[++j] != NULL)
		free(e->split[j]);
	if (e->split)
		free(e->split);
	e->split = NULL;
}

static void			ft_norme(t_e *e, t_env *rt)
{
	e->verifc = 0;
	ft_fill_info_brut(rt, e, 1);
	ft_fill_info_brut(rt, e, 2);
	ft_free_parse(e);
}

int					ft_parsing_camera_after(t_env *rt, t_e *e, int i)
{
	i++;
	e->nb_camera++;
	ft_norme(e, rt);
	while (i < e->nbr_line && i != -1 && e->verifc == 0)
	{
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			if (e->split)
				ft_free_parse(e);
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) == 0)
				ft_fill_info_camera(rt, e);
			else if (ft_verif_scene_object(e->split[0]) == 1)
			{
				e->verifc++;
				i = i - 2;
			}
		}
		if (e->split)
			ft_free_parse(e);
		i++;
	}
	ft_verif_nbr_camera(e);
	return (i);
}
