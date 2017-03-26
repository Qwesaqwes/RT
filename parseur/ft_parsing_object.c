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
	e->vobject.x_min = 0;
	e->vobject.x_max = 0;
	e->vobject.y_min = 0;
	e->vobject.y_max = 0;
	e->vobject.z_min = 0;
	e->vobject.z_max = 0;
}

static void 		ft_verif_object_texture_4(t_e *e, int i)
{
	if (e->vobject.tex_col1 != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.tex_col2 != 1)
		ft_puterror("Wrong Info Object");
	if (i == 1)
	{
		if (e->vobject.square != 1)
			ft_puterror("Wrong Info Object");
	}
}

static void			ft_verif_nbr_object_v2(t_e *e, t_obj obj)
{
	if (e->vobject.rotation_xyz != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.k_ads != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.i != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.t != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.shininess != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.refraction_index != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.tex_texture != 1 || e->vobject.tex_bump != 1 || e->vobject.tex_transp != 1)
		ft_puterror("Wrong Info Object");
	if (obj.tex.texture == 5 && e->vobject.map_buf != 1)
		ft_puterror("Wrong Info Object");
	if (obj.tex.bump == 1 && e->vobject.tex_bump != 1)
		ft_puterror("Wrong Info Object");
	if (obj.tex.transp == 1 && e->vobject.transp_buf != 1)
		ft_puterror("Wrong Info Object");

	if (obj.tex.texture >= 2 && obj.tex.texture <= 4)
		ft_verif_object_texture_4(e, 0);
	if (obj.tex.texture == 1)
		ft_verif_object_texture_4(e, 1);


}

static void			ft_verif_nbr_object(t_e *e, t_obj obj)
{
	if (e->vobject.name != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.type != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.color_rgb != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.scale_xyz != 1)
		ft_puterror("Wrong Info Object");
	if (e->vobject.translate_xyz != 1)
		ft_puterror("Wrong Info Object_");
	ft_verif_nbr_object_v2(e, obj);
}

void 		print_info_object(t_obj obj, t_e *e)
{
	printf("id  ---->\t\t%d\n", obj.id);
	printf("name  ---->\t\t%s\n", obj.name);
	printf("scale x ---->\t\t%f\n", obj.transform.scale.x);
	printf("scale y ---->\t\t%f\n", obj.transform.scale.y);
	printf("scale z ---->\t\t%f\n", obj.transform.scale.z);
	printf("scale w ---->\t\t%f\n", obj.transform.scale.w);
	printf("type ---->\t\t%c\n", obj.type);
	printf("transl x ---->\t\t%f\n", obj.transform.transl.x);
	printf("transl y ---->\t\t%f\n", obj.transform.transl.y);
	printf("transl z ---->\t\t%f\n", obj.transform.transl.z);
	printf("transl w ---->\t\t%f\n", obj.transform.transl.w);
	printf("rot x ---->\t\t%f\n", obj.transform.rot.x);
	printf("rot y ---->\t\t%f\n", obj.transform.rot.y);
	printf("rot z ---->\t\t%f\n", obj.transform.rot.z);
	printf("rot w ---->\t\t%f\n", obj.transform.rot.w);
	printf("color r ---->\t\t%f\n", obj.color.red);
	printf("color g ---->\t\t%f\n", obj.color.green);
	printf("color b ---->\t\t%f\n", obj.color.blue);
	printf("ka---->\t\t\t%f\n", obj.ka);
	printf("kd ---->\t\t%f\n", obj.kd);
	printf("ks ---->\t\t%f\n", obj.ks);
	printf("i ---->\t\t\t%f\n", obj.i);
	printf("t ---->\t\t\t%f\n", obj.t);
	printf("shininess ---->\t\t%f\n", obj.shininess);
	printf("refr_index ---->\t%f\n", obj.refr_index);
	printf("tex.texture ---->\t%d\n", obj.tex.texture);
	if (obj.tex.texture == 5)
		printf("tex.texture ---->\t%s\n", e->file_name);
	if (obj.tex.texture == 4)
	{
		printf("tex_tex_col1_red ---->\t%f\n", obj.tex.tex_col1.red);
		printf("tex_tex_col1_green --->\t%f\n", obj.tex.tex_col1.green);
		printf("tex_tex_col1_blue --->\t%f\n", obj.tex.tex_col1.blue);
		printf("tex_tex_col2_red --->\t%f\n", obj.tex.tex_col2.red);
		printf("tex_tex_col2_green --->\t%f\n", obj.tex.tex_col2.green);
		printf("tex_tex_col2_blue --->\t%f\n", obj.tex.tex_col2.blue);
		printf("tex_tex_col3_red --->\t%f\n", obj.tex.tex_col3.red);
		printf("tex_tex_col3_green --->\t%f\n", obj.tex.tex_col3.green);
		printf("tex_tex_col3_blue --->\t%f\n", obj.tex.tex_col3.blue);
	}
	ft_putendl("\n");
}

static void 		ft_verif_limit_exist(t_e *e, t_obj *tmp)
{
	if (e->vobject.x_min > 1 || e->vobject.x_max > 1 || e->vobject.y_min > 1
		|| e->vobject.y_max > 1 || e->vobject.z_min > 1 || e->vobject.z_max > 1)
		ft_puterror("Wrong Info Object");

	if (e->vobject.x_min == 1 && e->vobject.x_max == 1)
		if (tmp->limit.x_min >= tmp->limit.x_max)
			ft_puterror("Wrong Info Object  x_min must to be less than x_max");
	if (e->vobject.y_min == 1 && e->vobject.y_max == 1)
		if (tmp->limit.y_min >= tmp->limit.y_max)
			ft_puterror("Wrong Info Object 	y_min must to be less than y_max");
	if (e->vobject.z_min == 1 && e->vobject.z_max == 1)
		if (tmp->limit.z_min >= tmp->limit.z_max)
			ft_puterror("Wrong Info Object  z_min must to be less than z_max");
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
}

t_obj				ft_parsing_obj_after(t_e *e, int i)
{
	int j;
	t_obj tmp;

	tmp.refr_index = 0.1;
	i++;
	ft_verif_object(e);
	ft_fill_info_brut(&tmp);
	while (i < e->nbr_line && i != -1)
	{
		e->line = i;
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->save_i = i;
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) ==  0)
				ft_fill_info_object(&tmp, e);
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) !=  0)
				i = -2;
			j = -1;
			while (e->split[++j])
				free(e->split[j]);
			free(e->split);
		}
		i++;
	}
	ft_verif_nbr_object(e, tmp);
	ft_verif_limit_exist(e, &tmp);
	return (tmp);
}
