/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:24:35 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 21:24:37 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void			ft_fill_info_face(t_face *face, t_e *e)
{
	t_vertex		*vertex;

	ft_putendl(e->split_face[0]);
	if (ft_strcmp(e->split_face[0], "vertex") == 0 && e->split_face[1] != NULL
		&& e->split_face[2] != NULL && e->split_face[3] != NULL)
	{
		vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
		vertex->coord.x = atof(e->split_face[1]);
		vertex->coord.y = atof(e->split_face[2]);
		vertex->coord.z = atof(e->split_face[3]);
		vertex->coord.w = 1;
		vertex->next = NULL;
		add_after_vertex(vertex, &face->vertex);
	}
	else if (ft_strcmp(e->split_face[0], "normal") == 0 && e->split_face[1]
		!= NULL && e->split[2] != NULL && e->split[3] != NULL)
	{
		face->normal.x = atof(e->split_face[1]);
		face->normal.y = atof(e->split_face[2]);
		face->normal.z = atof(e->split_face[3]);
		face->normal.w = 1;
	}
}

static void			ft_free_face(int k, t_e *e)
{
	int				j;

	j = -1;
	if (k == 0 && e->split_face[0])
	{
		while (e->split_face[++j])
			free(e->split_face[j]);
		if (e->split_face)
			free(e->split_face);
	}
}

t_face				*ft_parsing_face_after(t_e *e, int i, int k)
{
	t_face			*face;

	face = (t_face*)ft_memalloc(sizeof(t_face));
	face->vertex = NULL;
	face->next = NULL;
	i++;
	while (i < e->nbr_line && k != -2)
	{
		e->line = i;
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->split_face = ft_strsplit(e->file[i], '\t');
			if (e->split_face[0] && (ft_strcmp(e->split_face[0], "vertex") == 0
				|| ft_strcmp(e->split_face[0], "normal") == 0))
				ft_fill_info_face(face, e);
			else
				k = -2;
			if (k == 0 && e->split_face[0])
				ft_free_face(k, e);
		}
		i++;
	}
	e->faceend = i - 1;
	return (face);
}
