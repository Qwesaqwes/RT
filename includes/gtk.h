/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:29:11 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/05 22:45:55 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GTK_H
# define GTK_H

# define MOTION_KERNEL 20
# define BLUR_KERNEL 15

typedef	struct		s_gtk
{
	int				nb_effect;
	float			kernel[MOTION_KERNEL][MOTION_KERNEL];
	float			kernel1[BLUR_KERNEL][BLUR_KERNEL];
	GdkRGBA			*color;
	GdkPixbuf		*buffer;
	GdkPixbuf		*tmp_buf;
	guchar			*pixel;
	GtkWidget		*window;
	GtkWidget		*layout;
	GtkWidget		*img;
	GtkWidget		*imgbox;
	GtkWidget		*back_img;
	GtkWidget		*label1;
	GtkWidget		*zoom;
	GtkWidget		*dezoom;
	GtkWidget		*save;
	GtkWidget		*globalbox;
	GtkWidget		*vbox;
	GtkWidget		*stopbox;
	GtkWidget		*effect;
	GtkWidget		*n_effect;
	GtkWidget		*antial;
	GtkWidget		*n_antial;
	GtkWidget		*l_obj;
	GtkWidget		*l_nobj;
	GtkWidget		*l_pos;
	GtkWidget		*l_scale;
	GtkWidget		*l_rot;
	GtkWidget		*l_color;
	GtkWidget		*l_shine;
	GtkWidget		*l_refrac;
	GtkWidget		*l_ka;
	GtkWidget		*l_kd;
	GtkWidget		*l_ks;
	GtkWidget		*l_i;
	GtkWidget		*l_tr;
	GtkWidget		*l_x;
	GtkWidget		*l_y;
	GtkWidget		*l_z;
	GtkWidget		*l_x1;
	GtkWidget		*l_y1;
	GtkWidget		*l_z1;
	GtkWidget		*l_x2;
	GtkWidget		*l_y2;
	GtkWidget		*l_z2;
	GtkWidget		*l_tex;
	GtkWidget		*l_che1;
	GtkWidget		*l_che2;
	GtkWidget		*l_che3;
	GtkWidget		*l_square;
	GtkWidget		*l_limit;
	GtkWidget		*l_xmin;
	GtkWidget		*l_xmax;
	GtkWidget		*l_ymin;
	GtkWidget		*l_ymax;
	GtkWidget		*l_zmin;
	GtkWidget		*l_zmax;
	GtkWidget		*l_info_limit;
	GtkWidget		*c_obj;
	GtkWidget		*c_tex;
	GtkWidget		*e_nobj;
	GtkWidget		*e_posx;
	GtkWidget		*e_posy;
	GtkWidget		*e_posz;
	GtkWidget		*e_scalex;
	GtkWidget		*e_scaley;
	GtkWidget		*e_scalez;
	GtkWidget		*e_rotx;
	GtkWidget		*e_roty;
	GtkWidget		*e_rotz;
	GtkWidget		*e_color;
	GtkWidget		*e_shine;
	GtkWidget		*e_refrac;
	GtkWidget		*e_ka;
	GtkWidget		*e_kd;
	GtkWidget		*e_ks;
	GtkWidget		*e_i;
	GtkWidget		*e_tr;
	GtkWidget		*e_che1;
	GtkWidget		*e_che2;
	GtkWidget		*e_che3;
	GtkWidget		*e_square;
	GtkWidget		*e_xmin;
	GtkWidget		*e_xmax;
	GtkWidget		*e_ymin;
	GtkWidget		*e_ymax;
	GtkWidget		*e_zmin;
	GtkWidget		*e_zmax;
	GtkWidget		*obj_box;
	GtkWidget		*obj_box2;
	GtkWidget		*obj_box3;
	GtkWidget		*obj_box4;
	GtkWidget		*obj_box5;
	GtkWidget		*obj_box6;
	GtkWidget		*obj_box7;
	GtkWidget		*obj_box8;
	GtkWidget		*obj_box9;
	GtkWidget		*obj_box10;
	GtkWidget		*obj_box11;
	GtkWidget		*obj_box12;
	GtkWidget		*obj_box13;
	GtkWidget		*obj_box14;
	GtkWidget		*obj_box15;
	GtkWidget		*obj_box16;
	GtkWidget		*obj_gbox;
	GtkWidget		*view_obj;
	GtkWidget		*windowscr;
	GtkWidget		*gtklist;
	GtkWidget		*choose_f;
}					t_gtk;

enum
{
	OBJ_COLUMN,
	TYPE_COLUMN,
	ID_COLUMN,
	N_COLUMNS
};
#endif
