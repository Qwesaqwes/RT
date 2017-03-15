/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_modif_obj3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:35:48 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 15:36:48 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_type(char *type, t_list *list, const char *object)
{
	t_list	*tmp;
	t_obj	*tmp_obj;

	tmp = list;
	while (tmp != NULL)
	{
		tmp_obj = (t_obj*)tmp->content;
		if (ft_strcmp(tmp_obj->name, object) == 0)
		{
			*type = tmp_obj->type;
			break ;
		}
		tmp = tmp->next;
	}
}

GdkRGBA	*get_color(t_color *color)
{
	GdkRGBA		*gtk_color;

	gtk_color = NULL;
	gtk_color = malloc(sizeof(GdkRGBA));
	gtk_color->red = color->red;
	gtk_color->green = color->green;
	gtk_color->blue = color->blue;
	return (gtk_color);
}
