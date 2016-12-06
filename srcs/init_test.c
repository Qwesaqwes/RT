/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:21:24 by jichen-m          #+#    #+#             */
/*   Updated: 2016/12/06 16:50:48 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_list 	*init_test(void)
{
	t_list	*list;
	t_obj	obj1;
	// t_obj	obj2;

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
	obj1.k.a.red = 0.5;
	obj1.k.a.green = 0;
	obj1.k.a.blue = 0;
	obj1.k.d.red = 0.9;
	obj1.k.d.green = 0;
	obj1.k.d.blue = 0;
	obj1.k.s.red = 1;
	obj1.k.s.green = 0;
	obj1.k.s.blue = 0;
	obj1.i.d.red = 0;
	obj1.i.d.green = 0;
	obj1.i.d.blue = 0;
	obj1.i.s.red = 0;
	obj1.i.s.green = 0;
	obj1.i.s.blue = 0;
	obj1.shininess = 50;
	ft_lstadd(&list, ft_lstnew(&obj1, sizeof(t_obj)));
	// obj2.id = 1;
	// obj2.transform.scale.x = 100;
	// obj2.transform.scale.y = 100;
	// obj2.transform.scale.z = 100;
	// obj2.transform.scale.w = 1;
	// obj2.type = 0;
	// obj2.transform.transl.x = 1000;
	// obj2.transform.transl.y = -500;
	// obj2.transform.transl.z = 0;
	// obj2.transform.transl.w = 1;
	// obj2.transform.rot.x = 0;
	// obj2.transform.rot.y = 0;
	// obj2.transform.rot.z = 0;
	// obj2.transform.rot.w = 1;
	// obj2.color.red = 0;
	// obj2.color.green = 1;
	// obj2.color.blue = 0;
	// obj2.kd = 0.9;
	// obj2.ks = 0.1;
	// obj2.i = 0;
	// ft_lstadd(&list, ft_lstnew(&obj2, sizeof(t_obj)));
	return (list);
}

t_list	*init_test_lum(void)
{
	t_list	*list;
	t_obj	lum1;

	list = NULL;
	lum1.id = 0;
	lum1.transform.scale.x = 1;
	lum1.transform.scale.y = 1;
	lum1.transform.scale.z = 1;
	lum1.transform.scale.w = 1;
	lum1.type = 0;
	lum1.transform.transl.x = 750;
	lum1.transform.transl.y = -250;
	lum1.transform.transl.z = 0;
	lum1.transform.transl.w = 1;
	lum1.transform.rot.x = 0;
	lum1.transform.rot.y = 0;
	lum1.transform.rot.z = 0;
	lum1.transform.rot.w = 1;
	lum1.color.red = 1;
	lum1.color.green = 1;
	lum1.color.blue = 1;
	lum1.color.red = 1;
	lum1.color.green = 0;
	lum1.color.blue = 0;
	lum1.k.a.red = 0;
	lum1.k.a.green = 0;
	lum1.k.a.blue = 0;
	lum1.k.d.red = 0;
	lum1.k.d.green = 0;
	lum1.k.d.blue = 0;
	lum1.k.s.red = 0;
	lum1.k.s.green = 0;
	lum1.k.s.blue = 0;
	lum1.i.d.red = 1;
	lum1.i.d.green = 1;
	lum1.i.d.blue = 1;
	lum1.i.s.red = 1;
	lum1.i.s.green = 1;
	lum1.i.s.blue = 1;
	lum1.shininess = 0;
	ft_lstadd(&list, ft_lstnew(&lum1, sizeof(t_obj)));
	return (list);
}