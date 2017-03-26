#include "../includes/parsing.h"

static void			ft_verif_scene(t_e *e)
{
	e->vscene.ambiant_rgb = 0;
	e->vscene.refr_index = 0;
	e->vscene.background_rgb = 0;
	e->vscene.antialiasing = 0;
}

static void			ft_verif_nbr_scene(t_e *e)
{
	if (e->vscene.ambiant_rgb != 1)
		ft_puterror("Wrong Info Scene");
	if (e->vscene.refr_index != 1)
		ft_puterror("Wrong Info Scene1");
	if (e->vscene.background_rgb != 1)
		ft_puterror("Wrong Info Scene1");
	if (e->vscene.antialiasing != 1)
		ft_puterror("Wrong Info Scene1");
}

void				ft_next_fill_scene_2(t_scene *scene, t_e* e)
{
	if (ft_strcmp(e->split[0], "background_rgb") == 0  && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vscene.background_rgb++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror("Wrong Info in scene - background_red");
		scene->background.red = (e->tmp);
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror("Wrong Info in scene - background_green");
		scene->background.green = (e->tmp);
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror("Wrong Info in scene - background_blue");
		scene->background.blue = (e->tmp);
	}
	else
		ft_puterror("Wrong Info Scene");
}

void				ft_next_fill_scene_1(t_scene *scene, t_e* e)
{
	if (ft_strcmp(e->split[0], "ambiant_rgb") == 0  && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vscene.ambiant_rgb++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror("Wrong Info in scene - ambiant red");
		scene->ambiant.red = (e->tmp);
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror("Wrong Info in scene - ambiant green");
		scene->ambiant.green = (e->tmp);
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror("Wrong Info in scene - ambiant blue");
		scene->ambiant.blue = (e->tmp);
	}
	else if (ft_strcmp(e->split[0], "refr_index") == 0  && e->split[1] != NULL)
	{
		e->vscene.refr_index++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror("Wrong Info in scene - refr_index");
		scene->refr_index = (e->tmp);
	}
	else
		ft_next_fill_scene_2(scene, e);
}

void				ft_fill_info_scene(t_scene *scene, t_e *e)
{
	if (ft_strcmp(e->split[0], "refr_index") == 0  && e->split[1] != NULL)
	{
		e->vscene.refr_index++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror("Wrong Info in scene - refr_index");
		scene->refr_index = (e->tmp);
	}
	else if (ft_strcmp(e->split[0], "antialiasing") == 0  && e->split[1] != NULL)
	{
		e->vscene.antialiasing++;
		e->tmp = atoi(e->split[1]);
		if (e->tmp < 1 || e->tmp > 4)
			ft_puterror("Wrong Info in scene - antialiasing");
		scene->antialiasing = (e->tmp);
	}
	else
		ft_next_fill_scene_1(scene, e);
}

void				ft_parsing_scene_after(t_env *rt, t_e *e, int i)
{
	int 			verif;
	int 			j;

	verif = 0;
	i++;
	ft_verif_scene(e);
	e->split = NULL;
	while (i < e->nbr_line && i != -1 && verif == 0)
	{
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) == 0)
			{
				ft_fill_info_scene(&rt->scene, e);
				j = -1;
				while (e->split[++j])
					free(e->split[j]);
				free(e->split);
			}
			else if (ft_verif_scene_object(e->split[0]) == 1)
			{
				verif++;
				i = i - 2;
			}
		}
		i++;
	}
	e->line = i;
	ft_verif_nbr_scene(e);
}
