/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:01:33 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 17:01:35 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d	inter_point_to_zero(t_obj obj, t_vec3d ip)
{
	t_vec3d	zero_ip;

	zero_ip.x = ip.x - obj.transform.transl.x;
	zero_ip.y = ip.y - obj.transform.transl.y;
	zero_ip.z = ip.z - obj.transform.transl.z;
	zero_ip.w = 1;
	zero_ip = mult_matrix(rotation_x(-obj.transform.rot.x), zero_ip);
	zero_ip = mult_matrix(rotation_y(-obj.transform.rot.y), zero_ip);
	zero_ip = mult_matrix(rotation_z(-obj.transform.rot.z), zero_ip);
	return (zero_ip);
}
