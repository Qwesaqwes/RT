/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:56 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/09 22:19:44 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <gtk/gtk.h>


#include <stdio.h>


# define H 600
# define W 600
# define ESC 53
# define MAX_DEPTH 3
# define SHADOW_BIAS 0.0001

typedef struct		s_matrix
{
	float			a;
	float			b;
	float			c;
	float			d;
	float			e;
	float			f;
	float			g;
	float			h;
	float			i;
	float			j;
	float			k;
	float			l;
	float			m;
	float			n;
	float			o;
	float			p;
}					t_matrix;

typedef struct		s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef	struct		s_viewplane
{
	float			dist;
	int				width;
	int				height;
}					t_vp;

typedef struct		s_vec3d
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec3d;

typedef struct		s_camera
{
	t_vec3d			origin;
	t_vec3d			vectorU;
	t_vec3d			vectorV;
	t_vec3d			vectorW;
	t_vec3d			baseU;
	t_vec3d			baseV;
	t_vec3d			baseW;
	t_vec3d			rot;
}					t_camera;

typedef struct		s_ray
{
	t_vec3d			origin;
	t_vec3d			dir;
}					t_ray;

typedef struct		s_transform
{
	t_vec3d			scale;
	t_vec3d			transl;
	t_vec3d			rot;
}					t_transform;

typedef struct		s_parameters
{
	t_color			a;
	t_color			d;
	t_color			s;
	t_color			t;
}					t_param;

typedef struct		s_obj
{
	int				id;
	const char		*name;
	char			type;
	t_color			color;
	float			ka;
	float			kd;
	float			ks;
	float			i;
	float			t;
	float			shininess;
	t_transform		transform;
	float			refr_index;
	t_vec3d			normal;
}					t_obj;

typedef struct		s_nearest_obj
{
	t_obj			obj;
	t_vec3d			ip;
	t_ray			img_ray;
	t_ray			origin;
	t_vec3d			normal;
}					t_no;

typedef struct		s_calculated_values
{
	t_vec3d			normal;
	t_vec3d			ip;
	float			n1;
	float			n2;
	float			n;
	float			cosI;
	float			sinT2;
	char			TIR;
	float			cosT;
	char			action;
	char			sign;
}					t_cv;

typedef	struct		s_values
{
	int				depth;
	char			id_refl;
	t_list			**refr_index;
	char			enter;
}					t_values;
typedef struct		s_scene
{
	t_list			*obj;
	t_list			*lum;
	t_color			ambiant;
	float			refr_index;
	t_color			background;
}					t_scene;

typedef	struct		s_gtk
{
	GdkRGBA			*color;
	GdkPixbuf		*buffer;
	guchar			*pixel;
	GtkWidget		*window;
	GtkWidget		*img;
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
	GtkWidget		*imgbox;

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

	GtkWidget		*c_obj;		/*Combo_box for object*/
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
	GtkWidget		*obj_gbox;

	GtkWidget		*view_obj;
	GtkWidget		*windowscr;
	GtkWidget		*gtklist;

}					t_gtk;

enum
{
	OBJ_COLUMN,
	TYPE_COLUMN,
	N_COLUMNS
};

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	// t_img			img;
	t_camera		camera;
	t_vp			vp;
	t_scene			scene;
	t_gtk			gtk;
}					t_env;

t_color		compute_ray(t_ray ray, t_scene s, t_values v);
t_vec3d		compute_normal_vec(t_no no);
t_ray		imaginary_ray(t_ray ray, t_transform t);

int			get_nearest_obj(t_ray ray, t_list *list, t_no *no);
t_vec3d		rota_vect(t_vec3d old, t_vec3d rot);
int			expose_hook(t_env *e);
int			key_release(int keycode, t_env *e);
void 		ft_pixel_put(int i, int j, t_rgb color, t_env e);
float		compute_solution(double a, double b, double d);
float		sphere_dist(t_ray r);
t_vec3d	sphere_normal_vec(t_vec3d ip, t_vec3d t);
t_vec3d		cylindre_normal_vec(t_no no);
float		cylindre_dist(t_ray r);
float		plane_dist(t_obj obj, t_ray r);
float		cone_dist(t_ray r);
t_vec3d		cone_normal_vec(t_no no);

