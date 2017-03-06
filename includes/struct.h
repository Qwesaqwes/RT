/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:47:02 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/06 21:51:03 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	float				width;
	float				height;
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

typedef struct		s_vertex
{
	t_vec3d			coord;
	struct s_vertex	*next;
}					t_vertex;

typedef struct		s_face
{
	t_vertex		*vertex;
	t_vec3d			normal;
	struct s_face	*next;
}					t_face;

typedef	struct		s_poly_return
{
	float			dist;
	t_face			*no;
}					t_pret;

typedef struct		s_texture
{
	int				texture;	// texture == 0 si no texture
	t_color			tex_col1;
	t_color			tex_col2;
	t_color			tex_col3;
	float			square;
}					t_tex;

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
	t_face			*faces;
	t_tex			tex;
}					t_obj;

typedef struct		s_nearest_obj
{
	t_obj			obj;
	t_vec3d			ip;
	t_ray			img_ray;
	t_ray			origin;
	t_vec3d			normal;
	t_face			*poly_face;
	t_color			color;
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

typedef struct	s_thread_data
{
   int h_start;
   int h_end;
   t_env *e;
}				t_thread_data;


#endif
