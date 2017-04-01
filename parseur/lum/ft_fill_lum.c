#include "../includes/parsing.h"

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

static void		ft_fill_info_lum4(t_obj *obj, t_e *e)
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
		ft_puterror(e, ft_strjoin("Wrong Info Light line ",
		ft_itoa(e->save_i + 1)));
}

static void		ft_fill_info_lum3(t_obj *obj, t_e *e)
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
		ft_fill_info_lum4(obj, e);
}

static void		ft_fill_info_lum2(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "color_rgb") == 0 && e->split[1] != NULL && e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.color_rgb++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Light - color_green");
		obj->color.red = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Light - color_blue");
		obj->color.green = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Light - color_red");
		obj->color.blue = (e->tmp);
	}
	else
		ft_fill_info_lum3(obj, e);
}


void		ft_fill_info_lum(t_obj *obj, t_e *e)
{
	e->tmp = 0;
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
	else if (ft_strcmp(e->split[0], "scale") == 0 && e->split[1] != NULL)
	{
		e->vobject.scale_xyz++;
		e->tmp = atof(e->split[1]);
		if (e->tmp <= 0)
			ft_puterror(e, "Wrong Info in Light - scale");
		if (e->tmp > 1.8)
			e->tmp = 1.8;
		obj->transform.scale.x = e->tmp;
		obj->transform.scale.y = e->tmp;
		obj->transform.scale.z = e->tmp;
	}
	else
		ft_fill_info_lum2(obj, e);
}
