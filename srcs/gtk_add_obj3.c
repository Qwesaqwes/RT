/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:33:16 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/18 16:40:26 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

int		put_type_obj(t_gtk *gtk, char *type)
{
	int active;

	active = gtk_combo_box_get_active(GTK_COMBO_BOX(gtk->c_obj));
	if (active > -1)
	{
		if (active == 0) 			//selected type of object "Sphere"
			*type = 0;
		else if (active == 1)	//selected type of object "Cone"
			*type = 3;
		else if (active == 2)		//selected type of object "Cylindre"
			*type = 1;
		else if (active == 3)		//selected type of object "Plan"
			*type = 2;
		return (0);
	}
	else
		g_print("You didn't choose an Object\n");
	return (1);
}

int 	check_if_digit(const char * str)
{
	int	i;

	i = 0;
	while(str[i] == ',' || str[i] == '.' ||
		str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i == 0)
		return (1);
	else if (str[i] == '\0')
		return (0);
	return (1);
}

int 	put_pos_obj(t_gtk *gtk, t_vec3d *pos)
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
		g_print("Put the right position\n");
		return (1);
	}
	pos->x = stof(posx);
	pos->y = stof(posy);
	pos->z = stof(posz);
	pos->w = 1;
	return (0);
}

int		create_new_obj(int response, int clicked_ok, t_env *e)
{
	t_obj	new_obj;

	if (response == clicked_ok)
	{
		if (
			put_type_obj(&e->gtk, &new_obj.type) == 1 ||
			put_name_obj(&e->gtk, &new_obj.name, e->scene.obj,
			&new_obj.id) == 1 ||
			put_pos_obj(&e->gtk, &new_obj.transform.transl) == 1 ||
			put_scale_obj(&e->gtk, &new_obj.transform.scale) == 1 ||
			put_rotation_obj(&e->gtk, &new_obj.transform.rot) == 1 ||
			put_shininess_obj(&e->gtk, &new_obj.shininess) == 1 ||
			put_refraction_obj(&e->gtk, &new_obj.refr_index) == 1 ||
			put_amb_coe_obj(&e->gtk, &new_obj.ka) == 1 ||
			put_dif_coe_obj(&e->gtk, &new_obj.kd) == 1 ||
			put_spec_coe_obj(&e->gtk, &new_obj.ks) == 1 ||
			put_i_light_obj(&e->gtk, &new_obj.i) == 1 ||
			put_tr_obj(&e->gtk, &new_obj.t) == 1)
			return (1); //error
		put_color_obj(&e->gtk, &new_obj.color);
		ft_lstaddend(&e->scene.obj, ft_lstnew(&new_obj, sizeof(t_obj)));
		raytracing(e);
		gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
		// t_obj *tmp_obj;
		// t_list *tmp;
		//
		// tmp = e->scene.obj;
		// while (tmp != NULL)
		// {
		// 	tmp_obj = (t_obj *)tmp->content;
		// 	// printf("%d\n", tmp_obj->id);
		// 	printf("%s\n", tmp_obj->name);
		// 	tmp = tmp->next;
		// 	// printf("%d\n", j);
		// }
	}
	else
	{
		//free color and stuff
		g_print("the CANCEL was pressed\n");
	}
	return (0);
}
