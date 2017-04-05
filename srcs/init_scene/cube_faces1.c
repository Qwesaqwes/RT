/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_faces1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 22:33:00 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/05 22:35:56 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_face6(t_face *faces)
{
	faces->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->vertex->coord = (t_vec3d){ 15, -3, 0, 1 };
	faces->vertex->next->coord = (t_vec3d){ 18, -3, 0, 1 };
	faces->vertex->next->next->coord = (t_vec3d){ 15, -3, 3, 1 };
	faces->vertex->next->next->next = NULL;
	faces->normal = (t_vec3d){0, -1, 0, 1};
	faces->n = (t_face*)ft_memalloc(sizeof(t_face));
	faces->n->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	faces->n->vertex->coord = (t_vec3d){ 15, -3, 3, 1 };
	faces->n->vertex->next->coord = (t_vec3d){ 18, -3, 0, 1 };
	faces->n->vertex->next->next->coord = (t_vec3d){ 18, -3, 3, 1 };
	faces->n->vertex->next->next->next = NULL;
	faces->n->normal = (t_vec3d){0, -1, 0, 1};
	faces->n->n = NULL;
}
