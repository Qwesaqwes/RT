/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbcells.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 07:38:08 by opandolf          #+#    #+#             */
/*   Updated: 2015/12/22 07:38:12 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nbcells(char const *s, char c)
{
	int				nb_cells;
	unsigned int	i;

	if (c == '\0')
		return (2);
	nb_cells = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0)
		{
			if (s[i] != c)
				nb_cells++;
		}
		else
		{
			if (s[i] != c && s[i - 1] == c)
				nb_cells++;
		}
		i++;
	}
	nb_cells++;
	return (nb_cells);
}