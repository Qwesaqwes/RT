/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_set_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:06:16 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/24 15:53:47 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	top_box(t_env *e)
{
	GtkWidget *image;

	e->gtk.vbox = gtk_box_new(0, 0);
	e->gtk.zoom = gtk_button_new();
	e->gtk.dezoom = gtk_button_new();
	e->gtk.save = gtk_button_new();
	image = gtk_image_new_from_file("./images/zoom1.png");
	gtk_button_set_image(GTK_BUTTON(e->gtk.zoom), image);
	image = gtk_image_new_from_file("./images/unzoom.png");
	gtk_button_set_image(GTK_BUTTON(e->gtk.dezoom), image);
	image = gtk_image_new_from_file("./images/save.png");
	gtk_button_set_image(GTK_BUTTON(e->gtk.save), image);
	// g_signal_connect(e->gtk.save, "clicked", G_CALLBACK(gtk_s_img),
	// e->gtk.buffer);
	g_signal_connect(e->gtk.zoom, "clicked", G_CALLBACK(gtk_zoom), e);
	g_signal_connect(e->gtk.dezoom, "clicked", G_CALLBACK(gtk_dezoom), e);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), e->gtk.zoom, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), e->gtk.dezoom, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(e->gtk.vbox), e->gtk.save, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.globalbox), e->gtk.vbox, 0, 0, 0);
}

void 	add_view_box(t_env *e)
{
	e->gtk.view_obj = gtk_button_new_with_label("View of Objects");
	g_signal_connect(e->gtk.view_obj, "clicked", G_CALLBACK(gtk_view_obj), e);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.view_obj,
	FALSE, FALSE, 0);
}

void 	choose_file(t_env *e)
{
	e->gtk.choose_f = gtk_button_new_with_label("Change Scene");
	g_signal_connect(e->gtk.choose_f, "clicked", G_CALLBACK(gtk_choose_f), e);
	gtk_box_pack_end(GTK_BOX(e->gtk.stopbox), e->gtk.choose_f, FALSE, FALSE, 0);
}

void 	init_combo_box_effect(GtkWidget *n_effect)
{
	char	*effec[] = {"None", "Sepia", "GreyScale", "Sobel", "Cartoon",
	"Motion Blur", "Motion Blur 2", "Stereoscopie"};
	int		nb;

	nb = 0;
	while (nb < 8)
	{
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(n_effect), effec[nb]);
		nb++;
	}
}

void 	init_combo_box_anti(GtkWidget *n_antial)
{
	char	*anti[] = {"None", "2x AA", "4x AA", "8x AA", "16x AA"};
	int		nb;

	nb = 0;
	while (nb < 5)
	{
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(n_antial), anti[nb]);
		nb++;
	}
}

void 	sec_top_box(t_env *e)
{
	e->gtk.stopbox = gtk_box_new(0, 0);
	e->gtk.effect = gtk_label_new("Effect:");
	e->gtk.n_effect = gtk_combo_box_text_new();
	e->gtk.antial = gtk_label_new("Antialiasing:");
	e->gtk.n_antial = gtk_combo_box_text_new();
	init_combo_box_effect(e->gtk.n_effect);
	init_combo_box_anti(e->gtk.n_antial);
	g_signal_connect(e->gtk.n_effect, "changed", G_CALLBACK(gtk_effect), e);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.effect, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.n_effect,
	FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.antial, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.n_antial,
	FALSE, FALSE, 0);
	add_view_box(e);
	choose_file(e);
	gtk_box_pack_start(GTK_BOX(e->gtk.globalbox), e->gtk.stopbox, 0, 0, 0);
}

void 	init_gtk(t_env *e)
{
	e->gtk.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(e->gtk.window), W, H + 100);
	gtk_window_set_position(GTK_WINDOW(e->gtk.window), GTK_WIN_POS_CENTER);
	e->gtk.buffer = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, W, H);
	e->gtk.layout = gtk_layout_new(NULL, NULL);
	e->gtk.back_img = gtk_image_new_from_file("./images/images.jpg");
	gtk_layout_put(GTK_LAYOUT(e->gtk.layout), e->gtk.back_img, 0, 0);
	e->gtk.globalbox = gtk_box_new(1, 0);
	e->gtk.imgbox = gtk_box_new(0, 0);
	e->gtk.label1 = gtk_label_new("TITLE OF FILE");
	gtk_box_pack_start(GTK_BOX(e->gtk.globalbox), e->gtk.label1, 0, 0, 10);
	top_box(e);
	sec_top_box(e);
	e->gtk.img = gtk_image_new_from_pixbuf(e->gtk.buffer);
	gtk_box_pack_start(GTK_BOX(e->gtk.imgbox), e->gtk.img, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.globalbox), e->gtk.imgbox, 0, 0, 0);
	g_signal_connect(e->gtk.window, "delete-event", G_CALLBACK(gtk_main_quit),
	NULL);
	gtk_layout_put(GTK_LAYOUT(e->gtk.layout), e->gtk.globalbox, 0, 0);
	gtk_container_add(GTK_CONTAINER(e->gtk.window), e->gtk.layout);
	gtk_widget_show_all(e->gtk.window);
}
