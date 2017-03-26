#include "../includes/parsing.h"

static void			ft_verif_lum(t_e *e)
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
}

static void			ft_verif_nbr_lum_v2(t_e *e)
{
	if (e->vobject.rotation_xyz != 1)
		ft_puterror("Wrong Info Light");
	if (e->vobject.k_ads != 1)
		ft_puterror("Wrong Info Light");
	if (e->vobject.i != 1)
		ft_puterror("Wrong Info Light");
	if (e->vobject.t != 1)
		ft_puterror("Wrong Info Light");
	if (e->vobject.shininess != 1)
		ft_puterror("Wrong Info Light");
}

static void			ft_verif_nbr_lum(t_e *e)
{
	if (e->vobject.name != 1)
		ft_puterror("Wrong Info Light");
	if (e->vobject.type != 1)
		ft_puterror("Wrong Info Light");
	if (e->vobject.color_rgb != 1)
		ft_puterror("Wrong Info Light");
	if (e->vobject.scale_xyz != 1)
		ft_puterror("Wrong Info Light");
	if (e->vobject.translate_xyz != 1)
		ft_puterror("Wrong Info Light");
	ft_verif_nbr_lum_v2(e);
}


t_obj				ft_parsing_lum(t_e *e, int i)
{
	int j;
	t_obj tmp;

	tmp.refr_index = 0.1;
	i++;
	ft_verif_lum(e);
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
	ft_verif_nbr_lum(e);
	return (tmp);
}
