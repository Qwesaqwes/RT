/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:10:57 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 05:06:04 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		set_black_color(void)
{
	t_color	c;

	c.red = 0;
	c.green = 0;
	c.blue = 0;
	return(c);
}

t_color		compute_ray(t_ray ray, t_scene s)
{
	t_no	no;
	t_color	color;

	if (get_nearest_obj(ray, s.obj, &no) == 0)
		color = set_black_color();
	else
	{
		ft_putchar('A');
		color = no.obj.color;
		printf(" red2:%f", no.obj.color.red);
	}
	return(color);
}
