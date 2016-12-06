/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:58:56 by opandolf          #+#    #+#             */
/*   Updated: 2016/12/06 18:37:42 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		reflection(t_no no, t_scene s, t_vec3d n, int depth)
{
	t_ray	reflected;
	t_color	color;

	reflected.origin = no.ip;
	reflected.dir = vector_sub(no.origin.dir, vector_fact(n, 2 * vector_scalar_product(no.origin.dir, n)));
	color = compute_ray(reflected, s, depth + 1, no.obj.id);
	return (color);
}
