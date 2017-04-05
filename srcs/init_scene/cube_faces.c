/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_faces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 22:31:23 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/05 22:36:53 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_face1(t_face *faces)
{
	faces->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->coord = (t_vec3d){ 15, 0, 3, 1 };
	faces->vertex->next->coord = (t_vec3d){ 15, -3, 0, 1 };
	faces->vertex->next->next->coord = (t_vec3d){ 15, -3, 3, 1 };
	faces->vertex->next->next->next = NULL;
	faces->normal = (t_vec3d){-1, 0, 0, 1};
	faces->n = (t_face*)ft_memalloc(sizeof(t_face));
	faces->n->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->coord = (t_vec3d){ 15, 0, 3, 1 };
	faces->n->vertex->next->coord = (t_vec3d){ 15, 0, 0, 1 };
	faces->n->vertex->next->next->coord = (t_vec3d){ 15, -3, 0, 1 };
	faces->n->vertex->next->next->next = NULL;
	faces->n->normal = (t_vec3d){-1, 0, 0, 1};
}

void	add_face2(t_face *faces)
{
	faces->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->coord = (t_vec3d){ 15, 0, 0, 1 };
	faces->vertex->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	faces->vertex->next->next->coord = (t_vec3d){ 18, 0, 0, 1 };
	faces->vertex->next->next->next = NULL;
	faces->normal = (t_vec3d){0, 1, 0, 1};
	faces->n = (t_face*)ft_memalloc(sizeof(t_face));
	faces->n->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->coord = (t_vec3d){ 15, 0, 0, 1 };
	faces->n->vertex->next->coord = (t_vec3d){ 15, 0, 3, 1 };
	faces->n->vertex->next->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	faces->n->vertex->next->next->next = NULL;
	faces->n->normal = (t_vec3d){0, 1, 0, 1};
}

void	add_face3(t_face *faces)
{
	faces->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->coord = (t_vec3d){ 15, 0, 0, 1 };
	faces->vertex->next->coord = (t_vec3d){ 18, 0, 0, 1 };
	faces->vertex->next->next->coord = (t_vec3d){ 15, -3, 0, 1 };
	faces->vertex->next->next->next = NULL;
	faces->normal = (t_vec3d){0, 0, -1, 1};
	faces->n = (t_face*)ft_memalloc(sizeof(t_face));
	faces->n->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->coord = (t_vec3d){ 15, -3, 0, 1 };
	faces->n->vertex->next->coord = (t_vec3d){ 18, 0, 0, 1 };
	faces->n->vertex->next->next->coord = (t_vec3d){ 18, -3, 0, 1 };
	faces->n->vertex->next->next->next = NULL;
	faces->n->normal = (t_vec3d){0, 0, -1, 1};
}

void	add_face4(t_face *faces)
{
	faces->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->coord = (t_vec3d){ 15, 0, 3, 1 };
	faces->vertex->next->coord = (t_vec3d){ 15, -3, 3, 1 };
	faces->vertex->next->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	faces->vertex->next->next->next = NULL;
	faces->normal = (t_vec3d){0, 0, 1, 1};
	faces->n = (t_face*)ft_memalloc(sizeof(t_face));
	faces->n->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->coord = (t_vec3d){ 15, -3, 3, 1 };
	faces->n->vertex->next->coord = (t_vec3d){ 18, -3, 3, 1 };
	faces->n->vertex->next->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	faces->n->vertex->next->next->next = NULL;
	faces->n->normal = (t_vec3d){0, 0, 1, 1};
}

void	add_face5(t_face *faces)
{
	faces->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->coord = (t_vec3d){ 18, 0, 0, 1 };
	faces->vertex->next->coord = (t_vec3d){ 18, -3, 3, 1 };
	faces->vertex->next->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	faces->vertex->next->next->next = NULL;
	faces->normal = (t_vec3d){1, 0, 0, 1};
	faces->n = (t_face*)ft_memalloc(sizeof(t_face));
	faces->n->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->coord = (t_vec3d){ 18, 0, 0, 1 };
	faces->n->vertex->next->coord = (t_vec3d){ 18, -3, 0, 1 };
	faces->n->vertex->next->next->coord = (t_vec3d){ 18, -3, 3, 1 };
	faces->n->vertex->next->next->next = NULL;
	faces->n->normal = (t_vec3d){1, 0, 0, 1};
}
