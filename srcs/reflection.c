/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:58:56 by opandolf          #+#    #+#             */
/*   Updated: 2016/12/07 10:35:07 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		reflection(t_no no, t_scene s, t_vec3d n, t_values v)
{
	t_ray	reflected;
	t_color	color;

	reflected.origin = vector_add(no.ip, vector_fact(n, SHADOW_BIAS));
	reflected.dir = vector_sub(no.origin.dir, vector_fact(n, 2 * vector_scalar_product(no.origin.dir, n)));
	v.depth = v.depth + 1;
	color = compute_ray(reflected, s, v);
	return (color);
}
