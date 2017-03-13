/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_set_box2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:57:51 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 15:58:33 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_view_box(t_env *e)
{
	e->gtk.view_obj = gtk_button_new_with_label("View of Objects");
	g_signal_connect(e->gtk.view_obj, "clicked", G_CALLBACK(gtk_view_obj), e);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.view_obj,
	FALSE, FALSE, 0);
}

void	choose_file(t_env *e)
{
	e->gtk.choose_f = gtk_button_new_with_label("Change Scene");
	g_signal_connect(e->gtk.choose_f, "clicked", G_CALLBACK(gtk_choose_f), e);
	gtk_box_pack_end(GTK_BOX(e->gtk.stopbox), e->gtk.choose_f, FALSE, FALSE, 0);
}
