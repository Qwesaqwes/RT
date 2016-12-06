/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:10:57 by jichen-m          #+#    #+#             */
/*   Updated: 2016/12/06 18:23:50 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		set_black_color(void)
{
	t_color	c;

	c.red = 0;
	c.green = 0;
	c.blue = 0;
	return(c);
}

t_color		compute_ray(t_ray ray, t_scene s, int depth, char id_refl)
{
	t_no	no;
	t_color	color;
	t_vec3d normal_vec;

	if (get_nearest_obj(ray, s.obj, &no, id_refl) == 0)
	{
		color = set_black_color();
	}
	else
	{
		normal_vec = compute_normal_vec(no);
		color = compute_color(no, s, normal_vec, no.origin.origin);
		if(depth < MAX_DEPTH)
		{
			color = color_add(color, color_mult(reflection(no, s, normal_vec, depth), no.obj.k.s));
		}
	}
	return(color);
}
