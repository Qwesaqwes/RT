/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 22:46:13 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/05 22:49:29 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include "rt.h"

typedef	struct		s_verif_scene
{
	int				ambiant_rgb;
	int				refr_index;
	int				background_rgb;
	int				antialiasing;
}					t_verif_scene;

typedef	struct		s_verif_camera
{
	int				origin_xyz;
	int				rotation_xyz;
	int				distance_viewplane;
}					t_verif_camera;

typedef	struct		s_verif_object
{
	int				name;
	int				type;
	int				typel;
	int				color_rgb;
	int				scale_xyz;
	int				translate_xyz;
	int				rotation_xyz;
	int				k_ads;
	int				i;
	int				t;
	int				shininess;
	int				refraction_index;
	int				tex_texture;
	int				tex_bump;
	int				tex_transp;
	int				faces;
	int				map_buf;
	int				bump_buf;
	int				transp_buf;
	int				tex_col1;
	int				tex_col2;
	int				tex_col3;
	int				square;
	int				x_min;
	int				x_max;
	int				y_min;
	int				y_max;
	int				z_min;
	int				z_max;
	int				quadrics;
	int				normal_xyz;
}					t_verif_object;

typedef struct		s_parsing
{
	int				i;
	char			**file;
	char			**split;
	char			**split_face;
	int				fd1;
	int				fd2;
	char			*file_name;
	char			*fn;
	char			*file_name_bump;
	char			*file_name_transp;
	char			*tmpc;
	float			tmp;
	int				nbr_line;
	int				start;
	int				nb_scene;
	int				nb_camera;
	int				line;
	int				save_i;
	int				id_o;
	int				id_l;
	char			*name;
	int				error;
	int				faceend;
	int				ii;
	int				verif;
	int				source_exist;
	int				texture_5;
	char			*source_jpeg;
	int				nbr_source;
	int				verifc;
	t_camera		camera;
	t_vp			vp;
	t_scene			scene;
	t_obj			obj;
	t_obj			lum;
	t_verif_camera	vcamera;
	t_verif_scene	vscene;
	t_verif_object	vobject;
	t_vec3d			normal;
}					t_e;

/*
**		camera
*/
void				ft_fill_info_camera(t_env *rt, t_e *e);
int					ft_parsing_camera_after(t_env *rt, t_e *e, int i);

/*
**		face
*/
t_face				*ft_parsing_face_after(t_e *e, int i, int k);

/*
**		lum
*/
void				ft_fill_info_lum8(t_obj *obj, t_e *e);
void				ft_fill_info_lum5(t_obj *obj, t_e *e);
void				ft_fill_info_lum(t_obj *obj, t_e *e);
t_obj				ft_parsing_lum(t_e *e, int i);
void				ft_verif_limit_exist_lum(t_e *e, t_obj *tmp);


/*
**		object
*/
t_obj				ft_parsing_obj_after(t_e *e, int i);
void				ft_verif_nbr_object(t_e *e, t_obj obj);
void				ft_verif_nbr_object_v2(t_e *e, t_obj obj);
void				ft_verif_object_texture_4(t_e *e, int i);
void				ft_norme_object(t_e *e, t_obj *tmp, int i);
void				ft_free_object(t_e *e);
void				ft_verif_limit_exist(t_e *e, t_obj *tmp);
void				ft_fill_info_object(t_obj *obj, t_e *e);
void				ft_fill_info_object_6(t_obj *obj, t_e *e);
void				ft_fill_info_object_12(t_obj *obj, t_e *e);
void				ft_fill_info_object_18(t_obj *obj, t_e *e);

/*
**		reader
*/
void				ft_read_file(char *file, t_e *e);

/*
**		source
*/
void				ft_parsing_scene_after(t_env *rt, t_e *e, int i);
void				ft_fill_info_scene(t_scene *scene, t_e *e);

/*
**		parseur
*/
int					ft_fill_parce(t_env *rt, char *name);
int					ft_verif_scene_object(char *str);
void				ft_puterror(t_e *e, char *str);

/*
**		parsin_file
*/
t_list				*ft_parsing_obj(t_e *e);
void				ft_parsing_scene(t_env *rt, t_e *p);
void				ft_parsing_camera(t_env *rt, t_e *e);
t_list				*ft_parsing_light(t_e *e);

#endif
