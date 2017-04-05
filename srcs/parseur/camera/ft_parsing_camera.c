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

static void			ft_verif_camera(t_e *e)
{
	e->vcamera.origin_xyz = 0;
	e->vcamera.rotation_xyz = 0;
	e->vcamera.distance_viewplane = 0;
}

static void			ft_verif_nbr_camera(t_e *e)
{
	if (e->vcamera.origin_xyz != 1)
		ft_puterror(e, "Wrong Info Camera - origin_xyz");
	if (e->vcamera.rotation_xyz != 1)
		ft_puterror(e, "Wrong Info Camera - rotation_xyz");
	if (e->vcamera.distance_viewplane != 1)
		ft_puterror(e, "Wrong Info Camera - distance_camera");
}

static void			ft_fill_info_brut(t_env *rt)
{
	rt->camera.baseU.x = 1;
	rt->camera.baseU.y = 0;
	rt->camera.baseU.z = 0;
	rt->camera.baseU.w = 1;
	rt->camera.baseV.x = 0;
	rt->camera.baseV.y = 1;
	rt->camera.baseV.z = 0;
	rt->camera.baseV.w = 1;
	rt->camera.baseW.x = 0;
	rt->camera.baseW.y = 0;
	rt->camera.baseW.z = 1;
	rt->camera.baseW.w = 1;
	rt->camera.origin.z = 1;
	rt->camera.rot.w = 1;
}

static void			ft_free_parse(t_e *e)
{
	int				j;

	j = -1;
	while (e->split[++j])
		free(e->split[j]);
	free(e->split);
}

int					ft_parsing_camera_after(t_env *rt, t_e *e, int i)
{
	int				verif;

	verif = 0;
	i++;
	ft_verif_camera(e);
	ft_fill_info_brut(rt);
	e->split = NULL;
	while (i < e->nbr_line && i != -1 && verif == 0)
	{
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) == 0)
				ft_fill_info_camera(rt, e);
			else if (ft_verif_scene_object(e->split[0]) == 1)
			{
				verif++;
				i = i - 2;
			}
			ft_free_parse(e);
		}
		i++;
	}
	ft_verif_nbr_camera(e);
	return (i);
}
