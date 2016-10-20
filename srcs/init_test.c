/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:21:24 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 03:47:40 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_list 	*init_test(void)
{
	t_list	*list;
	t_obj	obj1;

	list = NULL;
	obj1.id = 0;
	obj1.radius = 50;
	obj1.type = 0;
	obj1.center.x = 1000;
	obj1.center.y = 0;
	obj1.center.z = 0;
	obj1.color.red = 1;
	obj1.color.green = 0;
	obj1.color.blue = 0;
	ft_lstadd(&list, ft_lstnew(&obj1, sizeof(t_obj)));
	return (list);
}
