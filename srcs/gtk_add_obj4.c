/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_options5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:06:23 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/01 17:42:06 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		put_scale_obj(t_gtk *gtk, t_vec3d *scale)
{
	const char *scalex;
	const char *scaley;
	const char *scalez;

	scalex = gtk_entry_get_text(GTK_ENTRY(gtk->e_scalex));
	scaley = gtk_entry_get_text(GTK_ENTRY(gtk->e_scaley));
	scalez = gtk_entry_get_text(GTK_ENTRY(gtk->e_scalez));
	if ((check_if_digit(scalex)) == 1 || (check_if_digit(scaley)) == 1 ||
	(check_if_digit(scalez)) == 1)
	{
		g_print("Put the right scale\n");
		return (1);
	}
	scale->x = (float)ft_atoi(scalex);
	scale->y = (float)ft_atoi(scaley);
	scale->z = (float)ft_atoi(scalez);
	scale->w = 1;
	return (0);
}

int		put_rotation_obj(t_gtk *gtk, t_vec3d *rot)
{
	const char *rotx;
	const char *roty;
	const char *rotz;

	rotx = gtk_entry_get_text(GTK_ENTRY(gtk->e_rotx));
	roty = gtk_entry_get_text(GTK_ENTRY(gtk->e_roty));
	rotz = gtk_entry_get_text(GTK_ENTRY(gtk->e_rotz));
	if ((check_if_digit(rotx)) == 1 || (check_if_digit(roty)) == 1 ||
	(check_if_digit(rotz)) == 1)
	{
		g_print("Put the right rotation\n");
		return (1);
	}
	rot->x = (float)ft_atoi(rotx);
	rot->y = (float)ft_atoi(roty);
	rot->z = (float)ft_atoi(rotz);
	rot->w = 1;
	return (0);
}

void	put_color_obj(t_gtk *gtk, t_color *color)
{
	gtk->color = NULL;
	gtk->color = malloc(sizeof(GdkRGBA));
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(gtk->e_color), gtk->color);
	// if (gtk->color == NULL)
	// {
	// 	g_print("Choose a color plis\n");
	// 	return (1);
	// }
	color->red = gtk->color->red;
	color->green = gtk->color->green;
	color->blue = gtk->color->blue;
}

int		put_shininess_obj(t_gtk *gtk, float *shine)
{
	const char *tmp_shi;

	tmp_shi = gtk_entry_get_text(GTK_ENTRY(gtk->e_shine));
	if (check_if_digit(tmp_shi) == 1)
	{
		g_print("Put the right shininess\n");
		return (1);
	}
	*shine = (float)ft_atoi(tmp_shi);
	return (0);
}

int		put_refraction_obj(t_gtk *gtk, float *refrac)
{
	const char *tmp_refrac;

	tmp_refrac = gtk_entry_get_text(GTK_ENTRY(gtk->e_refrac));
	if (check_if_digit(tmp_refrac) == 1)
	{
		g_print("Put the right refraction\n");
		return (1);
	}
	*refrac = (float)ft_atoi(tmp_refrac);
	return (0);
}
