/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:33:16 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:30:21 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		put_type_obj(t_gtk *gtk, char *type)
{
	int active;

	active = gtk_combo_box_get_active(GTK_COMBO_BOX(gtk->c_obj));
	if (active > -1)
	{
		if (active == 0)
			*type = 0;
		else if (active == 1)
			*type = 3;
		else if (active == 2)
			*type = 1;
		else if (active == 3)
			*type = 2;
		return (0);
	}
	else
		ft_putstr_fd("You didn't choose an Object\n", 2);
	return (1);
}

int		check_if_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ',' || str[i] == '.' ||
		str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i == 0)
		return (1);
	else if (str[i] == '\0')
		return (0);
	return (1);
}

int		put_pos_obj(t_gtk *gtk, t_vec3d *pos)
{
	const char *posx;
	const char *posy;
	const char *posz;

	posx = gtk_entry_get_text(GTK_ENTRY(gtk->e_posx));
	posy = gtk_entry_get_text(GTK_ENTRY(gtk->e_posy));
	posz = gtk_entry_get_text(GTK_ENTRY(gtk->e_posz));
	if ((check_if_digit(posx)) == 1 || (check_if_digit(posy)) == 1 ||
	(check_if_digit(posz)) == 1)
	{
		ft_putstr_fd("Put the right position\n", 2);
		return (1);
	}
	pos->x = stof(posx);
	pos->y = stof(posy);
	pos->z = stof(posz);
	pos->w = 1;
	return (0);
}

int		create_new_obj1(t_env *e, t_obj *new_obj)
{
	if (put_type_obj(&e->gtk, &new_obj->type) == 1 ||
		put_name_obj(&e->gtk, &new_obj->name, e->scene.obj,
		&new_obj->id) == 1 ||
		put_pos_obj(&e->gtk, &new_obj->transform.transl) == 1 ||
		put_scale_obj(&e->gtk, &new_obj->transform.scale) == 1 ||
		put_rotation_obj(&e->gtk, &new_obj->transform.rot) == 1 ||
		put_shininess_obj(&e->gtk, &new_obj->shininess) == 1 ||
		put_refraction_obj(&e->gtk, &new_obj->refr_index) == 1 ||
		put_amb_coe_obj(&e->gtk, &new_obj->ka) == 1 ||
		put_dif_coe_obj(&e->gtk, &new_obj->kd) == 1 ||
		put_spec_coe_obj(&e->gtk, &new_obj->ks) == 1 ||
		put_i_light_obj(&e->gtk, &new_obj->i) == 1 ||
		put_tr_obj(&e->gtk, &new_obj->t) == 1 ||
		put_tex_obj(&e->gtk, &new_obj->tex) == 1)
		return (1);
	return (0);
}

int		create_new_obj(t_env *e)
{
	t_obj	new_obj;

	if (create_new_obj1(e, &new_obj) == 1)
		return (1);
	if (new_obj.type == 2)
		put_normal(&new_obj.normal);
	put_color_obj(&e->gtk, &new_obj.color);
	ft_lstaddend(&e->scene.obj, ft_lstnew(&new_obj, sizeof(t_obj)));
	raytracing(e);
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
	return (0);
}
