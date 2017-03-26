#include "../includes/parsing.h"

void 			ft_search_source(t_e *e, int i)
{
	e->split = NULL;
	e->nbr_source = 0;
	e->source_exist = 0;
	e->source_jpeg = NULL;
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
					e->source_exist++;
					e->nbr_source++;
				}
				else
					ft_puterror("Wrong info given in source");
			}
		}
		i++;
	}
}
