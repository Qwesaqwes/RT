#include "../includes/parsing.h"
// else
// 	ft_puterror(ft_strjoin("Wrong Info Object line ", ft_itoa(e->save_i + 1)));

void 		ft_fill_info_object_19(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "y_max") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.y_max = 1;
		e->vobject.y_max++;
		obj->limit.y_max = atof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "z_min") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.z_min = 1;
		e->vobject.z_min++;
		obj->limit.z_min = atof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "z_max") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.z_max = 1;
		e->vobject.z_max++;
		obj->limit.z_max = atof(e->split[1]);
	}
	else
		ft_puterror(e, ft_strjoin("Wrong Info Object line ", ft_itoa(e->save_i + 1)));
}

void 		ft_fill_info_object_18(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "x_min") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.x_min = 1;
		e->vobject.x_min++;
		obj->limit.x_min = atof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "x_max") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.x_max = 1;
		e->vobject.x_max++;
		obj->limit.x_max = atof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "y_min") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.y_min = 1;
		e->vobject.y_min++;
		obj->limit.y_min = atof(e->split[1]);
	}
	else
		ft_fill_info_object_19(obj, e);
}

void 		ft_fill_info_object_17(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "tex_bump") == 0 && e->split[1] != NULL)
	{
		e->vobject.tex_bump++;
		e->tmp = atoi(e->split[1]);
		if (e->tmp != 1 && e->tmp != 0)
			ft_puterror(e, "Wrong Info in Object - tex_bump");
		obj->tex.bump = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "tex_transp") == 0 && e->split[1] != NULL)
	{
		e->vobject.tex_transp++;
		e->tmp = atoi(e->split[1]);
		if (e->tmp != 1 && e->tmp != 0)
			ft_puterror(e, "Wrong Info in Object - tex_transp");
		obj->tex.transp = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "square") == 0 && e->split[1] != NULL)
	{
		e->vobject.square++;
		e->tmp = atof(e->split[1]);
		obj->tex.square = e->tmp;
	}
	else
		ft_fill_info_object_18(obj, e);
}

void 		ft_fill_info_object_16(t_obj *obj, t_e *e)
{
	int i;
	if (ft_strcmp(e->split[0], "bump_buf") == 0 && e->split[1] != NULL)
	{
		e->vobject.bump_buf++;
		e->file_name = e->split[1];
		if ((i = open(e->file_name, O_RDONLY)) < 0)
			ft_puterror(e, "error file given - bump_buf");
		if ((i = get_next_line(i, &e->tmpc)) < 0)
			ft_puterror(e, "error file given - bump_buf");
		close(i);
		obj->bump_buf = gray_scale(gdk_pixbuf_new_from_file(e->file_name, NULL));
	}
	else if (ft_strcmp(e->split[0], "transp_buf") == 0 && e->split[1] != NULL)
	{
		e->vobject.transp_buf++;
		e->file_name = e->split[1];
		if ((i = open(e->file_name, O_RDONLY)) < 0)
			ft_puterror(e, "error file given - transp_buf");
		if ((i = get_next_line(i, &e->tmpc)) < 0)
			ft_puterror(e, "error file given - bump_buf");
		close(i);
		obj->transp_buf = gray_scale(gdk_pixbuf_new_from_file(e->file_name, NULL));
	}
	else
		ft_fill_info_object_17(obj, e);
}

void 		ft_fill_info_object_14(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "tex_col3") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.tex_col3++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col3_red");
		obj->tex.tex_col3.red = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col3_green");
		obj->tex.tex_col3.green = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col3_blue");
		obj->tex.tex_col3.blue = e->tmp;
	}
	else
		ft_fill_info_object_16(obj, e);
}

void 		ft_fill_info_object_13(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "tex_col2") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.tex_col2++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col2_red");
		obj->tex.tex_col2.red = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col2_green");
		obj->tex.tex_col2.green = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col2_blue");
		obj->tex.tex_col2.blue = e->tmp;
	}
	else
		ft_fill_info_object_14(obj, e);
}

void 		ft_fill_info_object_12(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "tex_col1") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.tex_col1++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col1_red");
		obj->tex.tex_col1.red = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col1_green");
		obj->tex.tex_col1.green = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col1_blue");
		obj->tex.tex_col1.blue = e->tmp;
	}
	else
		ft_fill_info_object_13(obj, e);
}

