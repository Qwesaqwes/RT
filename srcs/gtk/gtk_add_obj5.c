/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:42:21 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:27:37 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		put_amb_coe_obj(t_gtk *gtk, float *ka)
{
	const char *tmp_ka;

	tmp_ka = gtk_entry_get_text(GTK_ENTRY(gtk->e_ka));
	if (check_if_digit(tmp_ka) == 1)
	{
		ft_putstr_fd("Put the right ambient coefficient\n", 2);
		return (1);
	}
	*ka = stof(tmp_ka);
	return (0);
}

int		put_dif_coe_obj(t_gtk *gtk, float *kd)
{
	const char *tmp_kd;

	tmp_kd = gtk_entry_get_text(GTK_ENTRY(gtk->e_kd));
	if (check_if_digit(tmp_kd) == 1)
	{
		ft_putstr_fd("Put the right diffuse coefficient\n", 2);
		return (1);
	}
	*kd = stof(tmp_kd);
	return (0);
}

int		put_spec_coe_obj(t_gtk *gtk, float *ks)
{
	const char *tmp_ks;

	tmp_ks = gtk_entry_get_text(GTK_ENTRY(gtk->e_ks));
	if (check_if_digit(tmp_ks) == 1)
	{
		ft_putstr_fd("Put the right specular coefficient\n", 2);
		return (1);
	}
	*ks = stof(tmp_ks);
	return (0);
}

int		put_i_light_obj(t_gtk *gtk, float *i)
{
	const char *tmp_i;

	tmp_i = gtk_entry_get_text(GTK_ENTRY(gtk->e_i));
	if (check_if_digit(tmp_i) == 1)
	{
		ft_putstr_fd("Put the right Intensity of light\n", 2);
		return (1);
	}
	*i = stof(tmp_i);
	return (0);
}

int		put_tr_obj(t_gtk *gtk, float *tr)
{
	const char *tmp_tr;

	tmp_tr = gtk_entry_get_text(GTK_ENTRY(gtk->e_tr));
	if (check_if_digit(tmp_tr) == 1)
	{
		ft_putstr_fd("Put the right Transparence\n", 2);
		return (1);
	}
	*tr = stof(tmp_tr);
	return (0);
}
