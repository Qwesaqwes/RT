#include "../includes/parsing.h"

int		ft_verif_line(char *str, int x)
{
	while (str[++x])
		if (str[x] == '#')
			return (1);
	return (0);
}

void	ft_change_space(t_e *e)
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

void			ft_read_file(char *file, t_e *e)
{
	int i;
	int res;
	char *line;
	int fd1;
	int fd2;

	if ((fd1 = open(file, O_RDONLY)) < 0)
		ft_puterror("error file given");
	res = 0;
	e->nbr_line = 0;
	while ((res = get_next_line(fd1, &line)) > 0)
	{
		e->nbr_line++;
		free(line);
	}
	free(line);
	if (e->nbr_line >= 1)
		e->file = (char **)ft_memalloc(sizeof(char *) * e->nbr_line);
	if ((fd2 = open(file, O_RDONLY)) < 0)
		ft_puterror("error file given");
	close(fd1);
	i = -1;
	while ((res = get_next_line(fd2, &line)) > 0)
		e->file[++i] = line;
	if (res == -1)
		ft_putendl("error gnl");
	ft_change_space(e);
}

void	ft_print_xx(char **tab)
{
	int y;

	y = -1;
	while (tab[++y])
	{
		ft_putnbr(y);ft_putchar(' ');
		ft_putendl(tab[y]);
	}
}
