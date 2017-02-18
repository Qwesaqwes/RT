/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 04:57:58 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/18 15:18:32 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rt.h"

int		get_pos(int line, int col, t_gtk *gtk)
{
	int				tmp;
	unsigned int	rowstride;
	unsigned int	n_channels;

	n_channels = gdk_pixbuf_get_n_channels(gtk->buffer);
	rowstride = gdk_pixbuf_get_rowstride (gtk->buffer);
	tmp = line * rowstride + col * n_channels;
	return (tmp);
}

void	sepia_effect(t_rgb *color, t_gtk *gtk, int col, int line)
{
	int		i;
	int		j;
	int		k;
	guchar			*pixel;


	// pixel = NULL;
	pixel = gdk_pixbuf_get_pixels(gtk->buffer);
	i = (color->red * 0.189) + (color->green * 0.769) + (color->blue * 0.393);
	j = (color->red * 0.168) + (color->green * 0.686) + (color->blue * 0.349);
	k = (color->red * 0.131) + (color->green * 0.534) + (color->blue * 0.272);
	pixel[get_pos(line, col, gtk)] = i > 255 ? 255 : i;
	pixel[get_pos(line, col, gtk) + 1] = j > 255 ? 255 : j;
	pixel[get_pos(line, col, gtk) + 2] = k > 255 ? 255 : k;
	gtk_image_set_from_pixbuf(GTK_IMAGE(gtk->img), gtk->buffer);
}

void	gray_scale_effect(t_rgb *color, t_gtk *gtk, int col, int line)
{
	int		res;
	guchar	*pixel;
	int		tmp;

	// pixel = NULL;
	pixel = gdk_pixbuf_get_pixels(gtk->buffer);
	tmp = get_pos(line, col, gtk);
	res = (color->red * 0.333) + (color->green * 0.333) + (color->blue * 0.333);
	pixel[tmp] = res > 255 ? 255 : res;
	pixel[tmp + 1] = res > 255 ? 255 : res;
	pixel[tmp + 2] = res > 255 ? 255 : res;
	gtk_image_set_from_pixbuf(GTK_IMAGE(gtk->img), gtk->buffer);
}

void	no_effect(t_rgb *color, t_gtk *gtk, int col, int line)
{
	guchar	*pixel;
	int		tmp;

	// pixel = NULL;
	pixel = gdk_pixbuf_get_pixels(gtk->buffer);
	tmp = get_pos(line, col, gtk);
	pixel[tmp] = color->red;
	pixel[tmp + 1] = color->green;
	pixel[tmp + 2] = color->blue;
	gtk_image_set_from_pixbuf(GTK_IMAGE(gtk->img), gtk->buffer);
}

int		xgrad(guchar *pixel, int line, int col, t_gtk *gtk)
{
	int		j;
	int		i;
	int		res;
	int		weight[3][3];

	j = -1;
	res = 0;
	weight[0][0] = -1;
	weight[0][1] = 0;
	weight[0][2] = 1;
	weight[1][0] = -2;
	weight[1][1] = 0;
	weight[1][2] = 2;
	weight[2][0] = -1;
	weight[2][1] = 0;
	weight[2][2] = 1;
	while (++j < 3)
	{
		i = -1;
		while (++i < 3)
			res += weight[j][i] * pixel[get_pos(line + j, col + i, gtk)];
	}
	return (res);
}

int		ygrad(guchar *pixel, int line, int col, t_gtk *gtk)
{
	int		j;
	int		i;
	int		res;
	int		height[3][3];

	i = -1;
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
	while(++i < 3)
	{
		j = -1;
		while(++j < 3)
		res += height[j][i] * pixel[get_pos(line + j, col + i, gtk)];
	}
	return (res);
}

void	sobel_effect(int col, int line, t_gtk *gtk)
{
	guchar	*pixel;
	int		sum;

	// pixel = NULL;
	pixel = gdk_pixbuf_get_pixels(gtk->buffer);
	sum = abs(xgrad(pixel, line, col, gtk)) + abs(ygrad(pixel, line, col, gtk));
	sum = sum > 255 ? 255 : sum;
	sum = sum < 0 ? 0 : sum;
	pixel[get_pos(line, col, gtk)] = sum;
	pixel[get_pos(line, col, gtk) + 1] = sum;
	pixel[get_pos(line, col, gtk) + 2] = sum;
	gtk_image_set_from_pixbuf(GTK_IMAGE(gtk->img), gtk->buffer);
}

int		limit_color(int col)
{
	if (col <= 0)
		return (0);
	else if (col > 0 && col <= 50)
		return (25);
	else if (col > 50 && col <= 100)
		return (75);
	else if (col > 100 && col <= 200)
		return (150);
	else if (col > 200 && col <= 250)
		return (225);
	else if ((col > 250 && col <= 255) || col > 255)
		return (255);
	else
		return (col);
}

