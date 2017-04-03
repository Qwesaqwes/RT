/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <dsusheno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:21:40 by dsusheno          #+#    #+#             */
/*   Updated: 2017/04/02 20:30:50 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_vertex(t_vertex **vertex)
{
	t_vertex	*copy;
	t_vertex	*nextlist;

	copy = *vertex;
	while (copy)
	{
		nextlist = copy->next;
		free(copy);
		copy = nextlist;
	}
	*vertex = NULL;
}

void	free_face(t_face **face)
{
	t_face	*copy;
	t_face	*nextlist;

	copy = *face;
	while (copy)
	{
		nextlist = copy->next;
		free_vertex(&(*face)->vertex);
		free(copy);
		copy = nextlist;
	}
	*face = NULL;
}

void	ft_free_obj2(t_obj *obj)
{
	if (obj->type == 5 || obj->type == 6)
	{
		free_face(&obj->faces);
	}
	free(obj);
}

void	ft_free_obj(void *obj, size_t size)
{
	ft_free_obj2((t_obj *)obj);
	(void)size;
}

void	ft_free_float(void *content, size_t size)
{
	free(content);
	(void)size;
}
