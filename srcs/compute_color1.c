/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:05:20 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 20:43:19 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		dist_ip(t_obj obj, t_ray img_ray, t_ray ray)
{
	if (obj.type == 0)
		return (sphere_dist(img_ray));
	if (obj.type == 1)
		return (cylindre_dist(img_ray));
	if (obj.type == 2)
		return (plane_dist(obj, ray));
	if (obj.type == 3)
		return (cone_dist(img_ray));
	if (obj.type == 4)
		return (triangle_dist(ray, *obj.faces));
	else
		return (polygone_dist(ray, obj).dist);
}

t_color		diffuse_color(t_no no, t_obj lum, float k)
{
	t_color		color;

	color = color_fact(lum.color, no.obj.kd * (1 - no.obj.t) * k);
	color = color_mult(color, no.color);
	return (color);
}

t_color		spec_color(t_obj obj, t_obj lum, float k)
{
	t_color		color;

	color = color_fact(lum.color, obj.ks * k);
	return (color);
}
