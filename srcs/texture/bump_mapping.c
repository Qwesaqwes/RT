/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:48:03 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 18:02:02 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		choose_obj_bumpmap(t_no no, float *u, float *v, t_vec3d *rot_angle)
{
	if (no.obj.type == 0)
		uv_sphere(no, u, v, rot_angle);
	else
		uv_polygone(no, u, v, rot_angle);
}

void		bu_bumpmap(t_no no, float u, float v, float *bu)
{
	guchar		*pixel;

	pixel = gdk_pixbuf_get_pixels(no.obj.bump_buf);
	*bu = (float)(pixel[map_value_right(u, v, no.obj.bump_buf)] -
		pixel[map_value(u, v, no.obj.bump_buf)]) / 255.0f;
}

void		bv_bumpmap(t_no no, float u, float v, float *bv)
{
	guchar		*pixel;

	pixel = gdk_pixbuf_get_pixels(no.obj.bump_buf);
	*bv = (float)(pixel[map_value_down(u, v, no.obj.bump_buf)] -
		pixel[map_value(u, v, no.obj.bump_buf)]) / 255.0f;
}

t_vec3d		modif_normal_bumpmap(t_vec3d rot_angle, t_no no, float bu, float bv)
{
	t_vec3d		n;

	n = no.normal;
	n = mult_matrix(rotationX(-rot_angle.x), n);
	n = mult_matrix(rotationY(-rot_angle.y), n);
	n = mult_matrix(rotationZ(-rot_angle.z), n);
	n = vector_add(n, vector_add(
		vector_fact(vector_cross(n, (t_vec3d){0, 1, 0, 1}), -bv * 10),
		vector_fact(vector_cross(n, (t_vec3d){0, 0, 1, 1}), -bu * 10)));
	n = mult_matrix(rotationX(rot_angle.x), n);
	n = mult_matrix(rotationY(rot_angle.y), n);
	n = mult_matrix(rotationZ(rot_angle.z), n);
	return (n);
}

t_vec3d		bump_mapping(t_no no)
{
	float	u;
	float	v;
	float	bu;
	float	bv;
	t_vec3d	rot_angle;

	if (no.obj.tex.bump == 0)
		return (no.normal);
	choose_obj_bumpmap(no, &u, &v, &rot_angle);
	bu_bumpmap(no, u, v, &bu);
	bv_bumpmap(no, u, v, &bv);
	return (modif_normal_bumpmap(rot_angle, no, bu, bv));
}
