/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:21:24 by jichen-m          #+#    #+#             */
/*   Updated: 2016/11/23 18:55:28 by JimmyChen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_list 	*init_test(void)
{
	t_list	*list;
	t_obj	obj1;

	list = NULL;
	obj1.id = 0;
	obj1.transform.scale.x = 100;
	obj1.transform.scale.y = 100;
	obj1.transform.scale.z = 100;
	obj1.transform.scale.w = 1;
	obj1.type = 0;
	obj1.transform.transl.x = 1000;
	obj1.transform.transl.y = 0;
	obj1.transform.transl.z = 0;
	obj1.transform.transl.w = 1;
	obj1.transform.rot.x = 0;
	obj1.transform.rot.y = 0;
	obj1.transform.rot.z = 0;
	obj1.transform.rot.w = 1;
	obj1.color.red = 1;
	obj1.color.green = 0;
	obj1.color.blue = 0;
	ft_lstadd(&list, ft_lstnew(&obj1, sizeof(t_obj)));
	// if (list == NULL)
		// printf("A\n");
	return (list);
}
