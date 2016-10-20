/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:56 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 03:15:06 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>


#include <stdio.h>


# define H 480
# define W 640
# define ESC 53

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
	float			angleX;
	float			angleY;
	float			angleZ;
}					t_camera;

typedef struct		s_img
{
	void 			*img_ptr;
	unsigned char 			*buffer;
	int				bpp;
	int				bpl;
	int				endian;
}					t_img;

typedef struct		s_ray
{
	t_vec3d			origin;
	t_vec3d			dir;
}					t_ray;

typedef struct		s_obj
{
	int				id;
	t_vec3d			center;
	//t_vec3d			dir;
	float			radius;
	char			type;
	t_color			color;
}					t_obj;

typedef struct		s_nearest_obj
{
	t_obj			obj;
	t_vec3d			ip;			//intersection point with obj
}					t_no;

typedef struct		s_scene
{
	t_list			*obj;
}					t_scene;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_camera		camera;
	t_vp			vp;
	t_scene			scene;
}					t_env;

t_color		compute_ray(t_ray ray, t_scene s);
t_no		get_nearest_obj(t_ray ray, t_list *list);
t_vec3d		rota_vect(t_vec3d old, float angleX, float angleY, float angleZ);
t_vec3d		normalizevec(t_vec3d old);
int			expose_hook(t_env *e);
int			key_release(int keycode, t_env *e);
void 		ft_pixel_put(int i, int j, t_rgb color, t_env e);
float		compute_solution(double a, double b, double d);
float		sphere_dist(t_ray r, t_obj o);
void 		init_vp(t_vp *vp);
void 		init_cam(t_camera *cam);
void		raytracing(t_env *e);

t_list 	*init_test(void);

#endif
