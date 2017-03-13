/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:51:45 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 19:57:41 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d		inter_point_to_zero(t_obj obj, t_vec3d ip)
{
	t_vec3d	zero_ip;

	zero_ip.x = ip.x - obj.transform.transl.x;
	zero_ip.y = ip.y - obj.transform.transl.y;
	zero_ip.z = ip.z - obj.transform.transl.z;
	zero_ip.w = 1;
	zero_ip = mult_matrix(rotationX(-obj.transform.rot.x), zero_ip);
	zero_ip = mult_matrix(rotationY(-obj.transform.rot.y), zero_ip);
	zero_ip = mult_matrix(rotationZ(-obj.transform.rot.z), zero_ip);
	return (zero_ip);
}
