/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_choose_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:46:08 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 14:54:15 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	gtk_choose_f(GtkWidget *button, t_env *e)
{
	GtkWidget	*dial;
	char		*c;

	(void)button;
	dial = gtk_file_chooser_dialog_new("Open Scene",
	GTK_WINDOW(e->gtk.window), GTK_FILE_CHOOSER_ACTION_OPEN, ("CANCEL"),
	GTK_RESPONSE_REJECT, ("OPEN"), GTK_RESPONSE_ACCEPT, NULL);
	gtk_widget_show_all(dial);
	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dial), "./parce_file");
	if (gtk_dialog_run(GTK_DIALOG(dial)) == GTK_RESPONSE_ACCEPT)
	{
		c = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dial));
		g_print("%s\n", c);
		g_free(c);
	}
	gtk_widget_destroy(dial);
}
