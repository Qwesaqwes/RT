/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:56 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/06 21:53:02 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <math.h>
# include "libft.h"
# include <stdlib.h>
# include <gtk/gtk.h>
# include <pthread.h>
# include "gtk.h"
# include "struct.h"

# include <stdio.h>

# define H 600
# define W 900
# define ESC 53
# define MAX_DEPTH 3
# define SHADOW_BIAS 0.0001
# define NB_THREAD 8

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
t_vec3d		set_inter_point(float dist, t_ray ray);
t_pret		polygone_dist(t_ray ray, t_obj obj);
float		triangle_dist(t_ray ray, t_face obj);

float    	plane_dist2(t_face obj, t_ray r);


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


void 		gtk_s_img(GtkWidget	*button, gpointer buffer);
void 		gtk_zoom(GtkWidget *button, t_env *e);
void 		gtk_dezoom(GtkWidget *button, t_env *e);
void 		gtk_add_obj(t_env *e, int resp);
void 		put_box_inside_gbox(t_gtk	*gtk, int resp);
void 		put_label_inside_box(t_gtk *gtk, int resp);
void 		init_gtk(t_env *e);
int			create_new_obj(t_env *e);
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
void		gtk_choose_f(GtkWidget *button, t_env *e);
void		gtk_effect(GtkWidget *button, t_env *e);
int			get_pos(int line, int col, t_gtk *gtk);
void		no_effect(t_env *e);
void		sepia_effect(t_env *e);
void		greyscale_effect(t_env *e);
void		sobel_effect(t_env *e);
void		cartoon_effect(t_env *e);
void		motion_effec(t_env *e);
void		blur_effec(t_env *e);
void		stereo_effect(t_env *e);
int			ygrad(guchar *pixel, int line, int col, t_gtk *gtk);
int			xgrad(guchar *pixel, int line, int col, t_gtk *gtk);
t_rgb		get_color_pixel(guchar *pixel, t_gtk *gtk, int line, int col);
const char	*get_selected_row(t_env *e, t_list 	*list);
void 		init_modif_obj_e(t_gtk *gtk, const char *object, t_list **list);
int			put_tex_obj(t_gtk *gtk, t_tex *texture);
void		put_normal(t_vec3d *normal);




t_color		texture_color(t_no no);



t_list 	*init_test(void);
t_list	*init_test_lum(void);

t_vec3d  inter_point_to_zero(t_obj obj, t_vec3d ip);

#endif
