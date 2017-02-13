/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:16:51 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/13 18:35:24 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	gtk_effect(GtkWidget *button, t_env *e)
{
	int		active;

	(void)button;
	active = gtk_combo_box_get_active(GTK_COMBO_BOX(e->gtk.n_effect));
	if (active > -1)
	{
		if (active == 1)
		{
			e->gtk.nb_effect = 1;
			gtk_widget_destroy(e->gtk.img);
			raytracing(e);
			reset_img(&e->gtk);
		}
		else if (active == 0)
		{
			e->gtk.nb_effect = 0;
			gtk_widget_destroy(e->gtk.img);
			raytracing(e);
			reset_img(&e->gtk);
		}
		else if (active == 2)
		{
			e->gtk.nb_effect = 2;
			gtk_widget_destroy(e->gtk.img);
			raytracing(e);
			reset_img(&e->gtk);
		}
	}
}
