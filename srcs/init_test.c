/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:21:24 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/02 21:48:22 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_list 	*init_test(void)
{
	t_list	*list;
	t_obj	obj1;
	t_obj	obj2;
	t_obj	obj3;
	// t_obj	obj4;
	 t_obj	obj5;
	// t_obj	obj6;
	// t_obj	obj7;
	//t_obj	obj8;*/
	// t_obj	obj9;
	t_obj	obj10;

	list = NULL;
	obj1.id = 0;
	obj1.name = "sphere1";
	obj1.transform.scale.x = 1;
	obj1.transform.scale.y = 1;
	obj1.transform.scale.z = 1;
	obj1.transform.scale.w = 1;
	obj1.type = 0;
	obj1.transform.transl.x = 10;
	obj1.transform.transl.y = 0;
	obj1.transform.transl.z = -1;
	obj1.transform.transl.w = 1;
	obj1.transform.rot.x = 90;
	obj1.transform.rot.y = 0;
	obj1.transform.rot.z = 0;
	obj1.transform.rot.w = 1;
	obj1.color.red = 1;
	obj1.color.green = 0;
	obj1.color.blue = 0;
	obj1.ka = 0;
	obj1.kd = 0;
	obj1.ks = 1;
	obj1.i = 0;
	obj1.t = 0;
	obj1.shininess = 50;
	obj1.refr_index = 1;
	ft_lstaddend(&list, ft_lstnew(&obj1, sizeof(t_obj)));

	obj2.id = 1;
	obj2.name = "sphere2";
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
	ft_lstaddend(&list, ft_lstnew(&obj2, sizeof(t_obj)));

	obj3.id = 2;
	obj3.name = "sphere3";
	obj3.transform.scale.x = 1;
	obj3.transform.scale.y = 1;
	obj3.transform.scale.z = 1;
	obj3.transform.scale.w = 1;
	obj3.type = 0;
	obj3.transform.transl.x = 10;
	obj3.transform.transl.y = -1.75;
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
	obj3.t = 0;
	obj3.shininess = 50;
	obj3.refr_index = 1.33;
	ft_lstaddend(&list, ft_lstnew(&obj3, sizeof(t_obj)));

	// obj4.id = 3;
	// obj4.name = "sphere4";
	// obj4.transform.scale.x = 1;
	// obj4.transform.scale.y = 1;
	// obj4.transform.scale.z = 1;
	// obj4.transform.scale.w = 1;
	// obj4.type = 0;
	// obj4.transform.transl.x = 7;
	// obj4.transform.transl.y = 0;
	// obj4.transform.transl.z = 0;
	// obj4.transform.transl.w = 1;
	// obj4.transform.rot.x = 0;
	// obj4.transform.rot.y = 0;
	// obj4.transform.rot.z = 0;
	// obj4.transform.rot.w = 1;
	// obj4.color.red = 1;
	// obj4.color.green = 1;
	// obj4.color.blue = 1;
	// obj4.ka = 0.2;
	// obj4.kd = 0.9;
	// obj4.ks = 1;
	// obj4.i = 0;
	// obj4.t = 0.8;
	// obj4.shininess = 50;
	// obj4.refr_index = 1.33;
	// ft_lstaddend(&list, ft_lstnew(&obj4, sizeof(t_obj)));
	obj5.id = 5;
	obj5.name = "plane1";
	obj5.transform.scale.x = 1;
	obj5.transform.scale.y = 1;
	obj5.transform.scale.z = 1;
	obj5.transform.scale.w = 1;
	obj5.type = 2;
	obj5.transform.transl.x = 50;
	obj5.transform.transl.y = 0;
	obj5.transform.transl.z = -5;
	obj5.transform.transl.w = 1;
	obj5.normal.x = -1;
	obj5.normal.y = 0;
	obj5.normal.z = 0;
	obj5.normal.w = 1;
	obj5.transform.rot.x = 60;
	obj5.transform.rot.y = 60;
	obj5.transform.rot.z = 60;
	obj5.transform.rot.w = 1;
	obj5.color.red = 0.6;
	obj5.color.green = 0.7;
	obj5.color.blue = 0.3;
	obj5.ka = 0.2;
	obj5.kd = 0.9;
	obj5.ks = 0;
	obj5.i = 0;
	obj5.t = 0;
	obj5.shininess = 50;
	obj5.refr_index = 1.33;
	 ft_lstadd(&list, ft_lstnew(&obj5, sizeof(t_obj)));

	// obj6.id = 6;
	// obj6.name = "plane2";
	// obj6.transform.scale.x = 1;
	// obj6.transform.scale.y = 1;
	// obj6.transform.scale.z = 1;
	// obj6.transform.scale.w = 1;
	// obj6.type = 2;
	// obj6.transform.transl.x = 25;
	// obj6.transform.transl.y = 0;
	// obj6.transform.transl.z = 0;
	// obj6.transform.transl.w = 1;
	// obj6.normal.x = -1;
	// obj6.normal.y = 0;
	// obj6.normal.z = 0;
	// obj6.normal.w = 1;
	// obj6.transform.rot.x = 0;
	// obj6.transform.rot.y = 0;
	// obj6.transform.rot.z = 0;
	// obj6.transform.rot.w = 1;
	// obj6.color.red = 0.9;
	// obj6.color.green = 0.1;
	// obj6.color.blue = 0.2;
	// obj6.ka = 0.2;
	// obj6.kd = 0.9;
	// obj6.ks = 0;
	// obj6.i = 0;
	// obj6.t = 0;
	// obj6.shininess = 50;
	// obj6.refr_index = 1.33;
	//  ft_lstadd(&list, ft_lstnew(&obj6, sizeof(t_obj)));
	//
	// obj7.id = 8;
 // 	obj7.name = "plane3";
 // 	obj7.transform.scale.x = 1;
 // 	obj7.transform.scale.y = 1;
 // 	obj7.transform.scale.z = 1;
 // 	obj7.transform.scale.w = 1;
 // 	obj7.type = 2;
 // 	obj7.transform.transl.x = 50;
 // 	obj7.transform.transl.y = 0;
 // 	obj7.transform.transl.z = 5;
 // 	obj7.transform.transl.w = 1;
 // 	obj7.normal.x = -1;
 // 	obj7.normal.y = 0;
 // 	obj7.normal.z = 0;
 // 	obj7.normal.w = 1;
 // 	obj7.transform.rot.x = 0;
 // 	obj7.transform.rot.y = 90;
 // 	obj7.transform.rot.z = 0;
 // 	obj7.transform.rot.w = 1;
 // 	obj7.color.red = 0.2;
 // 	obj7.color.green = 0.1;
 // 	obj7.color.blue = 0.9;
 // 	obj7.ka = 0.2;
 // 	obj7.kd = 0.9;
 // 	obj7.ks = 0;
 // 	obj7.i = 0;
 // 	obj7.t = 0;
 // 	obj7.shininess = 50;
 // 	obj7.refr_index = 1.33;
 // 	 ft_lstadd(&list, ft_lstnew(&obj7, sizeof(t_obj)));

	/*obj8.id = 7;
	obj8.transform.scale.x = 1;
	obj8.transform.scale.y = 1;
	obj8.transform.scale.z = 1;
	obj8.transform.scale.w = 1;
	obj8.type = 2;
	obj8.transform.transl.x = 40;
	obj8.transform.transl.y = 0;
	obj8.transform.transl.z = 0;
	obj8.transform.transl.w = 1;
	obj8.normal.x = 1;
	obj8.normal.y = 0;
	obj8.normal.z = 0;
	obj8.normal.w = 1;
	obj8.transform.rot.x = 0;
	obj8.transform.rot.y = 0;
	obj8.transform.rot.z = 0;
	obj8.transform.rot.w = 1;
	obj8.color.red = 0.3;
	obj8.color.green = 0.5;
	obj8.color.blue = 0.3;
	obj8.ka = 0.2;
	obj8.kd = 0.9;
	obj8.ks = 0;
	obj8.i = 0;
	obj8.t = 0;
	obj8.shininess = 50;
	obj8.refr_index = 1.33;
	//ft_lstadd(&list, ft_lstnew(&obj8, sizeof(t_obj)));*/
	// obj9.id = 4;
	// obj9.name = "cone1";
	// obj9.transform.scale.x = 1;
	// obj9.transform.scale.y = 1;
	// obj9.transform.scale.z = 1;
	// obj9.transform.scale.w = 1;
	// obj9.type = 3; // cone
 // 	obj9.transform.transl.x = 15;
	// obj9.transform.transl.y = 0;
	// obj9.transform.transl.z = 0;
	// obj9.transform.transl.w = 1;
	// obj9.transform.rot.x = 70;
	// obj9.transform.rot.y = 0;
	// obj9.transform.rot.z = 0;
	// obj9.transform.rot.w = 1;
	// obj9.color.red = 1;
	// obj9.color.green = 1;
	// obj9.color.blue = 1;
	// obj9.ka = 0.2;
	// obj9.kd = 0.9;
	// obj9.ks = 0.1;
	// obj9.i = 0;
	// obj9.t = 0;
	// obj9.shininess = 50;
	// obj9.refr_index = 1.33;
	// ft_lstaddend(&list, ft_lstnew(&obj9, sizeof(t_obj)));

	obj10.id = 7;
	obj10.name = "triangle1";
	obj10.transform.scale.x = 1;
	obj10.transform.scale.y = 1;
	obj10.transform.scale.z = 1;
	obj10.transform.scale.w = 1;
	obj10.type = 5; // triangle
 	obj10.transform.transl.x = 15;
	obj10.transform.transl.y = 1;
	obj10.transform.transl.z = 1;
	obj10.transform.transl.w = 1;
	obj10.transform.rot.x = 0;
	obj10.transform.rot.y = 0;
	obj10.transform.rot.z = 0;
	obj10.transform.rot.w = 1;
	obj10.faces = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->vertex->coord = (t_vec3d){ 15, -3, 3, 1 };
	obj10.faces->vertex->next->coord = (t_vec3d){ 15, 0, 3, 1 };
	obj10.faces->vertex->next->next->coord = (t_vec3d){ 15, -3, 0, 1 };
	obj10.faces->vertex->next->next->next = NULL;
	obj10.faces->normal = (t_vec3d){-1, 0, 0, 1};

	obj10.faces->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->vertex->coord = (t_vec3d){ 15, 0, 0, 1 };
	obj10.faces->next->vertex->next->coord = (t_vec3d){ 15, -3, 0, 1 };
	obj10.faces->next->vertex->next->next->coord = (t_vec3d){ 15, 0, 3, 1 };
	obj10.faces->next->vertex->next->next->next = NULL;
	obj10.faces->next->normal = (t_vec3d){-1, 0, 0, 1};

	obj10.faces->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->vertex->coord = (t_vec3d){ 15, 0, 0, 1 };
	obj10.faces->next->next->vertex->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	obj10.faces->next->next->vertex->next->next->coord = (t_vec3d){ 18, 0, 0, 1 };
	obj10.faces->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->normal = (t_vec3d){0, 1, 0, 1};

	obj10.faces->next->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->vertex->coord = (t_vec3d){ 15, 0, 0, 1 };
	obj10.faces->next->next->next->vertex->next->coord = (t_vec3d){ 15, 0, 3, 1 };
	obj10.faces->next->next->next->vertex->next->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	obj10.faces->next->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->next->normal = (t_vec3d){0, 1, 0, 1};


	obj10.faces->next->next->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->vertex->coord = (t_vec3d){ 15, 0, 0, 1 };
	obj10.faces->next->next->next->next->vertex->next->coord = (t_vec3d){ 18, 0, 0, 1 };
	obj10.faces->next->next->next->next->vertex->next->next->coord = (t_vec3d){ 15, -3, 0, 1 };
	obj10.faces->next->next->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->next->next->normal = (t_vec3d){0, 0, -1, 1};


	obj10.faces->next->next->next->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->next->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->vertex->coord = (t_vec3d){ 15, -3, 0, 1 };
	obj10.faces->next->next->next->next->next->vertex->next->coord = (t_vec3d){ 18, 0, 0, 1 };
	obj10.faces->next->next->next->next->next->vertex->next->next->coord = (t_vec3d){ 18, -3, 0, 1 };
	obj10.faces->next->next->next->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->next->next->next->normal = (t_vec3d){0, 0,-1, 1};


	obj10.faces->next->next->next->next->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->next->next->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->vertex->coord = (t_vec3d){ 15, 0, 3, 1 };
	obj10.faces->next->next->next->next->next->next->vertex->next->coord = (t_vec3d){ 15, -3, 3, 1 };
	obj10.faces->next->next->next->next->next->next->vertex->next->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	obj10.faces->next->next->next->next->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->next->next->next->next->normal = (t_vec3d){0, 0, 1, 1};


	obj10.faces->next->next->next->next->next->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->next->next->next->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->vertex->coord = (t_vec3d){ 15, -3, 3, 1 };
	obj10.faces->next->next->next->next->next->next->next->vertex->next->coord = (t_vec3d){ 18, -3, 3, 1 };
	obj10.faces->next->next->next->next->next->next->next->vertex->next->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	obj10.faces->next->next->next->next->next->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->next->next->next->next->next->normal = (t_vec3d){0, 0, 1, 1};


	obj10.faces->next->next->next->next->next->next->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->next->next->next->next->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->vertex->coord = (t_vec3d){ 18, 0, 0, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->vertex->next->coord = (t_vec3d){ 18, -3, 3, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->vertex->next->next->coord = (t_vec3d){ 18, 0, 3, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->next->next->next->next->next->next->normal = (t_vec3d){1, 0, 0, 1};


	obj10.faces->next->next->next->next->next->next->next->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->next->next->next->next->next->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->next->vertex->coord = (t_vec3d){ 18, 0, 0, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->next->vertex->next->coord = (t_vec3d){ 18, -3, 0, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->next->vertex->next->next->coord = (t_vec3d){ 18, -3, 3, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->next->next->next->next->next->next->next->normal = (t_vec3d){1, 0, 0, 1};


	obj10.faces->next->next->next->next->next->next->next->next->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->next->next->next->next->next->next->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->next->next->vertex->coord = (t_vec3d){ 15, -3, 0, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->next->next->vertex->next->coord = (t_vec3d){ 18, -3, 0, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->next->next->vertex->next->next->coord = (t_vec3d){ 15, -3, 3, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->next->next->next->next->next->next->next->next->normal = (t_vec3d){0, -1, 0, 1};


	obj10.faces->next->next->next->next->next->next->next->next->next->next->next = (t_face*)ft_memalloc(sizeof(t_face));
	obj10.faces->next->next->next->next->next->next->next->next->next->next->next->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->next->next->next->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->next->next->next->vertex->next->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	obj10.faces->next->next->next->next->next->next->next->next->next->next->next->vertex->coord = (t_vec3d){ 15, -3, 3, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->next->next->next->vertex->next->coord = (t_vec3d){ 18, -3, 0, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->next->next->next->vertex->next->next->coord = (t_vec3d){ 18, -3, 3, 1 };
	obj10.faces->next->next->next->next->next->next->next->next->next->next->next->vertex->next->next->next = NULL;
	obj10.faces->next->next->next->next->next->next->next->next->next->next->next->normal = (t_vec3d){0, -1, 0, 1};
	obj10.faces->next->next->next->next->next->next->next->next->next->next->next->next = NULL;

	obj10.normal = (t_vec3d){-1, 0, 0, 1};
	obj10.color.red = 0;
	obj10.color.green = 1;
	obj10.color.blue = 1;
	obj10.ka = 0.2;
	obj10.kd = 0.9;
	obj10.ks = 0.1;
	obj10.i = 0;
	obj10.t = 0.5;
	obj10.shininess = 50;
	obj10.refr_index = 1.33;
	// printf("coord x: %f, y: %f, z: %f\n\n", obj10.faces->next->vertex->coord.x,
	// obj10.faces->next->vertex->coord.y, obj10.faces->next->vertex->coord.z);
	ft_lstaddend(&list, ft_lstnew(&obj10, sizeof(t_obj)));
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
	lum1.transform.transl.x = -20;
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
	ft_lstaddend(&list, ft_lstnew(&lum1, sizeof(t_obj)));

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
