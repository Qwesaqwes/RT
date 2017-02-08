/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JimmyChe <JimmyChe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:43:33 by JimmyChe          #+#    #+#             */
/*   Updated: 2016/11/23 16:28:37 by JimmyChen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrix	scale_matrix(t_vec3d center)
{
	t_matrix	new;

	new.a = center.x;
	new.b = 0;
	new.c = 0;
	new.d = 0;
	new.e = 0;
	new.f = center.y;
	new.g = 0;
	new.h = 0;
	new.i = 0;
	new.j = 0;
	new.k = center.z;
	new.l = 0;
	new.m = 0;
	new.n = 0;
	new.o = 0;
	new.p = 1;
	return (new);
}
