/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:00:51 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/20 22:01:05 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb	get_color_pixel(guchar *pixel, t_gtk *gtk, int line, int col)
{
	t_rgb	color;

	// if(pixel[get_pos(line, col, gtk)])
	// {
		color.red = pixel[get_pos(line, col, gtk)];
		color.green = pixel[get_pos(line, col, gtk) + 1];
		color.blue = pixel[get_pos(line, col, gtk) + 2];
	// }
	// else
	// {
	// 	color.red = 0;
	// 	color.green = 0;
	// 	color.blue = 0;
	// }
	return (color);
}

int		xgrad(guchar *pixel, int line, int col, t_gtk *gtk)
{
	int		j;
	int		i;
	int		res;
	int		width[3][3];

	j = -1;
	res = 0;
	width[0][0] = -1;
	width[0][1] = 0;
	width[0][2] = 1;
	width[1][0] = -2;
	width[1][1] = 0;
	width[1][2] = 2;
	width[2][0] = -1;
	width[2][1] = 0;
	width[2][2] = 1;
	while (++j < 3)
	{
		i = -1;
		while (++i < 3)
		{
			res += width[j][i] *
			((pixel[get_pos(line + j, col + i, gtk)] +
			pixel[get_pos(line + j, col + i, gtk) + 1] +
			pixel[get_pos(line + j, col + i, gtk) + 2]) / 3);
		}
	}
	return (res);
}

int		ygrad(guchar *pixel, int line, int col, t_gtk *gtk)
{
	int		j;
	int		i;
	int		res;
	int		height[3][3];

	j = -1;
	res = 0;
	height[0][0] = -1;
	height[0][1] = -2;
	height[0][2] = -1;
	height[1][0] = 0;
	height[1][1] = 0;
	height[1][2] = 0;
	height[2][0] = 1;
	height[2][1] = 2;
	height[2][2] = 1;
	while(++j < 3)
	{
		i = -1;
		while(++i < 3)
		{
			res += height[j][i] *
			((pixel[get_pos(line + j, col + i, gtk)] +
			pixel[get_pos(line + j, col + i, gtk) + 1] +
			pixel[get_pos(line + j, col + i, gtk) + 2]) / 3);
		}
	}
	return (res);
}
