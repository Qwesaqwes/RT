/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <dsusheno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:21:40 by dsusheno          #+#    #+#             */
/*   Updated: 2017/04/01 15:37:26 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_vertex(t_vertex **vertex)
{
	t_vertex	*copy;
	t_vertex	*nextlist;

	printf("3\n");
	copy = *vertex;
	printf("4\n");
	while (copy)
	{
		nextlist = copy->next;
		free(copy);
		copy = nextlist;
	}
	printf("5\n");

	*vertex = NULL;
	//verif init NULL
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
		printf("1\n");
		free_face(&obj->faces);
		printf("2\n");

	}
	free(obj);
}

void	ft_free_obj(void  *obj, size_t size)
{
	ft_free_obj2((t_obj *)obj);
	(void)size;
}

void	ft_free_float(void *content, size_t size)
{
	free(content);
	(void)size;
}
