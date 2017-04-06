/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_cam_movement1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 22:30:26 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/06 16:58:21 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	gtk_camera_forward(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.origin.x += 1;
	raytracing(e);
}

void	gtk_camera_backward(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.origin.x -= 1;
	raytracing(e);
}

void	gtk_reset_cam(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.origin.x = 0;
	e->camera.origin.y = 0;
	e->camera.origin.z = 0;
	e->camera.rot.x = 0;
	e->camera.rot.y = 0;
	e->camera.rot.z = 0;
	raytracing(e);
}

void	movement_camera1(t_env *e)
{
	GtkWidget *forward;
	GtkWidget *backward;

	forward = gtk_button_new_with_mnemonic("_WForward");
	backward = gtk_button_new_with_mnemonic("_SBackward");
	g_signal_connect(forward, "clicked", G_CALLBACK(gtk_camera_forward), e);
	g_signal_connect(backward, "clicked", G_CALLBACK(gtk_camera_backward), e);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), forward, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), backward, FALSE, FALSE, 0);
}
