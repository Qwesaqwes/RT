/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:16:25 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:40:51 by jichen-m         ###   ########.fr       */
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
	cam->baseU.x = 1;
	cam->baseU.y = 0;
	cam->baseU.z = 0;
	cam->baseU.w = 1;
	cam->baseV.x = 0;
	cam->baseV.y = 1;
	cam->baseV.z = 0;
	cam->baseV.w = 1;
	cam->baseW.x = 0;
	cam->baseW.y = 0;
	cam->baseW.z = 1;
	cam->baseW.w = 1;
	cam->origin.x = 0;
	cam->origin.y = 0;
	cam->origin.z = 0;
	cam->origin.w = 1;
	cam->rot.x = 0;
	cam->rot.y = 0;
	cam->rot.z = 0;
	cam->rot.w = 1;
}
