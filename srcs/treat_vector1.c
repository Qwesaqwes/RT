/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_vector1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:16:12 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 18:16:57 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d		vector_cross(t_vec3d a, t_vec3d b)
{
	t_vec3d		ret;

	ret.x = a.y * b.z - a.z * b.y;
	ret.y = a.z * b.x - a.x * b.z;
	ret.z = a.x * b.y - a.y * b.x;
	ret.w = 1;
	return (ret);
}
