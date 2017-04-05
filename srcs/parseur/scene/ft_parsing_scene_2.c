/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_scene_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 23:16:44 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 23:16:45 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void				ft_next_fill_scene_3(t_scene *scene, t_e *e)
{
	if (ft_strcmp(e->split[0], "refr_index") == 0 && e->split[1] != NULL)
	{
		e->vscene.refr_index++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in scene - refr_index");
		scene->refr_index = (e->tmp);
	}
	else
		ft_puterror(e, "Wrong Info Scene");
}

static void				ft_next_fill_scene_2(t_scene *scene, t_e *e)
{
	if (ft_strcmp(e->split[0], "background_rgb") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vscene.background_rgb++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in scene - background_red");
		scene->background.red = (e->tmp);
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in scene - background_green");
		scene->background.green = (e->tmp);
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in scene - background_blue");
		scene->background.blue = (e->tmp);
	}
	else
		ft_next_fill_scene_3(scene, e);
}

static void				ft_next_fill_scene_1(t_scene *scene, t_e *e)
{
	if (ft_strcmp(e->split[0], "ambiant_rgb") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vscene.ambiant_rgb++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in scene - ambiant red");
		scene->ambiant.red = (e->tmp);
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in scene - ambiant green");
		scene->ambiant.green = (e->tmp);
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in scene - ambiant blue");
		scene->ambiant.blue = (e->tmp);
	}
	else
		ft_next_fill_scene_2(scene, e);
}

void					ft_fill_info_scene(t_scene *scene, t_e *e)
{
	if (ft_strcmp(e->split[0], "refr_index") == 0 && e->split[1] != NULL)
	{
		e->vscene.refr_index++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in scene - refr_index");
		scene->refr_index = (e->tmp);
	}
	else if (ft_strcmp(e->split[0], "antialiasing") == 0 && e->split[1] != NULL)
	{
		e->vscene.antialiasing++;
		e->tmp = atoi(e->split[1]);
		if (e->tmp < 1 || e->tmp > 4)
			ft_puterror(e, "Wrong Info in scene - antialiasing");
		scene->antialiasing = (e->tmp);
	}
	else
		ft_next_fill_scene_1(scene, e);
}
