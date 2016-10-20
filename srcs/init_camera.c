/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:16:25 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 01:47:22 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	init_vp(t_vp *vp)
{
	vp->dist = 100;
	vp->width = 100;
	vp->width = 100;
}


void 	init_cam(t_camera *cam)
{
	cam->baseU.x = 1;
	cam->baseU.y = 0;
	cam->baseU.z = 0;
	cam->baseV.x = 0;
	cam->baseV.y = 1;
	cam->baseV.z = 0;
	cam->baseW.x = 0;
	cam->baseW.y = 0;
	cam->baseW.z = 1;
}
