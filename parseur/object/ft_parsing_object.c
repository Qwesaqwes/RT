#include "../includes/parsing.h"

static void			ft_verif_object(t_e *e)
{
	e->vobject.name = 0;
	e->vobject.type = 0;
	e->vobject.color_rgb = 0;
	e->vobject.scale_xyz = 0;
	e->vobject.translate_xyz = 0;
	e->vobject.rotation_xyz = 0;
	e->vobject.k_ads = 0;
	e->vobject.i = 0;
	e->vobject.t = 0;
	e->vobject.shininess = 0;
	e->vobject.refraction_index = 0;
	e->vobject.tex_texture = 0;
	e->vobject.tex_bump = 0;
	e->vobject.tex_transp = 0;
	e->vobject.map_buf = 0;
	e->vobject.bump_buf = 0;
	e->vobject.transp_buf = 0;
	e->vobject.square = 0;
	e->vobject.tex_col1 = 0;
	e->vobject.tex_col2 = 0;
	e->vobject.tex_col3 = 0;
	e->vobject.x_min = 0;
	e->vobject.x_max = 0;
	e->vobject.y_min = 0;
	e->vobject.y_max = 0;
	e->vobject.z_min = 0;
	e->vobject.z_max = 0;
	e->vobject.quadrics = 0;
}

static void 		ft_verif_object_texture_4(t_e *e, int i)
{
	if (e->vobject.tex_col1 != 1)
		ft_puterror(e, "Wrong Info Object - tex_col1");
	if (e->vobject.tex_col2 != 1)
		ft_puterror(e, "Wrong Info Object - tex_col2");
	if (e->vobject.tex_col3 != 1)
		ft_puterror(e, "Wrong Info Object - tex_col3");
	if (i == 1)
	{
		if (e->vobject.square != 1)
			ft_puterror(e, "Wrong Info Object - square");
	}
}

static void			ft_verif_nbr_object_v2(t_e *e, t_obj obj)
{
	if (e->vobject.rotation_xyz != 1)
		ft_puterror(e, "Wrong Info Object - rotation_xyz");
	if (e->vobject.k_ads != 1)
		ft_puterror(e, "Wrong Info Object - k_ads");
	if (e->vobject.i != 1)
		ft_puterror(e, "Wrong Info Object - i");
	if (e->vobject.t != 1)
		ft_puterror(e, "Wrong Info Object - t");
	if (e->vobject.shininess != 1)
		ft_puterror(e, "Wrong Info Object - shininess");
	if (e->vobject.refraction_index != 1)
		ft_puterror(e, "Wrong Info Object - refraction_index");
	if (e->vobject.tex_texture != 1 || e->vobject.tex_bump != 1 ||
		e->vobject.tex_transp != 1)
		ft_puterror(e, "Wrong Info Object - tex_texture");
	if (obj.tex.texture == 5 && e->vobject.map_buf != 1)
		ft_puterror(e, "Wrong Info Object - texture 5");
	if (obj.tex.bump == 1 && e->vobject.tex_bump != 1)
		ft_puterror(e, "Wrong Info Object - bump");
	if (obj.tex.transp == 1 && e->vobject.transp_buf != 1)
		ft_puterror(e, "Wrong Info Object - transp");
	if (obj.tex.texture >= 2 && obj.tex.texture <= 4)
		ft_verif_object_texture_4(e, 0);
	if (obj.tex.texture == 1)
		ft_verif_object_texture_4(e, 1);
}

static void			ft_verif_nbr_object(t_e *e, t_obj obj)
{
	if (e->vobject.name != 1)
		ft_puterror(e, "Wrong Info Object - name");
	if (e->vobject.type != 1)
		ft_puterror(e, "Wrong Info Object - type");
	if (e->vobject.color_rgb != 1)
		ft_puterror(e, "Wrong Info Object - color_rgb");
	if (e->vobject.scale_xyz != 1)
		ft_puterror(e, "Wrong Info Object - scale_xyz");
	if (e->vobject.translate_xyz != 1)
		ft_puterror(e, "Wrong Info Object - translate_xyz");
	ft_verif_nbr_object_v2(e, obj);
}

static void 		ft_verif_limit_exist(t_e *e, t_obj *tmp)
{
	if (e->vobject.x_min > 1 || e->vobject.x_max > 1 || e->vobject.y_min > 1
		|| e->vobject.y_max > 1 || e->vobject.z_min > 1 || e->vobject.z_max > 1)
		ft_puterror(e, "Wrong Info Object - Min Max");

	if (e->vobject.x_min == 1 && e->vobject.x_max == 1)
		if (tmp->limit.x_min >= tmp->limit.x_max)
			ft_puterror(e, "Wrong Info Object  x_min must to be less than x_max");
	if (e->vobject.y_min == 1 && e->vobject.y_max == 1)
		if (tmp->limit.y_min >= tmp->limit.y_max)
			ft_puterror(e, "Wrong Info Object 	y_min must to be less than y_max");
	if (e->vobject.z_min == 1 && e->vobject.z_max == 1)
		if (tmp->limit.z_min >= tmp->limit.z_max)
			ft_puterror(e, "Wrong Info Object  z_min must to be less than z_max");
	if (tmp->tex.bump == 1 && tmp->tex.transp == 1)
		tmp->refr_index = 1;
	if (tmp->type == 8 && e->vobject.quadrics != 1)
		ft_puterror(e, "Wrong Info Object - quadrics");
}

static void 		ft_fill_info_brut(t_obj *tmp)
{
	tmp->limit.exist.z_min = 0;
	tmp->limit.exist.z_max = 0;
	tmp->limit.exist.y_min = 0;
	tmp->limit.exist.y_max = 0;
	tmp->limit.exist.x_min = 0;
	tmp->limit.exist.x_max = 0;
	tmp->transform.scale.w = 1;
	tmp->transform.transl.w = 1;
	tmp->transform.rot.w = 1;
	tmp->normal.x = -1;
	tmp->normal.y = 0;
	tmp->normal.z = 0;
	tmp->normal.w = 1;
	tmp->faces = NULL;
}

t_obj				ft_parsing_obj_after(t_e *e, int i)
{
	int j;
	t_obj tmp;

	tmp.refr_index = 0.1;
	i++;
	ft_verif_object(e);
	ft_fill_info_brut(&tmp);
	e->texture_5 = 0;
	while (i < e->nbr_line && i != -1)
	{
		e->line = i;
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->save_i = i;
			e->split = ft_strsplit(e->file[i], '\t');
			e->faceend = i + 1;
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) ==  0)
			{
				ft_fill_info_object(&tmp, e);
				i = e->faceend - 1;
			}
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) !=  0)
				i = -2;
			j = -1;
			while (e->split && e->split[++j])
				free(e->split[j]);
			if (e->split)
				free(e->split);
		}
		i++;
	}
	ft_verif_nbr_object(e, tmp);
	ft_verif_limit_exist(e, &tmp);
	if (e->vobject.faces != 0 && tmp.faces != NULL)
		tmp.faces = face_cuting(tmp.faces);
	return (tmp);
}
