#include "../includes/parsing.h"



void 			ft_search_source(t_e *e, int i)
{
	e->split = NULL;
	e->nbr_source = 0;
	while (e->file[i] && i < e->nbr_line)
	{
		if (e->file[i] && e->file[i][0] != '#')
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] && e->split[0][0] &&
				(ft_strcmp(e->split[0], "source")) == 0)
			{
				if (e->split[1])
				{
					e->source_jpeg = *ft_strsplit(e->split[1], ' ');
					e->nbr_source++;
				}
				else
					ft_puterror("Wrong info given in source");
			}
		}
		i++;
	}
	if (e->nbr_source != 1)
		ft_puterror("Too much given source");
}

t_list			*ft_parseur(t_env *rt, t_e *e, int type)
{
	t_list *list;

	(void)rt;
	list = NULL;
	if (type == 4)
		ft_search_source(e, 0);
	else if (type == 1)
		ft_parsing_scene(rt, e);
	else if (type == 5)
		ft_parsing_camera(rt, e);
	else if (type == 2)
		list = ft_parsing_obj(e);
	else if (type == 3)
		list = ft_parsing_light(e);
	return (list);
}

void 		ft_fill_parce(t_env *rt, char *name)
{
	t_e		e;
	e.name = name;
	ft_read_file(e.name, &e);
	ft_parseur(rt, &e, 1);
	ft_parseur(rt, &e, 4);
	ft_parseur(rt, &e, 5);
	rt->scene.obj = ft_parseur(rt, &e, 2);
	rt->scene.lum = ft_parseur(rt, &e, 3);
}