void 		init_vp(t_vp *vp);
void 		init_cam(t_camera *cam);
void		raytracing(t_env *e);
t_matrix	scale_matrix(t_vec3d center);
t_matrix	trans_matrix(t_vec3d center);
t_matrix	inver_rot_matrix(t_matrix old);
t_matrix	inver_transl_matrix(t_matrix old);
t_matrix	inver_scale_matrix(t_matrix old);
t_vec3d		mult_matrix(t_matrix mat, t_vec3d old);
t_matrix	rotationX(float angle);
t_matrix	rotationY(float angle);
t_matrix	rotationZ(float angle);
t_vec3d		normalizevec(t_vec3d old);

t_color		compute_color(t_no no, t_scene s, t_vec3d n, t_vec3d origin);

t_vec3d		vector_sub(t_vec3d a, t_vec3d b);
float		vector_dot(t_vec3d a, t_vec3d b);
t_vec3d		vector_fact(t_vec3d a, float k);
t_vec3d		vector_add(t_vec3d a, t_vec3d b);

t_color		color_add(t_color a, t_color b);
t_color		color_mult(t_color a, t_color b);
t_color		color_sub(t_color a, t_color b);
t_color		color_fact(t_color a, float k);

t_color		reflection(t_no no, t_scene s, t_vec3d n, t_values v);
t_color		refraction(t_no no, t_scene s, t_vec3d n, t_values v);

t_color		set_black_color(void);
t_color		set_white_color(void);

void		init_calculed_values(t_cv *cv, float n1, float n2);
t_ray		reflect(t_vec3d normal, t_vec3d incident, t_vec3d ip, t_cv cv);
t_ray		refract(t_vec3d normal, t_vec3d incident, t_vec3d ip, t_cv cv);
float		fresnel(t_cv cv);
float		schlick(t_cv cv);

void		modify_refr_list(t_cv *cv, t_list **list);
void		ft_lstdelfirst(t_list **alst);

void 		reset_img(t_gtk *gtk);
void 		gtk_s_img(GtkWidget	*button, gpointer buffer);
void 		gtk_zoom(GtkWidget *button, t_env *e);
void 		gtk_dezoom(GtkWidget *button, t_env *e);
void 		gtk_add_obj(t_env *e, int resp);
void 		put_box_inside_gbox(t_gtk	*gtk, int resp);
void 		put_label_inside_box(t_gtk *gtk, int resp);
void 		init_gtk(t_env *e);
int			create_new_obj(int response, int clicked_ok, t_env *e);
int			put_scale_obj(t_gtk *gtk, t_vec3d *scale);
int		 	check_if_digit(const char * str);
int			put_rotation_obj(t_gtk *gtk, t_vec3d *rot);
int			put_name_obj(t_gtk *gtk, const char **name, t_list *obj, int *i);
int			put_pos_obj(t_gtk *gtk, t_vec3d *pos);
void		put_id_ob(t_list *obj, int *i);
void		put_color_obj(t_gtk *gtk, t_color *color);
int			put_shininess_obj(t_gtk *gtk, float *shine);
int			put_refraction_obj(t_gtk *gtk, float *refrac);
int			put_amb_coe_obj(t_gtk *gtk, float *ka);
int			put_dif_coe_obj(t_gtk *gtk, float *kd);
int			put_spec_coe_obj(t_gtk *gtk, float *ks);
int			put_i_light_obj(t_gtk *gtk, float *i);
int			put_tr_obj(t_gtk *gtk, float *tr);
float 		stof (const char *s);
void 		gtk_view_obj(GtkWidget *button, t_env *e);
void 		view_delete_obj(int response, int clicked_del, t_env *e, GtkWidget *view);
int			view_modif_obj(int response, int clic_mod, t_env *e, GtkWidget *dialog);
void 		init_add_obj_l_e(t_gtk *gtk, int resp);
void 		init_add_obj_box(t_gtk *gtk, int resp);
const char	*itof(float nb);
void		ft_list_remove_if(t_list **begin_list, const char *data_ref,
			int (*cmp)());








t_list 	*init_test(void);
t_list	*init_test_lum(void);

t_vec3d  inter_point_to_zero(t_obj obj, t_vec3d ip);


#endif
