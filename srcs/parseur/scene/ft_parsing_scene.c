/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 23:16:35 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 23:16:36 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void			ft_verif_scene(t_e *e)
{
	e->split = NULL;
	e->vscene.ambiant_rgb = 0;
	e->vscene.refr_index = 0;
	e->vscene.background_rgb = 0;
	e->vscene.antialiasing = 0;
}

static void			ft_verif_nbr_scene(t_e *e)
{
	if (e->vscene.ambiant_rgb != 1)
		ft_puterror(e, "Wrong Info Scene ambiant_rgb");
	if (e->vscene.refr_index != 1)
		ft_puterror(e, "Wrong Info Scene refr_index");
	if (e->vscene.background_rgb != 1)
		ft_puterror(e, "Wrong Info Scene background_rgb");
	if (e->vscene.antialiasing != 1)
		ft_puterror(e, "Wrong Info Scene antialiasing");
}

static void			ft_free_scene(t_e *e)
{
	int				j;

	j = -1;
	while (e->split[++j])
		free(e->split[j]);
	free(e->split);
}

void				ft_parsing_scene_after(t_env *rt, t_e *e, int i)
{
	e->verif = 0;
	i++;
	ft_verif_scene(e);
	while (i < e->nbr_line && i != -1 && e->verif == 0)
	{
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) == 0)
			{
				ft_fill_info_scene(&rt->scene, e);
				ft_free_scene(e);
			}
			else if (ft_verif_scene_object(e->split[0]) == 1)
			{
				e->verif++;
				i = i - 2;
			}
		}
		i++;
	}
	e->line = i;
	ft_verif_nbr_scene(e);
}
