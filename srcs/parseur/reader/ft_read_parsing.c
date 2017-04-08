/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:56:49 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 22:56:56 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int		ft_verif_line(char *str, int x)
{
	while (str[++x])
		if (str[x] == '#')
			return (1);
	return (0);
}

static void		ft_change_space(t_e *e)
{
	int y;
	int x;

	y = -1;
	while (e->file[++y] && y < e->nbr_line)
	{
		if (ft_verif_line(e->file[y], -1) == 0)
		{
			x = -1;
			while (e->file[y][++x])
				if (e->file[y][x] == ' ')
					e->file[y][x] = '\t';
		}
	}
}

void			ft_read_file_2(t_e *e)
{
	int			i;
	char		*line;
	int			res;

	close(e->fd1);
	i = -1;
	while (e->file && (res = get_next_line(e->fd2, &line)) > 0 &&
		e->error == 0)
		e->file[++i] = line;
	if (res == -1)
		ft_puterror(e, "error gnl/fichier inexistant ou pas les droits");
	if (e->error == 0)
		ft_change_space(e);
}

int				ft_read_file(char *file, t_e *e)
{
	int			res;
	char		*line;

	if ((e->fd1 = open(file, O_RDONLY)) < 0)
		ft_puterror(e, "error file given");
	res = 0;
	e->nbr_line = 0;
	while ((res = get_next_line(e->fd1, &line)) > 0 && e->error == 0)
	{
		e->nbr_line++;
		if (res == 1)
			free(line);
	}
	if (res == -1 || (res == 0 && e->nbr_line == 0))
		ft_puterror(e, "error file void");
	if (e->nbr_line >= 1 && e->error == 0)
		e->file = (char **)ft_memalloc(sizeof(char *) * e->nbr_line);
	if (e->file && (e->fd2 = open(file, O_RDONLY)) < 0)
		ft_puterror(e, "error file given");
	ft_read_file_2(e);
	if (e->error == 0)
		return (0);
	return (1);
}
