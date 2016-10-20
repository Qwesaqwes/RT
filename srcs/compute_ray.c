/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:10:57 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 02:42:59 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		compute_ray(t_ray ray, t_scene s)
{
	t_no	no;
	t_color	color;

	no = get_nearest_obj(ray, s.obj);
	ft_putchar('B');
	color = no.obj.color;
	return(color);
}
