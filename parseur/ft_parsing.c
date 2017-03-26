#include "../includes/parsing.h"


void		ft_puterror(char*str)
{
	ft_putendl(str);
	exit(0);
}

int			ft_verif_scene_object(char *str)
{
	if (str && (ft_strcmp(str, "scene")) == 0)
		return (1);
	if (str && (ft_strcmp(str, "object")) == 0)
		return (1);
	if (str && (ft_strcmp(str, "light")) == 0)
		return (1);
	if (str && (ft_strcmp(str, "camera")) == 0)
		return (1);
	if (str && (ft_strcmp(str, "source")) == 0)
		return (1);
	return(0);
}

static void 	ft_verif_source_exist(t_e *e, t_obj *obj)
{
	if (obj->tex.texture == 5 && e->source_exist == 0)
		ft_puterror("no source given");
}

t_list			*ft_parsing_obj(t_e *e)
{
	t_list	*list;
	t_obj 	obj;
	int 	i;

	i = 0;
	list = NULL;
	e->split = NULL;
	e->id_o = -1;
	while (e->file[i] && i < e->nbr_line)
	{
		if (e->file[i] && e->file[i][0] != '#')
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] && e->split[0][0] && (ft_strcmp(e->split[0], "object")) == 0)
			{
				e->id_o++;
				ft_putendl("\n----------------\n");
				obj = ft_parsing_obj_after(e, i);
				obj.id = e->id_o;
				// print_info_object(obj, e);
				ft_lstadd(&list, ft_lstnew(&obj, sizeof(t_obj)));
				i = e->line - 1;
				ft_verif_source_exist(e, &obj);
			}
		}
		i++;
	}
	return (list);
}


void		ft_parsing_scene(t_env *rt, t_e *p)
{
	int 	i;

	i = 0;
	p->line = 0;
	p->split = NULL;
	p->nb_scene = 0;
	while (p->file[i] && i < p->nbr_line)
	{
		if (p->file[i] && p->file[i][0] != '#')
		{
			p->split = ft_strsplit(p->file[i], '\t');
			if (p->split[0] && p->split[0][0]
				&& (ft_strcmp(p->split[0], "scene")) == 0 && p->nb_scene == 0)
			{
				p->nb_scene++;
				ft_parsing_scene_after(rt, p, i);
				i = p->line - 1;
			}
			else if (p->split[0] && p->split[0][0]
				&& (ft_strcmp(p->split[0], "scene")) == 0 && p->nb_scene == 1)
				ft_puterror("Too much given scene");
		}
		i++;
	}
}



void		ft_parsing_camera(t_env *rt, t_e *e)
{
	int 	i;

	i = 0;
	e->line = 0;
	e->split = NULL;
	e->nb_camera = 0;
	while (e->file[i] && i < e->nbr_line)
	{
		if (e->file[i] && e->file[i][0] != '#')
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] && e->split[0][0]
				&& (ft_strcmp(e->split[0], "camera")) == 0 && e->nb_camera == 0)
			{
				e->nb_camera++;
				ft_parsing_camera_after(rt, e, i);
				i = e->line - 1;
			}
			else if (e->split[0] && e->split[0][0]
				&& (ft_strcmp(e->split[0], "camera")) == 0 && e->nb_camera == 1)
				ft_puterror("Too much given camera");
		}
		i++;
	}
	if (e->nb_camera != 1)
		ft_puterror("Too much given camera");
}
























t_list		*ft_parsing_light(t_e *e)
{
	t_list	*list;
	t_obj 	obj;
	int 	i;

	i = 0;
	e->split = NULL;
	e->id_l = -1;
	list = NULL;
	while (e->file[i] && i < e->nbr_line)
	{
		if (e->file[i] && e->file[i][0] != '#')
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] && e->split[0][0] && (ft_strcmp(e->split[0], "light")) == 0)
			{
				e->id_l++;
				obj = ft_parsing_lum(e, i);
				obj.id = e->id_l;
				ft_lstadd(&list, ft_lstnew(&obj, sizeof(t_obj)));
				i = e->line - 1;
			}
		}
		i++;
	}
	return (list);
}
