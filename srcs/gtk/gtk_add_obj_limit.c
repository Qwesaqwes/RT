/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj_limit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:17:06 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 17:31:11 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		put_limit_zmin(GtkWidget *zmin, t_limit *limit)
{
	const char *tmp;

	tmp = gtk_entry_get_text(GTK_ENTRY(zmin));
	if (ft_strcmp(tmp, "X") == 0 || ft_strcmp(tmp, "x") == 0)
		limit->exist.z_min = 0;
	else
	{
		if (check_if_digit(tmp) == 1)
		{
			ft_putstr_fd("Put the right limit in z_min\n", 2);
			return (1);
		}
		limit->z_min = stof(tmp);
		limit->exist.z_min = 1;
	}
	return (0);
}

int		put_limit_ymax(GtkWidget *ymax, t_limit *limit)
{
	const char *tmp;

	tmp = gtk_entry_get_text(GTK_ENTRY(ymax));
	if (ft_strcmp(tmp, "X") == 0 || ft_strcmp(tmp, "x") == 0)
		limit->exist.y_max = 0;
	else
	{
		if (check_if_digit(tmp) == 1)
		{
			ft_putstr_fd("Put the right limit in y_max\n", 2);
			return (1);
		}
		limit->y_max = stof(tmp);
		limit->exist.y_max = 1;
	}
	return (0);
}

int		put_limit_ymin(GtkWidget *ymin, t_limit *limit)
{
	const char *tmp;

	tmp = gtk_entry_get_text(GTK_ENTRY(ymin));
	if (ft_strcmp(tmp, "X") == 0 || ft_strcmp(tmp, "x") == 0)
		limit->exist.y_min = 0;
	else
	{
		if (check_if_digit(tmp) == 1)
		{
			ft_putstr_fd("Put the right limit in y_min\n", 2);
			return (1);
		}
		limit->y_min = stof(tmp);
		limit->exist.y_min = 1;
	}
	return (0);
}

int		put_limit_xmax(GtkWidget *xmax, t_limit *limit)
{
	const char *tmp;

	tmp = gtk_entry_get_text(GTK_ENTRY(xmax));
	if (ft_strcmp(tmp, "X") == 0 || ft_strcmp(tmp, "x") == 0)
		limit->exist.x_max = 0;
	else
	{
		if (check_if_digit(tmp) == 1)
		{
			ft_putstr_fd("Put the right limit in x_max\n", 2);
			return (1);
		}
		limit->x_max = stof(tmp);
		limit->exist.x_max = 1;
	}
	return (0);
}

int		put_limit_obj(t_gtk *gtk, t_limit *limit)
{
	const char *tmp;

	tmp = gtk_entry_get_text(GTK_ENTRY(gtk->e_xmin));
	if (ft_strcmp(tmp, "X") == 0 || ft_strcmp(tmp, "x") == 0)
		limit->exist.x_min = 0;
	else
	{
		if (check_if_digit(tmp) == 1)
		{
			ft_putstr_fd("Put the right limit in x_min\n", 2);
			return (1);
		}
		limit->x_min = stof(tmp);
		limit->exist.x_min = 1;
	}
	if (put_limit_xmax(gtk->e_xmax, limit) == 1 ||
		put_limit_ymin(gtk->e_ymin, limit) == 1 ||
		put_limit_ymax(gtk->e_ymax, limit) == 1 ||
		put_limit_zmin(gtk->e_zmin, limit) == 1 ||
		put_limit_zmax(gtk->e_zmax, limit) == 1)
		return (1);
	return (0);
}
