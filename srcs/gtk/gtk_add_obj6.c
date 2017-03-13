/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:14:08 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 16:01:38 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
			if (active == 1 || active == 2)
				tex->texture = active == 1 ? 1 : 2;
			else if (active == 3 || active == 4)
				tex->texture = active == 3 ? 3 : 4;
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

void	put_id_ob(t_list *obj, int *i)
{
	int		j;
	t_obj	*tmp_obj;
	t_list	*tmp;

	j = 0;
	tmp = obj;
	while (tmp != NULL)
	{
		tmp_obj = (t_obj *)tmp->content;
		if (j <= tmp_obj->id)
			j = tmp_obj->id;
		tmp = tmp->next;
	}
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
