/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:16:25 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/05 21:55:37 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_vp(t_vp *vp)
{
	vp->dist = 1;
	vp->width = 1;
	vp->height = (float)H / (float)W;
}

void	init_cam(t_camera *cam)
{
	cam->base_u.x = 1;
	cam->base_u.y = 0;
	cam->base_u.z = 0;
	cam->base_u.w = 1;
	cam->base_v.x = 0;
	cam->base_v.y = 1;
	cam->base_v.z = 0;
	cam->base_v.w = 1;
	cam->base_w.x = 0;
	cam->base_w.y = 0;
	cam->base_w.z = 1;
	cam->base_w.w = 1;
	cam->origin.x = 6;
	cam->origin.y = 3;
	cam->origin.z = 10;
	cam->origin.w = 1;
	cam->rot.x = 0;
	cam->rot.y = 35;
	cam->rot.z = -22.5;
	cam->rot.w = 1;
}
