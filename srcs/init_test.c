/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:21:24 by jichen-m          #+#    #+#             */
/*   Updated: 2016/12/12 18:31:42 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_list 	*init_test(void)
{
	t_list	*list;
	t_obj	obj1;
	t_obj	obj2;
	t_obj	obj3;
	t_obj	obj4;
	t_obj	obj5;
	t_obj	obj6;
	t_obj	obj7;

	list = NULL;
	obj1.id = 0;
	obj1.transform.scale.x = 1;
	obj1.transform.scale.y = 1;
	obj1.transform.scale.z = 1;
	obj1.transform.scale.w = 1;
	obj1.type = 0;
	obj1.transform.transl.x = 10;
	obj1.transform.transl.y = 0;
	obj1.transform.transl.z = -1;
	obj1.transform.transl.w = 1;
	obj1.transform.rot.x = 0;
	obj1.transform.rot.y = 0;
	obj1.transform.rot.z = 0;
	obj1.transform.rot.w = 1;
	obj1.color.red = 1;
	obj1.color.green = 0;
	obj1.color.blue = 0;
	obj1.ka = 0.2;
	obj1.kd = 0.9;
	obj1.ks = 0;
	obj1.i = 0;
	obj1.t = 0;
	obj1.shininess = 50;
	obj1.refr_index = 1;
	ft_lstadd(&list, ft_lstnew(&obj1, sizeof(t_obj)));
	obj2.id = 1;
	obj2.transform.scale.x = 1;
	obj2.transform.scale.y = 1;
	obj2.transform.scale.z = 1;
	obj2.transform.scale.w = 1;
	obj2.type = 0;
	obj2.transform.transl.x = 10;
	obj2.transform.transl.y = 0;
	obj2.transform.transl.z = 1;
	obj2.transform.transl.w = 1;
	obj2.transform.rot.x = 0;
	obj2.transform.rot.y = 0;
	obj2.transform.rot.z = 0;
	obj2.transform.rot.w = 1;
	obj2.color.red = 0;
	obj2.color.green = 1;
	obj2.color.blue = 0;
	obj2.ka = 0.2;
	obj2.kd = 0.9;
	obj2.ks = 1;
	obj2.i = 0;
	obj2.t = 0;
	obj2.shininess = 50;
	obj2.refr_index = 1.33;
	ft_lstadd(&list, ft_lstnew(&obj2, sizeof(t_obj)));
	obj3.id = 2;
	obj3.transform.scale.x = 1;
	obj3.transform.scale.y = 1;
	obj3.transform.scale.z = 1;
	obj3.transform.scale.w = 1;
	obj3.type = 0;
	obj3.transform.transl.x = 10;
	obj3.transform.transl.y = 1.75;
	obj3.transform.transl.z = 0;
	obj3.transform.transl.w = 1;
	obj3.transform.rot.x = 0;
	obj3.transform.rot.y = 0;
	obj3.transform.rot.z = 0;
	obj3.transform.rot.w = 1;
	obj3.color.red = 0;
	obj3.color.green = 0;
	obj3.color.blue = 1;
	obj3.ka = 0.2;
	obj3.kd = 0.9;
	obj3.ks = 1;
	obj3.i = 0;
	obj3.t = 0.5;
	obj3.shininess = 50;
	obj3.refr_index = 1.33;
//	ft_lstadd(&list, ft_lstnew(&obj3, sizeof(t_obj)));
	obj4.id = 3;
	obj4.transform.scale.x = 1;
	obj4.transform.scale.y = 1;
	obj4.transform.scale.z = 1;
	obj4.transform.scale.w = 1;
	obj4.type = 0;
	obj4.transform.transl.x = 1;
	obj4.transform.transl.y = 0;
	obj4.transform.transl.z = 0;
	obj4.transform.transl.w = 1;
	obj4.transform.rot.x = 0;
	obj4.transform.rot.y = 0;
	obj4.transform.rot.z = 0;
	obj4.transform.rot.w = 1;
	obj4.color.red = 1;
	obj4.color.green = 1;
	obj4.color.blue = 1;
	obj4.ka = 0.2;
	obj4.kd = 0.9;
	obj4.ks = 1;
	obj4.i = 0;
	obj4.t = 1;
	obj4.shininess = 50;
	obj4.refr_index = 1;
	//ft_lstadd(&list, ft_lstnew(&obj4, sizeof(t_obj)));
	obj5.id = 4;
	obj5.transform.scale.x = 1;
	obj5.transform.scale.y = 1;
	obj5.transform.scale.z = 1;
	obj5.transform.scale.w = 1;
	obj5.type = 2;
	obj5.transform.transl.x = 50;
	obj5.transform.transl.y = 0;
	obj5.transform.transl.z = -20;
	obj5.transform.transl.w = 1;
	obj5.normal.x = 0;
	obj5.normal.y = 0;
	obj5.normal.z = 1;
	obj5.normal.w = 1;
	obj5.transform.rot.x = 0;
	obj5.transform.rot.y = 0;
	obj5.transform.rot.z = 0;
	obj5.transform.rot.w = 1;
	obj5.color.red = 1;
	obj5.color.green = 1;
	obj5.color.blue = 1;
	obj5.ka = 0.2;
	obj5.kd = 0.9;
	obj5.ks = 0;
	obj5.i = 0;
	obj5.t = 0;
	obj5.shininess = 50;
	obj5.refr_index = 1.33;
	ft_lstadd(&list, ft_lstnew(&obj5, sizeof(t_obj)));
	obj6.id = 5;
	obj6.transform.scale.x = 1;
	obj6.transform.scale.y = 1;
	obj6.transform.scale.z = 1;
	obj6.transform.scale.w = 1;
	obj6.type = 2;
	obj6.transform.transl.x = 0;
	obj6.transform.transl.y = -20;
	obj6.transform.transl.z = 0;
	obj6.transform.transl.w = 1;
	obj6.normal.x = 0;
	obj6.normal.y = 1;
	obj6.normal.z = 0;
	obj6.normal.w = 1;
	obj6.transform.rot.x = 0;
	obj6.transform.rot.y = 0;
	obj6.transform.rot.z = 0;
	obj6.transform.rot.w = 1;
	obj6.color.red = 0.3;
	obj6.color.green = 0.5;
	obj6.color.blue = 0.3;
	obj6.ka = 0.2;
	obj6.kd = 0.9;
	obj6.ks = 0;
	obj6.i = 0;
	obj6.t = 0;
	obj6.shininess = 50;
	obj6.refr_index = 1.33;
	ft_lstadd(&list, ft_lstnew(&obj6, sizeof(t_obj)));
	obj7.id = 6;
	obj7.transform.scale.x = 1;
	obj7.transform.scale.y = 1;
	obj7.transform.scale.z = 1;
	obj7.transform.scale.w = 1;
	obj7.type = 1;
	obj7.transform.transl.x = 10;
	obj7.transform.transl.y = 0;
	obj7.transform.transl.z = -1;
	obj7.transform.transl.w = 1;
	obj7.transform.rot.x = 50;
	obj7.transform.rot.y = 0;
	obj7.transform.rot.z = 0;
	obj7.transform.rot.w = 1;
	obj7.color.red = 0;
	obj7.color.green = 1;
	obj7.color.blue = 0;
	obj7.ka = 0.2;
	obj7.kd = 0.9;
	obj7.ks = 1;
	obj7.i = 0;
	obj7.t = 0;
	obj7.shininess = 50;
	obj7.refr_index = 1.33;
	//ft_lstadd(&list, ft_lstnew(&obj7, sizeof(t_obj)));
	return (list);
}

t_list	*init_test_lum(void)
{
	t_list	*list;
	t_obj	lum1;
	// t_obj	lum2;

	list = NULL;
	lum1.id = 0;
	lum1.transform.scale.x = 1;
	lum1.transform.scale.y = 1;
	lum1.transform.scale.z = 1;
	lum1.transform.scale.w = 1;
	lum1.type = 0;
	lum1.transform.transl.x = 0;
	lum1.transform.transl.y = 0;
	lum1.transform.transl.z = 0;
	lum1.transform.transl.w = 1;
	lum1.transform.rot.x = 0;
	lum1.transform.rot.y = 0;
	lum1.transform.rot.z = 0;
	lum1.transform.rot.w = 1;
	lum1.color.red = 1;
	lum1.color.green = 1;
	lum1.color.blue = 1;
	lum1.ka = 0;
	lum1.kd = 0;
	lum1.ks = 0;
	lum1.i = 1;
	lum1.t = 0;
	lum1.shininess = 0;
	ft_lstadd(&list, ft_lstnew(&lum1, sizeof(t_obj)));

	// lum2.id = 1;
	// lum2.transform.scale.x = 1;
	// lum2.transform.scale.y = 1;
	// lum2.transform.scale.z = 1;
	// lum2.transform.scale.w = 1;
	// lum2.type = 0;
	// lum2.transform.transl.x = 0;
	// lum2.transform.transl.y = 1500;
	// lum2.transform.transl.z = 0;
	// lum2.transform.transl.w = 1;
	// lum2.transform.rot.x = 0;
	// lum2.transform.rot.y = 0;
	// lum2.transform.rot.z = 0;
	// lum2.transform.rot.w = 1;
	// lum2.color.red = 1;
	// lum2.color.green = 1;
	// lum2.color.blue = 1;
	// lum2.color.red = 1;
	// lum2.color.green = 0;
	// lum2.color.blue = 0;
	// lum2.k.a.red = 0;
	// lum2.k.a.green = 0;
	// lum2.k.a.blue = 0;
	// lum2.k.d.red = 0;
	// lum2.k.d.green = 0;
	// lum2.k.d.blue = 0;
	// lum2.k.s.red = 0;
	// lum2.k.s.green = 0;
	// lum2.k.s.blue = 0;
	// lum2.i.d.red = 1;
	// lum2.i.d.green = 1;
	// lum2.i.d.blue = 1;
	// lum2.i.s.red = 1;
	// lum2.i.s.green = 1;
	// lum2.i.s.blue = 1;
	// lum2.shininess = 0;
	// ft_lstadd(&list, ft_lstnew(&lum2, sizeof(t_obj)));
	return (list);
}
