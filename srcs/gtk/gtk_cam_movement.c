/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_cam_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:25:36 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/05 21:36:27 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	gtk_camera_left(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.origin.z -= 1;
	printf("z: %f\n", e->camera.origin.z);
	raytracing(e);
}

void	gtk_camera_right(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.origin.z += 1;
	printf("z: %f\n", e->camera.origin.z);
	raytracing(e);
}

void	gtk_camera_up(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.origin.y += 1;
	printf("y: %f\n", e->camera.origin.y);
	raytracing(e);
}

void	gtk_camera_down(GtkWidget *button, t_env *e)
{
	(void)button;
	e->camera.origin.y -= 1;
	printf("y: %f\n", e->camera.origin.y);
	raytracing(e);
}

void	movement_camera(t_env *e)
{
	GtkWidget *left;
	GtkWidget *right;
	GtkWidget *up;
	GtkWidget *down;

	left = gtk_button_new_with_mnemonic("_ALeft");
	right = gtk_button_new_with_mnemonic("_DRight");
	up = gtk_button_new_with_mnemonic("_ Up");
	down = gtk_button_new_with_mnemonic("_ZDown");
	g_signal_connect(left, "clicked", G_CALLBACK(gtk_camera_left), e);
	g_signal_connect(right, "clicked", G_CALLBACK(gtk_camera_right), e);
	g_signal_connect(up, "clicked", G_CALLBACK(gtk_camera_up), e);
	g_signal_connect(down, "clicked", G_CALLBACK(gtk_camera_down), e);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), left, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), right, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), up, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), down, FALSE, FALSE, 0);
	movement_camera1(e);
}
