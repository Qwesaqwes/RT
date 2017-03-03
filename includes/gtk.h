/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:29:11 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/03 18:16:19 by jichen-m         ###   ########.fr       */
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

	GtkWidget		*l_obj;		/*label for type of object (Combo_box)*/
	GtkWidget		*l_nobj;	/*label for name of object*/
	GtkWidget		*l_pos;		/*label for position of object (x, y, z)*/
	GtkWidget		*l_scale;	/*label for scale of object (x, y, z)*/
	GtkWidget		*l_rot;		/*label for rotation of object (x, y, z)*/
	GtkWidget		*l_color;	/*label for color of object (wanna use a graf to put color)*/
	GtkWidget		*l_shine;	/*label for shininess of object*/
	GtkWidget		*l_refrac;	/*label for reflection of object*/
	GtkWidget		*l_ka;		/*label for ambient coefficient*/
	GtkWidget		*l_kd;		/*label for diffuse coefficient*/
	GtkWidget		*l_ks;		/*label for specular coefficient*/
	GtkWidget		*l_i;		/*label for intensity of light*/
	GtkWidget		*l_tr;		/*label for transparence*/
	GtkWidget		*l_x;
	GtkWidget		*l_y;
	GtkWidget		*l_z;
	GtkWidget		*l_x1;
	GtkWidget		*l_y1;
	GtkWidget		*l_z1;
	GtkWidget		*l_x2;
	GtkWidget		*l_y2;
	GtkWidget		*l_z2;
	GtkWidget		*l_tex;		/*label for texture*/
	GtkWidget		*l_che1;	/*label for color checker*/
	GtkWidget		*l_che2;	/*label for color checker*/
	GtkWidget		*l_square;	/*label for square checker*/


	GtkWidget		*c_obj;		/*Combo_box for object*/
	GtkWidget		*c_tex;		/*Combo_box for texture*/
	GtkWidget		*e_nobj;	/*entry for type of object*/
	GtkWidget		*e_posx;	/*entry for position of object (x, y, z)*/
	GtkWidget		*e_posy;	/*entry for position of object (x, y, z)*/
	GtkWidget		*e_posz;	/*entry for position of object (x, y, z)*/

	GtkWidget		*e_scalex;	/*entry for scale of object (x, y, z)*/
	GtkWidget		*e_scaley;	/*entry for scale of object (x, y, z)*/
	GtkWidget		*e_scalez;	/*entry for scale of object (x, y, z)*/

	GtkWidget		*e_rotx;		/*entry for rotation of object (x, y, z)*/
	GtkWidget		*e_roty;		/*entry for rotation of object (x, y, z)*/
	GtkWidget		*e_rotz;		/*entry for rotation of object (x, y, z)*/

	GtkWidget		*e_color;	/*entry for color of object (wanna use a graf to put color)*/
	GtkWidget		*e_shine;	/*entry for shininess of object*/
	GtkWidget		*e_refrac;	/*entry for reflection of object*/
	GtkWidget		*e_ka;		/*entry for ambient coefficient*/
	GtkWidget		*e_kd;		/*entry for diffuse coefficient*/
	GtkWidget		*e_ks;		/*entry for specular coefficient*/
	GtkWidget		*e_i;		/*entry for intensity of light*/
	GtkWidget		*e_tr;		/*entry for transparence*/
	GtkWidget		*e_che1;	/*entry for color texture*/
	GtkWidget		*e_che2;	/*entry for color texture*/
	GtkWidget		*e_square;	/*entry for Square texture*/


	GtkWidget		*obj_box;	/*boxes for dialog of Add object*/
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
