/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 23:29:46 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 23:29:48 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		ft_free_scene(t_e *e)
{
	int			j;

	j = 0;
	if (e->split)
	{
		while (e->split[j] != NULL)
		{
			free(e->split[j]);
			j++;
		}
		free(e->split);
		e->split = NULL;
	}
}

t_list			*ft_parsing_obj(t_e *e)
{
	t_list		*list;
	t_obj		obj;

	e->ii = 0;
	list = NULL;
	e->id_o = -1;
	ft_free_scene(e);
	while (e->file[e->ii] && e->ii < e->nbr_line)
	{
		if (e->file[e->ii] && e->file[e->ii][0] != '#')
		{
			e->split = ft_strsplit(e->file[e->ii], '\t');
			if (e->split[0] && e->split[0][0] &&
				(ft_strcmp(e->split[0], "object")) == 0)
			{
				obj = ft_parsing_obj_after(e, e->ii);
				obj.id = e->id_o;
				ft_lstadd(&list, ft_lstnew(&obj, sizeof(t_obj)));
				e->ii = e->line - 1;
			}
			ft_free_scene(e);
		}
		e->ii++;
	}
	return (list);
}

void			ft_parsing_scene(t_env *rt, t_e *e)
{
	e->ii = 0;
	e->line = 0;
	e->split = NULL;
	e->nb_scene = 0;
	while (e->file[e->ii] && e->ii < e->nbr_line)
	{
		if (e->file[e->ii] && e->file[e->ii][0] != '#')
		{
			e->split = ft_strsplit(e->file[e->ii], '\t');
			if (e->split[0] && e->split[0][0]
				&& (ft_strcmp(e->split[0], "scene")) == 0 && e->nb_scene == 0)
			{
				e->nb_scene++;
				ft_parsing_scene_after(rt, e, e->ii);
				e->ii = e->line - 1;
			}
			else if (e->split[0] && e->split[0][0]
				&& (ft_strcmp(e->split[0], "scene")) == 0 && e->nb_scene == 1)
				ft_puterror(e, "Too much given scene");
			ft_free_scene(e);
		}
		e->ii++;
	}
}

void			ft_parsing_camera(t_env *rt, t_e *e)
{
	int			i;

	i = 0;
	e->line = 0;
	e->nb_camera = 0;
	ft_free_scene(e);
	while (e->file[i] && i < e->nbr_line)
	{
		if (e->file[i] && e->file[i][0] != '#')
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] && e->split[0][0]
				&& (ft_strcmp(e->split[0], "camera")) == 0 && e->nb_camera == 0)
				i = ft_parsing_camera_after(rt, e, i) - 1;
			else if (e->split[0] && e->split[0][0]
				&& (ft_strcmp(e->split[0], "camera")) == 0 && e->nb_camera == 1)
				ft_puterror(e, "Too much given camera");
			ft_free_scene(e);
		}
		i++;
	}
	if (e->nb_camera != 1)
		ft_puterror(e, "Too much given camera");
}

t_list			*ft_parsing_light(t_e *e)
{
	t_list		*list;
	t_obj		obj;

	e->ii = 0;
	e->split = NULL;
	e->id_l = -1;
	list = NULL;
	while (e->file[e->ii] && e->ii < e->nbr_line)
	{
		if (e->file[e->ii] && e->file[e->ii][0] != '#')
		{
			e->split = ft_strsplit(e->file[e->ii], '\t');
			if (e->split[0] && e->split[0][0] && (ft_strcmp(e->split[0],
				"light")) == 0)
			{
				obj = ft_parsing_lum(e, e->ii);
				obj.id = e->id_l;
				ft_lstadd(&list, ft_lstnew(&obj, sizeof(t_obj)));
				e->ii = e->line - 1;
			}
			ft_free_scene(e);
		}
		e->ii++;
	}
	return (list);
}
