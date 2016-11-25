/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inver_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JimmyChe <JimmyChe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:17:01 by JimmyChe          #+#    #+#             */
/*   Updated: 2016/11/25 15:44:49 by JimmyChen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrix	inver_rot_matrix(t_matrix old)
{
	t_matrix	inver;

	inver.a = old.a;
	inver.b = old.e;
	inver.c = old.i;
	inver.d = 0;
	inver.e = old.b;
	inver.f = old.f;
	inver.g = old.j;
	inver.h = 0;
	inver.i = old.c;
	inver.j = old.g;
	inver.k = old.k;
	inver.l = 0;
	inver.m = 0;
	inver.n = 0;
	inver.o = 0;
	inver.p = 1;
	return (inver);
}

t_matrix	inver_transl_matrix(t_matrix old)
{
	t_matrix	inver;

	inver.a = old.a;
	inver.b = old.b;
	inver.c = old.c;
	inver.d = (old.d) * (-1.0f);
	inver.e = old.e;
	inver.f = old.f;
	inver.g = old.g;
	inver.h = (old.h) * (-1.0f);
	inver.i = old.i;
	inver.j = old.j;
	inver.k = old.k;
	inver.l = (old.l) * (-1.0f);
	inver.m = old.m;
	inver.n = old.n;
	inver.o = old.o;
	inver.p = old.p;
	return (inver);
}

t_matrix	inver_scale_matrix(t_matrix old)
{
	t_matrix	inver;

	inver.a = (1.0f) / (old.a);
	inver.b = old.b;
	inver.c = old.c;
	inver.d = old.d;
	inver.e = old.e;
	inver.f = (1.0f) / (old.f);
	inver.g = old.g;
	inver.h = old.h;
	inver.i = old.i;
	inver.j = old.j;
	inver.k = (1.0f) / (old.k);
	inver.l = old.l;
	inver.m = old.m;
	inver.n = old.n;
	inver.o = old.o;
	inver.p = old.p;
	return (inver);
}
