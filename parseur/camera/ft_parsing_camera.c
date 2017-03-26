#include "../includes/parsing.h"

static void			ft_verif_camera(t_e *e)
{
	e->vcamera.origin_xyz = 0;
	e->vcamera.rotation_xyz = 0;
	e->vcamera.distance_viewplane = 0;

}

static void			ft_verif_nbr_camera(t_e *e)
{
	if (e->vcamera.origin_xyz != 1)
		ft_puterror("Wrong Info Camera - origin_xyz");
	if (e->vcamera.rotation_xyz != 1)
		ft_puterror("Wrong Info Camera - rotation_xyz");
	if (e->vcamera.distance_viewplane != 1)
		ft_puterror("Wrong Info Camera - distance_camera");
}

static void 		ft_fill_info_brut(t_env *rt)
{
	rt->camera.baseU.x = 1;
	rt->camera.baseU.y = 0;
	rt->camera.baseU.z = 0;
	rt->camera.baseU.w = 1;
	rt->camera.baseV.x = 0;
	rt->camera.baseV.y = 1;
	rt->camera.baseV.z = 0;
	rt->camera.baseV.w = 1;
	rt->camera.baseW.x = 0;
	rt->camera.baseW.y = 0;
	rt->camera.baseW.z = 1;
	rt->camera.baseW.w = 1;
	rt->camera.origin.z = 1;
	rt->camera.rot.w = 1;
}

void 				ft_fill_info_camera(t_env *rt, t_e *e)
{
	if (ft_strcmp(e->split[0], "origin_xyz") == 0  && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		if (e->split[4] != NULL)
			ft_puterror("Wrong Info in Camera - origin_xyz");
		e->vcamera.origin_xyz++;
		e->tmp = atof(e->split[1]);
		rt->camera.origin.x = (e->tmp);
		e->tmp = atof(e->split[2]);
		rt->camera.origin.y = (e->tmp);
		e->tmp = atof(e->split[3]);
		rt->camera.origin.z = (e->tmp);
	}
	else if (ft_strcmp(e->split[0], "rotation_xyz") == 0  && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		if (e->split[4] != NULL)
			ft_puterror("Wrong Info in Camera - rotation_xyz");
		e->vcamera.rotation_xyz++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror("Wrong Info in Camera - rotation_x");
		rt->camera.rot.x = (e->tmp);
		e->tmp = atof(e->split[2]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror("Wrong Info in Camera - rotation_y");
		rt->camera.rot.y = (e->tmp);
		e->tmp = atof(e->split[3]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror("Wrong Info in Camera - rotation_z");
		rt->camera.rot.z = (e->tmp);
	}
	else if (ft_strcmp(e->split[0], "distance_viewplane") == 0
		&& e->split[1] != NULL)
	{
		e->vcamera.distance_viewplane++;
		e->tmp = atof(e->split[1]);
		if (e->tmp <= 0)
			ft_puterror("Wrong Info in Camera - distance_viewplane");
		rt->vp.dist = (e->tmp);
		rt->vp.width = 1;
		rt->vp.height = (float)H / (float)W;
	}
}


void 				ft_parsing_camera_after(t_env *rt, t_e *e, int i)
{
	int 			verif;
	int 			j;

	verif = 0;
	i++;
	ft_verif_camera(e);
	ft_fill_info_brut(rt);
	e->split = NULL;
	while (i < e->nbr_line && i != -1 && verif == 0)
	{
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) == 0)
			{
				ft_fill_info_camera(rt, e);
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
	ft_verif_nbr_camera(e);
}
