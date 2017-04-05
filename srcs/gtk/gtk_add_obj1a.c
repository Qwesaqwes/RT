/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj1a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 17:26:39 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 17:27:18 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_add_obj_l_e4(t_gtk *gtk)
{
	gtk->l_limit = gtk_label_new("Limite -->");
	gtk->l_xmin = gtk_label_new("Xmin: ");
	gtk->l_xmax = gtk_label_new("Xmax: ");
	gtk->l_ymin = gtk_label_new("Ymin: ");
	gtk->l_ymax = gtk_label_new("Ymax: ");
	gtk->l_zmin = gtk_label_new("Zmin: ");
	gtk->l_zmax = gtk_label_new("Zmax: ");
	gtk->e_xmin = gtk_entry_new();
	gtk->e_xmax = gtk_entry_new();
	gtk->e_ymin = gtk_entry_new();
	gtk->e_ymax = gtk_entry_new();
	gtk->e_zmin = gtk_entry_new();
	gtk->e_zmax = gtk_entry_new();
	gtk->l_info_limit = gtk_label_new("Put 'x' for no limit");
}
