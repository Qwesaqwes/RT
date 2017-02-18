/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:09:30 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/18 15:54:03 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	init_add_obj_box(t_gtk *gtk, int clicked)
{
	if (clicked == -10)
		gtk->obj_box = gtk_box_new(0, 0);
	gtk->obj_box2 = gtk_box_new(0, 0);
	gtk->obj_box3 = gtk_box_new(0, 0);
	gtk->obj_box4 = gtk_box_new(0, 0);
	gtk->obj_box5 = gtk_box_new(0, 0);
	gtk->obj_box6 = gtk_box_new(0, 0);
	gtk->obj_box7 = gtk_box_new(0, 0);
	gtk->obj_box8 = gtk_box_new(0, 0);
	gtk->obj_box9 = gtk_box_new(0, 0);
	gtk->obj_box10 = gtk_box_new(0, 0);
	gtk->obj_box11 = gtk_box_new(0, 0);
	gtk->obj_gbox = gtk_box_new(1, 0);
}

void 	init_add_obj_l_e2(t_gtk *gtk)
{
	gtk->l_obj = gtk_label_new("Type of Object -->");
	gtk->e_ka = gtk_entry_new();
	gtk->e_kd = gtk_entry_new();
	gtk->e_ks = gtk_entry_new();
	gtk->e_i = gtk_entry_new();
	gtk->e_tr = gtk_entry_new();
	gtk->e_refrac = gtk_entry_new();
	gtk->e_color = gtk_color_button_new();
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

void 	init_add_obj_l_e(t_gtk *gtk, int clicked)
{
	if (clicked == -10)
		init_add_obj_l_e2(gtk);
	gtk->l_nobj = gtk_label_new("Name of Object -->");
	gtk->l_pos = gtk_label_new("Position of Object -->");
	gtk->l_scale = gtk_label_new("Scale of Object -->");
	gtk->l_rot = gtk_label_new("Rotation of Object -->");
	gtk->l_color = gtk_label_new("Color of Object -->");
	gtk->l_shine = gtk_label_new("Shininess of Object -->");
	gtk->l_refrac = gtk_label_new("Refraction of Object -->");
	gtk->l_ka = gtk_label_new("Ambient coefficient -->");
	gtk->l_kd = gtk_label_new("Diffuse coefficient -->");
	gtk->l_ks = gtk_label_new("Specular coefficient -->");
	gtk->l_i = gtk_label_new("Intensity of light -->");
	gtk->l_tr = gtk_label_new("Transparence -->");
	gtk->l_x = gtk_label_new("x: ");
	gtk->l_x1 = gtk_label_new("x: ");
	gtk->l_x2 = gtk_label_new("x: ");
	gtk->l_y = gtk_label_new("y: ");
	gtk->l_y1 = gtk_label_new("y: ");
	gtk->l_y2 = gtk_label_new("y: ");
	gtk->l_z = gtk_label_new("z: ");
	gtk->l_z1 = gtk_label_new("z: ");
	gtk->l_z2 = gtk_label_new("z: ");

}

void 	gtk_add_obj(t_env *e, int clic_add)
{
	GtkWidget	*dialog;
	GtkWidget	*area;
	gint 		response;

	init_add_obj_l_e(&e->gtk, clic_add);
	init_add_obj_box(&e->gtk, clic_add);
	dialog = gtk_dialog_new_with_buttons("Add Object",
	GTK_WINDOW(e->gtk.window), GTK_DIALOG_MODAL, ("CANCEL"),
	GTK_RESPONSE_REJECT, ("OK"), GTK_RESPONSE_ACCEPT, NULL);
	area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	put_label_inside_box(&e->gtk, clic_add);
	put_box_inside_gbox(&e->gtk, clic_add);
	gtk_container_add(GTK_CONTAINER(area), e->gtk.obj_gbox);
	gtk_widget_show_all(dialog);
	response = gtk_dialog_run(GTK_DIALOG(dialog));
	create_new_obj(response, GTK_RESPONSE_ACCEPT, e);
	gtk_widget_destroy(dialog);
}
