#include "../includes/parsing.h"

t_list			*ft_parseur(t_env *rt, t_e *e, int type)
{
	t_list *list;

	(void)rt;
	list = NULL;
	if (type == 4)
		ft_search_source(e, 0);
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

static void 		verif_info_file(t_e *e)
{
	if (e->texture_5 > 0)
	{
		if (e->source_exist > 1)
			ft_puterror("Wrong info, do many source given");
		if (e->source_exist == 0)
			ft_puterror("Wrong info, no source given");
	}
}


void 		ft_fill_parce(t_env *rt, char *name)
{
	t_e		e;
	e.name = name;
	ft_read_file(e.name, &e);
	ft_parseur(rt, &e, 1);
	ft_putendl("vas");
	ft_parseur(rt, &e, 4);
	ft_putendl("vas");
	ft_parseur(rt, &e, 5);
	ft_putendl("vas");
	rt->scene.obj = ft_parseur(rt, &e, 2);
	ft_putendl("vas");
	rt->scene.lum = ft_parseur(rt, &e, 3);
	ft_putendl("vas");
	verif_info_file(&e);
}
