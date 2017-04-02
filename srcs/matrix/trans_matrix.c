/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JimmyChe <JimmyChe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:25:23 by JimmyChe          #+#    #+#             */
/*   Updated: 2016/11/23 16:28:19 by JimmyChen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrix		trans_matrix(t_vec3d center)
{
	t_matrix	new;

	new.a = 1;
	new.b = 0;
	new.c = 0;
	new.d = center.x;
	new.e = 0;
	new.f = 1;
	new.g = 0;
	new.h = center.y;
	new.i = 0;
	new.j = 0;
	new.k = 1;
	new.l = center.z;
	new.m = 0;
	new.n = 0;
	new.o = 0;
	new.p = 1;
	return (new);
}
