/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_choose_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:46:08 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/01 22:05:16 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	gtk_choose_f(GtkWidget *button, t_env *e)
{
	GtkWidget	*dialog;

	(void)button;
	dialog = gtk_file_chooser_dialog_new("Open Scene",
	GTK_WINDOW(e->gtk.window), GTK_FILE_CHOOSER_ACTION_OPEN, ("CANCEL"),
	GTK_RESPONSE_REJECT, ("OPEN"), GTK_RESPONSE_ACCEPT, NULL);
	gtk_widget_show_all(dialog);
	gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER(dialog),"./parce_file");
	if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
	{
		char *c = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
		g_print("%s\n",c);
		g_free(c);
	}
	gtk_widget_destroy(dialog);
}
