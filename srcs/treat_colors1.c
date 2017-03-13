/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_colors1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:19:57 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 20:44:04 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		color_cmp(t_color a, t_color b)
{
	float	ret;

	ret = (a.red - b.red) + (a.green - b.green) + (a.blue - b.blue);
	return (ret);
}

t_color		color_mult_fact(t_color a, t_color b, float k)
{
	t_color		ret;

	ret = color_fact(color_mult(a, b), k);
	return (ret);
}

t_color		set_black_color(void)
{
	t_color	c;

	c.red = 0;
	c.green = 0;
	c.blue = 0;
	return(c);
}

t_color		set_white_color(void)
{
	t_color	c;

	c.red = 1;
	c.green = 1;
	c.blue = 1;
	return(c);
}
