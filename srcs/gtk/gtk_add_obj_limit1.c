/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gkt_add_obj_limit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 17:15:02 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 17:16:30 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		put_limit_zmax(GtkWidget *zmax, t_limit *limit)
{
	const char *tmp;

	tmp = gtk_entry_get_text(GTK_ENTRY(zmax));
	if (ft_strcmp(tmp, "X") == 0 || ft_strcmp(tmp, "x") == 0)
		limit->exist.z_max = 0;
	else
	{
		if (check_if_digit(tmp) == 1)
		{
			ft_putstr_fd("Put the right limit in z_max\n", 2);
			return (1);
		}
		limit->z_max = stof(tmp);
		limit->exist.z_max = 1;
	}
	return (0);
}
