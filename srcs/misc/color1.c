/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 20:45:51 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 20:45:53 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		color_mult(t_color a, t_color b)
{
	t_color res;

	res.red = fmin(a.red * b.red, 1);
	res.green = fmin(a.green * b.green, 1);
	res.blue = fmin(a.blue * b.blue, 1);
	return (res);
}

t_color		color_add(t_color a, t_color b)
{
	t_color res;

	res.red = fmin(1.0, a.red + b.red);
	res.blue = fmin(1.0, a.blue + b.blue);
	res.green = fmin(1.0, a.green + b.green);
	return (res);
}

t_color		color_add_no_limit(t_color a, t_color b)
{
	t_color res;

	res.red = a.red + b.red;
	res.blue = a.blue + b.blue;
	res.green = a.green + b.green;
	return (res);
}

t_color		color_sub(t_color a, t_color b)
{
	t_color res;

	res.red = fmax(0.0, a.red - b.red);
	res.blue = fmax(0.0, a.blue - b.blue);
	res.green = fmax(0.0, a.green - b.green);
	return (res);
}

t_color		color_fact(t_color a, float k)
{
	t_color	ret;

	ret.red = fmin(1.0, a.red * k);
	ret.green = fmin(1.0, a.green * k);
	ret.blue = fmin(1.0, a.blue * k);
	return (ret);
}
