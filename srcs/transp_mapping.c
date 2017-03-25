/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transp_mapping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:01:21 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:52:01 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		transp_mapping(t_no no)
{
	float		u;
	float		v;
	t_vec3d		rot_angle;
	guchar		*pixel;

	if (no.obj.tex.transp == 0)
		return (no.obj.t);
	if (no.obj.type == 0)
		uv_sphere(no, &u, &v, &rot_angle);
	else
		uv_polygone(no, &u, &v, &rot_angle);
	pixel = gdk_pixbuf_get_pixels(no.obj.transp_buf);
	return ((float)pixel[map_value(u, v, no.obj.transp_buf)] / 255.0f);
}
