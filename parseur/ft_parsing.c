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

#include "../includes/parsing.h"

t_list			*ft_parsing_obj(t_e *e)
{
	t_list		*list;
	t_obj		obj;

	e->ii = 0;
	list = NULL;
	e->split = NULL;
	e->id_o = -1;
	while (e->file[e->ii] && e->ii < e->nbr_line)
	{
		if (e->file[e->ii] && e->file[e->ii][0] != '#')
		{
			e->split = ft_strsplit(e->file[e->ii], '\t');
			if (e->split[0] && e->split[0][0] &&
				(ft_strcmp(e->split[0], "object")) == 0)
			{
				e->id_o++;
				obj = ft_parsing_obj_after(e, e->ii);
				obj.id = e->id_o;
				ft_lstadd(&list, ft_lstnew(&obj, sizeof(t_obj)));
				e->ii = e->line - 1;
			}
		}
		e->ii++;
	}
	return (list);
}

void			ft_parsing_scene(t_env *rt, t_e *p)
{
	p->ii = 0;
	p->line = 0;
	p->split = NULL;
	p->nb_scene = 0;
	while (p->file[p->ii] && p->ii < p->nbr_line)
	{
		if (p->file[p->ii] && p->file[p->ii][0] != '#')
		{
			p->split = ft_strsplit(p->file[p->ii], '\t');
			if (p->split[0] && p->split[0][0]
				&& (ft_strcmp(p->split[0], "scene")) == 0 && p->nb_scene == 0)
			{
				p->nb_scene++;
				ft_parsing_scene_after(rt, p, p->ii);
				p->ii = p->line - 1;
			}
			else if (p->split[0] && p->split[0][0]
				&& (ft_strcmp(p->split[0], "scene")) == 0 && p->nb_scene == 1)
				ft_puterror(p, "Too much given scene");
		}
		p->ii++;
	}
}

void			ft_parsing_camera(t_env *rt, t_e *e)
{
	int			i;

	i = 0;
	e->line = 0;
	e->split = NULL;
	e->nb_camera = 0;
	while (e->file[i] && i < e->nbr_line)
	{
		if (e->file[i] && e->file[i][0] != '#')
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] && e->split[0][0]
				&& (ft_strcmp(e->split[0], "camera")) == 0 && e->nb_camera == 0)
			{
				e->nb_camera++;
				i = ft_parsing_camera_after(rt, e, i) - 1;
			}
			else if (e->split[0] && e->split[0][0]
				&& (ft_strcmp(e->split[0], "camera")) == 0 && e->nb_camera == 1)
				ft_puterror(e, "Too much given camera");
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
			if (e->split[0] && e->split[0][0] &&
				(ft_strcmp(e->split[0], "light")) == 0)
			{
				e->id_l++;
				obj = ft_parsing_lum(e, e->ii);
				obj.id = e->id_l;
				ft_lstadd(&list, ft_lstnew(&obj, sizeof(t_obj)));
				e->ii = e->line - 1;
			}
		}
		e->ii++;
	}
	return (list);
}
