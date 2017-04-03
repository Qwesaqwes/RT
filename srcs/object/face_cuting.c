/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_cuting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:37:55 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/01 13:24:03 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_after_vertex(t_vertex *el, t_vertex **list)
{
	t_vertex	*tmp;

	tmp = *list;
	if (tmp == NULL)
		*list = el;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = el;
	}
}

void		add_after_face(t_face *el, t_face **list)
{
	t_face	*tmp;

	tmp = *list;
	if (tmp == NULL)
		*list = el;
	else
	{
		while (tmp != NULL && tmp->next)
			tmp = tmp->next;
		tmp->next = el;
	}
}

t_face		*new_triangle(t_vertex *v0, t_vertex *v1, t_vertex *v2,
			t_vec3d normal)
{
	t_face	*new;

	new = (t_face*)ft_memalloc(sizeof(t_face));
	new->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	new->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	new->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	new->vertex->next->next->next = NULL;
	new->vertex->coord = v0->coord;
	new->vertex->next->coord = v1->coord;
	new->vertex->next->next->coord = v2->coord;
	new->normal = normal;
	return (new);
}

t_face		*face_cuting2(t_face *old)
{
	t_face		*list;
	t_vertex	*tmp;

	list = NULL;
	tmp = old->vertex->next;
	if (!(tmp))
		return (NULL);
	while (tmp->next)
	{
		add_after_face(new_triangle(old->vertex, tmp, tmp->next, old->normal),
		&list);
		tmp = tmp->next;
	}
	return (list);
}

t_face		*face_cuting(t_face *old)
{
	t_face		*new;
	t_face		*tmp;

	new = NULL;
	tmp = old;
	while (tmp)
	{
		add_after_face(face_cuting2(tmp), &new);
		tmp = tmp->next;
	}
	return (new);
}
