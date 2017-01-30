/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:03 by jichen-m          #+#    #+#             */
/*   Updated: 2017/01/30 18:39:05 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	reset_img(t_gtk *gtk)
{
	gtk->img = gtk_image_new_from_pixbuf(gtk->buffer);
	gtk_box_pack_start(GTK_BOX(gtk->imgbox), gtk->img, 0, 0, 0);
	gtk_widget_show_all(gtk->window);
}
/* Function to Save img when click*/
void 	gtk_s_img(GtkWidget	*button, gpointer buffer)
{
	GError	*err;

	(void)button;
	err = NULL;
	gdk_pixbuf_save(buffer, "RT_img", "jpeg", &err, "quality", "100", NULL);
}

/* Function to zoom when click in the button*/
void 	gtk_zoom(GtkWidget *button, t_env *e)
{
	(void)button;
	gtk_widget_destroy(e->gtk.img);
	e->vp.dist += 0.5;
	raytracing(e);
	reset_img(&e->gtk);
}

/* Function to dezoom when click in the button*/
void 	gtk_dezoom(GtkWidget *button, t_env *e)
{
	(void)button;
	gtk_widget_destroy(e->gtk.img);
	e->vp.dist -= 0.5;
	if (e->vp.dist <= 0)
	{
		e->vp.dist = 0.5;
		g_print("No more Dezoom available\n");
	}
	raytracing(e);
	reset_img(&e->gtk);
}


void 	top_box(t_env *e)
{
	/*Creation of "TOP_BOX"*/
	e->gtk.vbox = gtk_box_new(0, 0);

	/*Creation of buttons*/
	e->gtk.zoom = gtk_button_new_with_label("ZOOM");
	e->gtk.dezoom = gtk_button_new_with_label("DEZOOM");
	e->gtk.save = gtk_button_new_with_label("SAVE");

	/*signal to call function 'gtk_s_img' when Click on the button "SAVE" */
	g_signal_connect(e->gtk.save, "clicked", G_CALLBACK(gtk_s_img), e->gtk.buffer);

	/*signal to call function 'gtk_zoom' when click on the button "ZOOM"*/
	g_signal_connect(e->gtk.zoom, "clicked", G_CALLBACK(gtk_zoom), e);
	g_signal_connect(e->gtk.dezoom, "clicked", G_CALLBACK(gtk_dezoom), e);

	/*Put buttons inside the "TOP_BOX"*/
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), e->gtk.zoom, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.vbox), e->gtk.dezoom, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(e->gtk.vbox), e->gtk.save, FALSE, FALSE, 0);

	/*put the "TOP_BOX" inside the "GLOBAL_BOX" */
	gtk_box_pack_start(GTK_BOX(e->gtk.globalbox), e->gtk.vbox, 0, 0, 0);
}

void 	init_add_obj_l_e2(t_gtk *gtk)
{
	gtk->l_x = gtk_label_new("x: ");
	gtk->l_x1 = gtk_label_new("x: ");
	gtk->l_x2 = gtk_label_new("x: ");
	gtk->l_y = gtk_label_new("y: ");
	gtk->l_y1 = gtk_label_new("y: ");
	gtk->l_y2 = gtk_label_new("y: ");
	gtk->l_z = gtk_label_new("z: ");
	gtk->l_z1 = gtk_label_new("z: ");
	gtk->l_z2 = gtk_label_new("z: ");
	gtk->e_nobj = gtk_entry_new();
	gtk->e_posx = gtk_entry_new();
	gtk->e_posy = gtk_entry_new();
	gtk->e_posz = gtk_entry_new();
	gtk->e_scalex = gtk_entry_new();
	gtk->e_scaley = gtk_entry_new();
	gtk->e_scalez = gtk_entry_new();
	gtk->e_rotx = gtk_entry_new();
	gtk->e_roty = gtk_entry_new();
	gtk->e_rotz = gtk_entry_new();
	gtk->e_shine = gtk_entry_new();
	gtk->c_obj = gtk_combo_box_text_new();
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gtk->c_obj), "0", "Sphere");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gtk->c_obj), "1", "Cone");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gtk->c_obj), "2", "Cylindre");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gtk->c_obj), "3", "Plan");
}

