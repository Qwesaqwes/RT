/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizevec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 04:01:50 by jichen-m          #+#    #+#             */
/*   Updated: 2016/11/23 15:09:27 by JimmyChen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d		normalizevec(t_vec3d old)
{
	double	length;
	t_vec3d	new;

	length = sqrt(old.x * old.x + old.y * old.y + old.z * old.z);
	new.x = old.x / length;
	new.y = old.y / length;
	new.z = old.z / length;
	new.w = 1;
	return (new);
}
