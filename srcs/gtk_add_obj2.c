/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:12:42 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/09 20:02:10 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	gtk_box_pack_start(GTK_BOX(gtk->obj_box8), gtk->l_refrac, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box8), gtk->e_refrac, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box9), gtk->l_ka, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box9), gtk->e_ka, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box9), gtk->l_kd, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box9), gtk->e_kd, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box9), gtk->l_ks, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box9), gtk->e_ks, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box10), gtk->l_i, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box10), gtk->e_i, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box11), gtk->l_tr, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box11), gtk->e_tr, 0, 0, 0);


}

void 	put_label_inside_box(t_gtk *gtk, int clicked)
{
	if (clicked == -10)
	{
		gtk_box_pack_start(GTK_BOX(gtk->obj_box), gtk->l_obj, 0, 0, 10);
		gtk_box_pack_start(GTK_BOX(gtk->obj_box), gtk->c_obj, 0, 0, 0);
	}
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

void 	put_box_inside_gbox(t_gtk	*gtk, int clicked)
{
	if (clicked == -10)
		gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box2, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box3, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box4, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box5, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box6, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box7, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box8, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box9, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box10, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box11, 0, 0, 0);
}
