/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_cam_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 22:33:31 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/06 16:58:32 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	gtk_rot_camera_left(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.rot.y += 2.5;
	raytracing(e);
}

void	gtk_rot_camera_right(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.rot.y -= 2.5;
	raytracing(e);
}

void	gtk_rot_camera_up(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.rot.z += 2.5;
	raytracing(e);
}

void	gtk_rot_camera_down(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.rot.z -= 2.5;
	raytracing(e);
}

void	rot_camera(t_env *e)
{
	GtkWidget *left;
	GtkWidget *right;
	GtkWidget *up;
	GtkWidget *down;

	left = gtk_button_new_with_mnemonic("_JRot_l");
	right = gtk_button_new_with_mnemonic("_LRot_r");
	up = gtk_button_new_with_mnemonic("_IRot_up");
	down = gtk_button_new_with_mnemonic("_KRot_D");
	g_signal_connect(left, "clicked", G_CALLBACK(gtk_rot_camera_left), e);
	g_signal_connect(right, "clicked", G_CALLBACK(gtk_rot_camera_right), e);
	g_signal_connect(up, "clicked", G_CALLBACK(gtk_rot_camera_up), e);
	g_signal_connect(down, "clicked", G_CALLBACK(gtk_rot_camera_down), e);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), left, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), right, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), up, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), down, FALSE, FALSE, 0);
}
