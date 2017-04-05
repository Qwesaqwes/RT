/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_modif_obj_limit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:46:44 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 16:06:41 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_modif_obj_limit1(t_gtk *gtk, t_obj *obj)
{
	if (obj->limit.exist.y_max == 0)
		gtk->e_ymax = gtk_entry_new_with_buffer(gtk_entry_buffer_new("x", 1));
	else
	{
		gtk->e_ymax = gtk_entry_new_with_buffer(
			gtk_entry_buffer_new(itof(obj->limit.y_max),
			ft_strlen(itof(obj->limit.y_max))));
	}
	if (obj->limit.exist.z_min == 0)
		gtk->e_zmin = gtk_entry_new_with_buffer(gtk_entry_buffer_new("x", 1));
	else
	{
		gtk->e_zmin = gtk_entry_new_with_buffer(
			gtk_entry_buffer_new(itof(obj->limit.z_min),
			ft_strlen(itof(obj->limit.z_min))));
	}
	if (obj->limit.exist.z_max == 0)
		gtk->e_zmax = gtk_entry_new_with_buffer(gtk_entry_buffer_new("x", 1));
	else
	{
		gtk->e_zmax = gtk_entry_new_with_buffer(
			gtk_entry_buffer_new(itof(obj->limit.z_max),
			ft_strlen(itof(obj->limit.z_max))));
	}
}

void	init_modif_obj_limit(t_gtk *gtk, t_obj *obj)
{
	if (obj->limit.exist.x_min == 0)
		gtk->e_xmin = gtk_entry_new_with_buffer(gtk_entry_buffer_new("x", 1));
	else
	{
		gtk->e_xmin = gtk_entry_new_with_buffer(
			gtk_entry_buffer_new(itof(obj->limit.x_min),
			ft_strlen(itof(obj->limit.x_min))));
	}
	if (obj->limit.exist.x_max == 0)
		gtk->e_xmax = gtk_entry_new_with_buffer(gtk_entry_buffer_new("x", 1));
	else
	{
		gtk->e_xmax = gtk_entry_new_with_buffer(
			gtk_entry_buffer_new(itof(obj->limit.x_max),
			ft_strlen(itof(obj->limit.x_max))));
	}
	if (obj->limit.exist.y_min == 0)
		gtk->e_ymin = gtk_entry_new_with_buffer(gtk_entry_buffer_new("x", 1));
	else
	{
		gtk->e_ymin = gtk_entry_new_with_buffer(
			gtk_entry_buffer_new(itof(obj->limit.y_min),
			ft_strlen(itof(obj->limit.y_min))));
	}
	init_modif_obj_limit1(gtk, obj);
}
