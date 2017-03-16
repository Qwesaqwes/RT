/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_modif_obj1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:19:34 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/16 19:18:47 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_normal(t_vec3d *normal, t_list *list, const char *object)
{
	t_list	*tmp;
	t_obj	*tmp_obj;

	tmp = list;
	while (tmp != NULL)
	{
		tmp_obj = (t_obj*)tmp->content;
		if (ft_strcmp(tmp_obj->name, object) == 0)
		{
			normal->x = tmp_obj->normal.x;
			normal->y = tmp_obj->normal.y;
			normal->z = tmp_obj->normal.z;
			normal->w = tmp_obj->normal.w;
			break ;
		}
		tmp = tmp->next;
	}
}

int		update_obj1(t_env *e, t_obj *new)
{
	if (put_name_obj(&e->gtk, &new->name, e->scene.obj, &new->id) == 1 ||
		put_pos_obj(&e->gtk, &new->transform.transl) == 1 ||
		put_scale_obj(&e->gtk, &new->transform.scale) == 1 ||
		put_rotation_obj(&e->gtk, &new->transform.rot) == 1 ||
		put_shininess_obj(&e->gtk, &new->shininess) == 1 ||
		put_refraction_obj(&e->gtk, &new->refr_index) == 1 ||
		put_amb_coe_obj(&e->gtk, &new->ka) == 1 ||
		put_dif_coe_obj(&e->gtk, &new->kd) == 1 ||
		put_spec_coe_obj(&e->gtk, &new->ks) == 1 ||
		put_i_light_obj(&e->gtk, &new->i) == 1 ||
		put_tr_obj(&e->gtk, &new->t) == 1)
		return (1);
	return (0);
}

int		update_obj(t_env *e, const char *object)
{
	t_obj	new_obj;

	get_type(&new_obj.type, e->scene.obj, object);
	if (new_obj.type == 2)
		get_normal(&new_obj.normal, e->scene.obj, object);
	if (put_tex_obj(&e->gtk, &new_obj.tex) == 1)
		return (1);
	if (new_obj.tex.texture == 0)
		get_texture_bump_map(&new_obj, object, e->scene.obj);
	ft_list_remove_if(&e->scene.obj, object, &ft_strcmp);
	if (update_obj1(e, &new_obj) == 1)
		return (1);
	put_color_obj(&e->gtk, &new_obj.color);
	ft_lstaddend(&e->scene.obj, ft_lstnew(&new_obj, sizeof(t_obj)));
	raytracing(e);
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
	return (0);
}

void	view_modif_obj1(t_env *e, int resp, GtkWidget *dialog, const char *ob)
{
	GtkWidget	*area;

	init_add_obj_l_e(&e->gtk, resp);
	init_add_obj_box(&e->gtk, resp);
	init_modif_obj_e(&e->gtk, ob, &e->scene.obj);
	put_label_inside_box(&e->gtk, resp);
	put_box_inside_gbox(&e->gtk, resp);
	area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	gtk_container_add(GTK_CONTAINER(area), e->gtk.obj_gbox);
}

int		view_modif_obj(int response, int clic_mod, t_env *e, GtkWidget *view)
{
	GtkWidget	*dialog;
	const char	*object;

	if (response == clic_mod)
	{
		gtk_widget_hide(view);
		dialog = gtk_dialog_new_with_buttons("Modif Object",
		GTK_WINDOW(e->gtk.window), GTK_DIALOG_MODAL, ("CANCEL"),
		GTK_RESPONSE_REJECT, ("OK"), GTK_RESPONSE_ACCEPT, NULL);
		object = get_selected_row(e, e->scene.obj);
		if (object == NULL)
		{
			g_print("No Object to Modif\n");
			gtk_widget_destroy(dialog);
			return (1);
		}
		view_modif_obj1(e, response, dialog, object);
		gtk_widget_show_all(dialog);
		if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
			update_obj(e, object);
		gtk_widget_destroy(dialog);
	}
	return (0);
}
