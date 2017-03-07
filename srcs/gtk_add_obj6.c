/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:14:08 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/07 17:23:45 by jichen-m         ###   ########.fr       */
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

int	put_info_tex(t_gtk *gtk, t_tex *tex)
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

int		put_tex_obj(t_gtk *gtk, t_tex *tex)
{
	int active;

	active = gtk_combo_box_get_active(GTK_COMBO_BOX(gtk->c_tex));
	if (active > -1)
	{
		if (active == 0)
			tex->texture = 0;
		else if (active == 1 || active == 2 || active == 3 || active == 4)
		{
			tex->texture = active == 1 ? 1 : ((active == 2) ? 2 :
			((active == 3) ? 3 : 4));
			if (put_info_tex(gtk, tex) == 1)
				return (1);
		}
	}
	else
		tex->texture = 0;
	return (0);
}

void	put_normal(t_vec3d *normal)
{
	normal->x = -1;
	normal->y = 0;
	normal->z = 0;
	normal->w = 1;
}

void 	put_id_ob(t_list *obj, int *i)
{
	int		j;
	t_obj *tmp_obj;
	t_list *tmp;

	j = 0;
	tmp = obj;
	while (tmp != NULL)
	{
		tmp_obj = (t_obj *)tmp->content;
		if (j <= tmp_obj->id)
			j = tmp_obj->id;
		tmp = tmp->next;
	}
	// printf("%d\n",j );
	*i = j + 1;
}

int		put_name_obj(t_gtk *gtk, const char **name, t_list *obj, int *i)
{
	t_list	*tmp;
	t_obj	*tmp_obj;

	tmp = obj;
	*name = ft_strdup(gtk_entry_get_text(GTK_ENTRY(gtk->e_nobj)));
	if (name[0][0] == 0)
	{
		g_print("Plis put a name\n");
		return (1);
	}
	while (tmp != NULL)
	{
		tmp_obj = (t_obj *)tmp->content;
		if (ft_strcmp(*name, tmp_obj->name) == 0)
		{
			g_print("Already exist name, plis choose another one\n");
			return (1);
		}
		tmp = tmp->next;
	}
	put_id_ob(obj, i);
	return (0);
}