// int draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data)
// {
// 	guint width, height;
// 	GtkStyleContext *context;
// 	cairo_surface_t	*img;
//
// 	data = NULL;
// 	img = cairo_image_surface_create_from_png("./color.png");
// 	cairo_save(cr);
// 	context = gtk_widget_get_style_context (widget);
// 	// width = cairo_image_surface_get_width (img);
// 	// height = cairo_image_surface_get_height (img);
// 	cairo_scale(cr, 0.4, 0.4);
// 	width = gtk_widget_get_allocated_width (widget);
// 	height = gtk_widget_get_allocated_height (widget);
// 	// printf("width:%d\nheight:%d\n", width, height);
// 	gtk_render_background (context, cr, 15, 15, width, height);
// 	cairo_set_source_surface(cr, img, 10, 10);
// 	cairo_paint(cr);
// 	cairo_restore(cr);
// 	return FALSE;
// }


void 	init_add_obj_l_e(t_gtk *gtk)
{
	// GdkRGBA *color;

	// color = NULL;
	gtk->l_obj = gtk_label_new("Type of Object -->");
	gtk->l_nobj = gtk_label_new("Name of Object -->");
	gtk->l_pos = gtk_label_new("Position of Object -->");
	gtk->l_scale = gtk_label_new("Scale of Object -->");
	gtk->l_rot = gtk_label_new("Rotation of Object -->");
	gtk->l_color = gtk_label_new("Color of Object -->");
	gtk->l_shine = gtk_label_new("Shininess of Obeject -->");
	gtk->l_reflex = gtk_label_new("Reflexion of Object -->");
	gtk->e_reflex = gtk_entry_new();
	init_add_obj_l_e2(gtk);
	// gtk->e_color = gtk_drawing_area_new();
	// gtk_widget_set_size_request (gtk->e_color, 210, 210);
	gtk->e_color = gtk_color_button_new();
	// g_signal_connect(gtk->e_color, "clicked", G_CALLBACK (get_color), gtk);
	// gtk_color_button_set_title(GTK_COLOR_BUTTON(gtk->e_color), "Choose Color Here >..<");
	// gtk_color_button_get_rgba(GTK_COLOR_CHOOSER(gtk->e_color));
	// printf("red:%f\ngreen:%f\nblue:%f\n", color->red, color->green, color->blue);
}

void 	init_add_obj_box(t_gtk *gtk)
{
	gtk->obj_box = gtk_box_new(0, 0);
	gtk->obj_box2 = gtk_box_new(0, 0);
	gtk->obj_box3 = gtk_box_new(0, 0);
	gtk->obj_box4 = gtk_box_new(0, 0);
	gtk->obj_box5 = gtk_box_new(0, 0);
	gtk->obj_box6 = gtk_box_new(0, 0);
	gtk->obj_box7 = gtk_box_new(0, 0);
	gtk->obj_box8 = gtk_box_new(0, 0);
	gtk->obj_gbox = gtk_box_new(1, 0);
}

void 	put_label_inside_box2(t_gtk *gtk)
{
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->l_rot, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->l_x2, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->e_rotx, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->l_y2, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->e_roty, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->l_z2, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->e_rotz, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box6), gtk->l_color, 0, 0, 10);

	gtk_box_pack_start(GTK_BOX(gtk->obj_box6), gtk->e_color, 0, 0, 30);

	gtk_box_pack_start(GTK_BOX(gtk->obj_box7), gtk->l_shine, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box7), gtk->e_shine, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box8), gtk->l_reflex, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box8), gtk->e_reflex, 0, 0, 0);
}

void 	put_label_inside_box(t_gtk *gtk)
{
	gtk_box_pack_start(GTK_BOX(gtk->obj_box), gtk->l_obj, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box), gtk->c_obj, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box2), gtk->l_nobj, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box2), gtk->e_nobj, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->l_pos, 0, 0, 11);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->l_x, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->e_posx, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->l_y, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->e_posy, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->l_z, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->e_posz, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->l_scale, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->l_x1, 0, 0, 17);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->e_scalex, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->l_y1, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->e_scaley, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->l_z1, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->e_scalez, 0, 0, 0);
	put_label_inside_box2(gtk);
}

void 	put_box_inside_gbox(t_gtk	*gtk)
{
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box2, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box3, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box4, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box5, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box6, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box7, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box8, 0, 0, 0);
}

