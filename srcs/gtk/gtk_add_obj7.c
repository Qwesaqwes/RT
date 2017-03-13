/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:48:15 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 14:49:05 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_color_texture(GtkWidget *tex_color, GdkRGBA *color, t_color *c)
{
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(tex_color), color);
	c->red = color->red;
	c->green = color->green;
	c->blue = color->blue;
}

int		put_info_tex(t_gtk *gtk, t_tex *tex)
{
	gtk->color = NULL;
	gtk->color = malloc(sizeof(GdkRGBA));
	get_color_texture(gtk->e_che1, gtk->color, &tex->tex_col1);
	get_color_texture(gtk->e_che2, gtk->color, &tex->tex_col2);
	if (tex->texture == 1)
	{
		if ((check_if_digit(gtk_entry_get_text(GTK_ENTRY(gtk->e_square)))) == 1)
		{
			g_print("Put the right Size for the square\n");
			return (1);
		}
		tex->square = stof(gtk_entry_get_text(GTK_ENTRY(gtk->e_square)));
	}
	else
		get_color_texture(gtk->e_che3, gtk->color, &tex->tex_col3);
	g_free(gtk->color);
	return (0);
}
