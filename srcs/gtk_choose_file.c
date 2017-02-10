/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_choose_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:46:08 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/10 18:00:50 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	gtk_choose_f(GtkWidget *button, t_env *e)
{
	GtkWidget	*dialog;
	gint		resp;

	(void)button;
	dialog = gtk_file_chooser_dialog_new("Open Scene",
	GTK_WINDOW(e->gtk.window), GTK_FILE_CHOOSER_ACTION_OPEN, ("CANCEL"),
	GTK_RESPONSE_REJECT, ("OPEN"), GTK_RESPONSE_ACCEPT, NULL);
	gtk_widget_show_all(dialog);
	resp = gtk_dialog_run(GTK_DIALOG(dialog));
	if (resp == GTK_RESPONSE_ACCEPT)
		g_print("clicked");
	gtk_widget_destroy(dialog);
}