void 	gtk_add_obj(GtkWidget *button, t_env *e)
{
	GtkWidget	*dialog;
	GtkWidget	*area;
	gint 		response;

	(void)button;
	init_add_obj_l_e(&e->gtk);
	init_add_obj_box(&e->gtk);
	dialog = gtk_dialog_new_with_buttons("Add Object", GTK_WINDOW(e->gtk.window),
	GTK_DIALOG_MODAL, ("CANCEL"), GTK_RESPONSE_REJECT, ("OK"), GTK_RESPONSE_ACCEPT, NULL);
	area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

	/*put label and entry in Global_BOX*/
	put_label_inside_box(&e->gtk);
	put_box_inside_gbox(&e->gtk);
	gtk_container_add(GTK_CONTAINER(area), e->gtk.obj_gbox);

	gtk_widget_show_all(dialog);
	response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_ACCEPT)
	{
		g_print("the OK was pressed\n");
	}
	else
		g_print("the CANCEL was pressed\n");
	gtk_widget_destroy(dialog);
}


void 	add_obj_box(t_env *e)
{
	/*Creation of button "Add Object"*/
	e->gtk.object = gtk_button_new_with_label("Add Object");

	/*signal to call function 'gtk_add_obj' when Click in the button "Add Object"*/
	g_signal_connect(e->gtk.object, "clicked", G_CALLBACK(gtk_add_obj), e);

	/*put button inside the box "second top box"*/
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.object, FALSE, FALSE, 0);
}


void 	sec_top_box(t_env *e)
{
	/*Creation of "Second top box"(stopbox)*/
	e->gtk.stopbox = gtk_box_new(0, 0);

	/*Creation of Combo_box of "Effect" & "Antialiasing"*/
	e->gtk.effect = gtk_label_new("Effect:");
	e->gtk.n_effect = gtk_combo_box_text_new();
	e->gtk.antial = gtk_label_new("Antialiasing:");
	e->gtk.n_antial = gtk_combo_box_text_new();

	/*Puting Options inside the Combo_box of "Effect"*/
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(e->gtk.n_effect), "0", "None");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(e->gtk.n_effect), "1", "Sepia");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(e->gtk.n_effect), "2", "Cartoon");

	/*......................................."Antialiasing"*/
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(e->gtk.n_antial), "0", "None");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(e->gtk.n_antial), "1", "2x AA");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(e->gtk.n_antial), "2", "4x AA");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(e->gtk.n_antial), "3", "8x AA");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(e->gtk.n_antial), "4", "16x AA");

	/*Put "Second top box" inside "Global box"*/
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.effect, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.n_effect, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.antial, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.n_antial, FALSE, FALSE, 0);
	add_obj_box(e);
	gtk_box_pack_start(GTK_BOX(e->gtk.globalbox), e->gtk.stopbox, 0, 0, 0);
}

void 	init_gtk(t_env *e)
{
	/*Creation of WINDOW, BUFFER, IMG, TITLE OF FILE, GLOBAL_BOX, IMG_BOX*/
	e->gtk.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(e->gtk.window), GTK_WIN_POS_CENTER);
	e->gtk.buffer = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, W, H);
	// e->gtk.back_img = gtk_image_new_from_file("~/Desktop/light.jpg");
	e->gtk.globalbox = gtk_box_new(1, 0);
	e->gtk.imgbox = gtk_box_new(0, 0);
	e->gtk.label1 = gtk_label_new("TITLE OF FILE");
	// gtk_box_pack_start(GTK_BOX(e->gtk.globalbox), e->gtk.back_img, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.globalbox), e->gtk.label1, 0, 0, 10);
	top_box(e);
	sec_top_box(e);
	e->gtk.img = gtk_image_new_from_pixbuf(e->gtk.buffer);
	gtk_box_pack_start(GTK_BOX(e->gtk.imgbox), e->gtk.img, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(e->gtk.globalbox), e->gtk.imgbox, 0, 0, 0);
}

int	main(int ac, char **av)
{
	t_env e;

	gtk_init(&ac, &av);
	init_cam(&e.camera);
	init_vp(&e.vp);
	e.scene.ambiant.red = 1;
	e.scene.ambiant.green = 1;
	e.scene.ambiant.blue = 1;
	e.scene.background.red = 0;
	e.scene.background.green = 0;
	e.scene.background.blue = 0;
	e.scene.refr_index = 1;
	e.scene.obj = init_test();
	e.scene.lum = init_test_lum();
	init_gtk(&e);
	raytracing(&e);
	g_signal_connect(e.gtk.window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_container_add(GTK_CONTAINER(e.gtk.window), e.gtk.globalbox);
	// gtk_container_add(GTK_CONTAINER(e.gtk.window), e.gtk.back_img);
	gtk_widget_show_all(e.gtk.window);
	gtk_main();
	return (0);
}
//
