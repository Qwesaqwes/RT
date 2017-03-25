/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_options1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:04:19 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:29:23 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	gtk_s_img(GtkWidget *button, gpointer buffer)
{
	GError	*err;

	(void)button;
	err = NULL;
	gdk_pixbuf_save(buffer, "RT_img", "jpeg", &err, "quality", "100", NULL);
}

void	gtk_zoom(GtkWidget *button, t_env *e)
{
	(void)button;
	e->vp.dist += 0.5;
	raytracing(e);
}

void	gtk_dezoom(GtkWidget *button, t_env *e)
{
	(void)button;
	e->vp.dist -= 0.5;
	if (e->vp.dist <= 0)
	{
		e->vp.dist = 0.5;
		ft_putstr_fd("No more Dezoom available\n", 2);
	}
	raytracing(e);
}
