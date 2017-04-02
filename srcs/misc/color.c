/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 20:45:38 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 20:45:43 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		color_cmp(t_color a, t_color b)
{
	float ret;

	ret = (a.red - b.red) + (a.green - b.green) + (a.blue - b.blue);
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

t_color		color_mult_fact(t_color a, t_color b, float k)
{
	t_color		ret;

	ret = color_fact(color_mult(a, b), k);
	return (ret);
}