void 		ft_fill_info_object_11(t_obj *obj, t_e *e)
{
	int i;

	if (ft_strcmp(e->split[0], "tex_texture") == 0 && e->split[1] != NULL)
	{
		e->vobject.tex_texture++;
		e->tmp = atoi(e->split[1]);
		if (e->tmp < 0 || e->tmp > 5)
			ft_puterror(e, "Wrong Info in Object - tex_texture");
		if (e->tmp == 5)
			e->texture_5++;
		obj->tex.texture = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "map_buf") == 0 && e->split[1] != NULL)
	{
		e->vobject.map_buf++;
		e->file_name = e->split[1];
		if ((i = open(e->file_name, O_RDONLY)) < 0)
			ft_puterror(e, "error file given - map_buf");
		if ((i = get_next_line(i, &e->tmpc)) < 0)
			ft_puterror(e, "error file given - bump_buf");
		obj->map_buf = gdk_pixbuf_new_from_file(e->file_name, NULL);
	}
	else
		ft_fill_info_object_12(obj, e);
}


void		ft_fill_info_object_10(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "shininess") == 0 && e->split[1] != NULL)
	{
		e->vobject.shininess++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0)
			ft_puterror(e, "Wrong Info in Object - shininess");
		obj->shininess = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "refraction_index") == 0 && e->split[1] != NULL)
	{
		e->vobject.refraction_index++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 1)
			ft_puterror(e, "Wrong Info in Object - refraction_index");
		obj->refr_index = e->tmp;
	}
	else
		ft_fill_info_object_11(obj, e);
}

void		ft_fill_info_object_9(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "i") == 0 && e->split[1] != NULL)
	{
		e->vobject.i++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - i");
		obj->i = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "t") == 0 && e->split[1] != NULL)
	{
		e->vobject.t++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - t");
		obj->t = e->tmp;
	}
	else
		ft_fill_info_object_10(obj, e);
}


void		ft_fill_info_object_7(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "k_ads") == 0 && e->split[1] != NULL && e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.k_ads++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - k_a");
		obj->ka = e->tmp;

		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - k_d");
		obj->kd = e->tmp;

		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - k_s");
		obj->ks = e->tmp;
	}
	else
		ft_fill_info_object_9(obj, e);
}

void		ft_fill_info_object_6(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "rotation_xyz") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.rotation_xyz++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Object - rotation_x");
		obj->transform.rot.x = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Object - rotation_y");
		obj->transform.rot.y = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Object - rotation_z");
		obj->transform.rot.z = e->tmp;
	}
	else
		ft_fill_info_object_7(obj, e);
}


void		ft_fill_info_object_4(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "translate_xyz") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.translate_xyz++;
		e->tmp = atof(e->split[1]);
		obj->transform.transl.x = e->tmp;
		e->tmp = atof(e->split[2]);
		obj->transform.transl.y = e->tmp;
		e->tmp = atof(e->split[3]);
		obj->transform.transl.z = e->tmp;
	}
	else
		ft_fill_info_object_6(obj, e);
}

void		ft_fill_info_object_3(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "scale") == 0 && e->split[1] != NULL)
	{
		e->vobject.scale_xyz++;
		e->tmp = atof(e->split[1]);
		if (e->tmp <= 0)
			ft_puterror(e, "Wrong Info in Object - scale");
		if (e->tmp > 1.8)
			e->tmp = 1.8;
		obj->transform.scale.x = e->tmp;
		obj->transform.scale.y = e->tmp;
		obj->transform.scale.z = e->tmp;
	}
	else
		ft_fill_info_object_4(obj, e);
}


void		ft_fill_info_object_2(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "color_rgb") == 0 && e->split[1] != NULL && e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.color_rgb++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - color_green");
		obj->color.red = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - color_blue");
		obj->color.green = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - color_red");
		obj->color.blue = (e->tmp);
	}
	else
		ft_fill_info_object_3(obj, e);
}

static char ft_verif_type(t_e *e, char *type)
{
	if (ft_strcmp(type, "sphere") == 0)
		return (0);
	else if (ft_strcmp(type, "cylindre") == 0)
		return (1);
	else if (ft_strcmp(type, "plane") == 0)
		return (2);
	else if (ft_strcmp(type, "cone") == 0)
		return (3);
	else if (ft_strcmp(type, "triangle") == 0)
		return (4);
	else if (ft_strcmp(type, "polygone") == 0)
		return (5);
	else if (ft_strcmp(type, "polygone") == 0)
		return (6);
	else if (ft_strcmp(type, "circle") == 0)
		return (7);
	ft_puterror(e, "Wrong Info Object - Type");
	return (0);
}

void		ft_fill_info_object(t_obj *obj, t_e *e)
{
	int i;

	e->tmp = 0;
	i = 0;
	if (ft_strcmp(e->split[0], "name") == 0 && e->split[1] != NULL)
	{
		e->vobject.name++;
		obj->name = *ft_strsplit(e->split[1], ' ');
	}
	else if (ft_strcmp(e->split[0], "type") == 0 && e->split[1] != NULL)
	{
		e->vobject.type++;
		obj->type = ft_verif_type(e, e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "face") == 0)
	{
		e->vobject.faces++;
		add_after_face(ft_parsing_face_after(e, e->faceend), &obj->faces);
	}
	else
		ft_fill_info_object_2(obj, e);
}