void	cartoon_effect(t_rgb *color, int col, int line, t_gtk *gtk)
{
	guchar	*pixel;
	int		sum;

	// pixel = NULL;
	pixel = gdk_pixbuf_get_pixels(gtk->buffer);
	sum = abs(xgrad(pixel, line, col, gtk)) + abs(ygrad(pixel, line, col, gtk));
	sum = 255 - sum;
	sum = sum > 255 ? 255 : sum;
	sum = sum < 0 ? 0 : sum;
	if (sum > 100)
	{
		color->red = limit_color(color->red);
		color->green = limit_color(color->green);
		color->blue = limit_color(color->blue);
		pixel[get_pos(line, col, gtk)] = color->red;
		pixel[get_pos(line, col, gtk) + 1] = color->green;
		pixel[get_pos(line, col, gtk) + 2] = color->blue;
	}
	else
	{
		pixel[get_pos(line, col, gtk)] = sum;
		pixel[get_pos(line, col, gtk) + 1] = sum;
		pixel[get_pos(line, col, gtk) + 2] = sum;
	}
	gtk_image_set_from_pixbuf(GTK_IMAGE(gtk->img), gtk->buffer);
}

// t_rgb	*kernel_blur(guchar *pixel, int col, int line, t_gtk *gtk)
// {
// 	int		j;
// 	int		i;
// 	int		res;
// 	float	height[3][3];
//
// 	i = -1;
// 	res = 0;
// 	height[0][0] = 0.0625;
// 	height[0][1] = 0.125;
// 	height[0][2] = 0.0625;
// 	height[1][0] = 0.125;
// 	height[1][1] = 0.25;
// 	height[1][2] = 0.125;
// 	height[2][0] = 0.0625;
// 	height[2][1] = 0.125;
// 	height[2][2] = 0.0625;
// 	while(++i < 3)
// 	{
// 		j = -1;
// 		while(++j < 3)
// 		res += height[j][i] * pixel[get_pos(line + j, col + i, gtk)];
// 	}
// 	return (res);
// }

void	blur_effect(t_rgb *color, int col, int line, t_gtk *gtk)
{
	guchar	*pixel;
	// int		sum;
	int		j;
	int		i;
	// float	kernel[3][3];
	//
	// // (void)color;
	// kernel[0][0] = 0.0625;
	// kernel[0][1] = 0.125;
	// kernel[0][2] = 0.0625;
	// kernel[1][0] = 0.125;
	// kernel[1][1] = 0.25;
	// kernel[1][2] = 0.125;
	// kernel[2][0] = 0.0625;
	// kernel[2][1] = 0.125;
	// kernel[2][2] = 0.0625;
	float kernel[20][20] =
	{
	  {0.111, 0, 0, 0, 0, 0, 0, 0, 0},
	  {0, 0.111, 0, 0, 0, 0, 0, 0, 0},
	  {0, 0, 0.111, 0, 0, 0, 0, 0, 0},
	  {0, 0, 0, 0.111, 0, 0, 0, 0, 0},
	  {0, 0, 0, 0, 0.111, 0, 0, 0, 0},
	  {0, 0, 0, 0, 0, 0.111, 0, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0.111, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 0.111, 0},
	  {0, 0, 0, 0, 0, 0, 0, 0, 0.111}
	};


	j = -1;
	pixel = gdk_pixbuf_get_pixels(gtk->buffer);
	while (++j < 9)
	{
		i = -1;
		while (++i < 9)
		{
			color->red += kernel[j][i] * pixel[get_pos(line + j, col + i, gtk)];
			color->green += kernel[j][i] * pixel[get_pos(line + j, col + i, gtk)];
			color->blue += kernel[j][i] * pixel[get_pos(line + j, col + i, gtk)];
		}
	}
	pixel[get_pos(line, col, gtk)] = color->red > 255 ? 255 : color->red;
	pixel[get_pos(line, col, gtk) + 1] = color->green > 255 ? 255 : color->green;
	pixel[get_pos(line, col, gtk) + 2] = color->blue > 255 ? 255 : color->blue;


	gtk_image_set_from_pixbuf(GTK_IMAGE(gtk->img), gtk->buffer);
}

void	ft_pixel_put(int i, int j, t_rgb color, t_env e)
{
	if (e.gtk.nb_effect == 0)
		no_effect(&color, &e.gtk, i, j);
	else if(e.gtk.nb_effect == 1)
		sepia_effect(&color, &e.gtk, i, j);
	else if(e.gtk.nb_effect == 2)
		gray_scale_effect(&color, &e.gtk, i, j);
	else if (e.gtk.nb_effect == 3)
		sobel_effect(i, j, &e.gtk);
	else if (e.gtk.nb_effect == 4)
		cartoon_effect(&color, i, j, &e.gtk);
	else if (e.gtk.nb_effect == 5)
		blur_effect(&color, i, j, &e.gtk);
}
