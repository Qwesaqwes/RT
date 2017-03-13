/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:17:18 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 18:21:28 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	color_mult(t_color a, t_color b)
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

	ret.red = a.red * k;
	ret.green = a.green * k;
	ret.blue = a.blue * k;
	return (ret);
}

t_color		color_init(void)
{
	t_color		ret;

	ret.red = 0;
	ret.green = 0;
	ret.blue = 0;
	return (ret);
}
