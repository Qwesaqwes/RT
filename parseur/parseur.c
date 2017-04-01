#include "../includes/parsing.h"

t_list			*ft_parseur(t_env *rt, t_e *e, int type)
{
	t_list *list;

	list = NULL;
	if (type == 1)
		ft_parsing_scene(rt, e);
	if (type == 5)
		ft_parsing_camera(rt, e);
	if (type == 2)
		list = ft_parsing_obj(e);
	if (type == 3)
		list = ft_parsing_light(e);
	return (list);
}

int 	ft_fill_parce(t_env *rt, char *name)
{
	t_e		e;
	t_env 	tmp;

	e.error = 0;
	e.name = name;
	ft_read_file(e.name, &e);
	if (e.error == 0)
		ft_parseur(&tmp, &e, 1);
	if (e.error == 0)
		ft_parseur(&tmp, &e, 5);
	if (e.error == 0)
		tmp.scene.obj = ft_parseur(rt, &e, 2);
	if (e.error == 0)
		tmp.scene.lum = ft_parseur(rt, &e, 3);
	if (e.error == 0)
	{
		rt->scene = tmp.scene;
		rt->camera = tmp.camera;
		rt->vp = tmp.vp;
		rt->scene.obj = tmp.scene.obj;
		rt->scene.lum = tmp.scene.lum;
	}
	return (e.error);
}
