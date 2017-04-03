#include "../includes/parsing.h"

static void		ft_fill_info_face(t_face *face, t_e *e)
{
	t_vertex	*vertex;


	if (ft_strcmp(e->split[0], "vertex") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
		vertex->coord.x = atof(e->split[1]);
		vertex->coord.y = atof(e->split[2]);
		vertex->coord.z = atof(e->split[3]);
		vertex->coord.w = 1;
		vertex->next = NULL;
		add_after_vertex(vertex, &face->vertex);
	}
	else if (ft_strcmp(e->split[0], "normal") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		face->normal.x = atof(e->split[1]);
		face->normal.y = atof(e->split[2]);
		face->normal.z = atof(e->split[3]);
		face->normal.w = 1;
	}
}

t_face		*ft_parsing_face_after(t_e *e, int i)
{
	int		j;
	int		k;
	t_face	*face;

	k = 0;
	face = (t_face*)ft_memalloc(sizeof(t_face));
	face->vertex = NULL;
	face->next = NULL;
	i++;
	while (i < e->nbr_line && k != -2)
	{
		e->line = i;
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] && (ft_strcmp(e->split[0], "vertex") == 0 || ft_strcmp(e->split[0], "normal") == 0))
				ft_fill_info_face(face, e);
			else
				k = -2;
			j = -1;
			if (k == 0 && e->split[0])
			{
				while (e->split[++j])
					free(e->split[j]);
				if (e->split)
					free(e->split);
			}
		}
			i++;
	}
	e->faceend = i - 1;
	return (face);
}