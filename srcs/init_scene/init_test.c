/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:21:24 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/10 00:28:28 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		protect_cube(t_obj *cube)
{
	int			fd;
	int			fd2;
	char		*str;
	char		*str2;

	str = "./maps/monde.jpg";
	str2 = "./maps/golf.jpg";
	fd = open(str, O_RDONLY);
	fd2 = open(str2, O_RDONLY);
	if (fd < 3 || fd2 < 3)
	{
		ft_putstr_fd("Invalid Map\n", 2);
		if (fd < 3)
			cube->tex.texture = 0;
		if (fd2 < 3)
			cube->tex.bump = 0;
	}
	if (cube->tex.texture == 5)
		cube->map_buf = gdk_pixbuf_new_from_file(str, NULL);
	if (cube->tex.bump == 1)
		cube->bump_buf = gray_scale(gdk_pixbuf_new_from_file(str2, NULL));
}

void			init_cube(t_obj *cube)
{
	cube->id = 7;
	cube->name = ft_strdup("triangle1");
	cube->transform.scale = (t_vec3d){1, 1, 1, 1};
	cube->type = 5;
	cube->transform.transl = (t_vec3d){15, 1, 1, 1};
	cube->transform.rot = (t_vec3d){0, 0, 0, 1};
	cube->normal = (t_vec3d){-1, 0, 0, 1};
	cube->color = (t_color){0.5, 0.5, 0.5};
	cube->ka = 0.2;
	cube->kd = 0.9;
	cube->ks = 0;
	cube->i = 0;
	cube->t = 0;
	cube->shininess = 0;
	cube->refr_index = 1.33;
	cube->tex.texture = 5;
	cube->tex.bump = 1;
	cube->tex.transp = 0;
	protect_cube(cube);
}

void			init_plan(t_obj *plan)
{
	plan->id = 4;
	plan->name = ft_strdup("plane1");
	plan->transform.scale = (t_vec3d){1, 1, 1, 1};
	plan->type = 2;
	plan->transform.transl = (t_vec3d){50, 0, -20, 1};
	plan->normal = (t_vec3d){-1, 0, 0, 1};
	plan->transform.rot = (t_vec3d){0, 60, 0, 1};
	plan->color = (t_color){0.6, 0.7, 0.3};
	plan->ka = 0.2;
	plan->kd = 0.9;
	plan->ks = 0;
	plan->i = 0;
	plan->t = 0;
	plan->shininess = 50;
	plan->refr_index = 1.33;
	plan->tex.texture = 1;
	plan->tex.bump = 0;
	plan->tex.transp = 0;
	plan->tex.tex_col1 = (t_color){0.4, 0.4, 0.4};
	plan->tex.tex_col2 = (t_color){0.5, 0.5, 0.5};
	plan->tex.tex_col3 = (t_color){0.8, 0.8, 0.8};
	plan->tex.square = 3;
}

t_list			*init_test(void)
{
	t_list		*list;
	t_obj		obj1;
	t_obj		obj2;

	list = NULL;
	init_cube(&obj1);
	obj1.faces = (t_face*)ft_memalloc(sizeof(t_face));
	add_face1(obj1.faces);
	obj1.faces->n->n = (t_face*)ft_memalloc(sizeof(t_face));
	add_face2(obj1.faces->n->n);
	obj1.faces->n->n->n->n = (t_face*)ft_memalloc(sizeof(t_face));
	add_face3(obj1.faces->n->n->n->n);
	obj1.faces->n->n->n->n->n->n = (t_face*)ft_memalloc(sizeof(t_face));
	add_face4(obj1.faces->n->n->n->n->n->n);
	obj1.faces->n->n->n->n->n->n->n->n = (t_face*)ft_memalloc(sizeof(t_face));
	add_face5(obj1.faces->n->n->n->n->n->n->n->n);
	obj1.faces->n->n->n->n->n->n->n->n->n->n =
	(t_face*)ft_memalloc(sizeof(t_face));
	add_face6(obj1.faces->n->n->n->n->n->n->n->n->n->n);
	ft_lstaddend(&list, ft_lstnew(&obj1, sizeof(t_obj)));
	init_plan(&obj2);
	ft_lstaddend(&list, ft_lstnew(&obj2, sizeof(t_obj)));
	return (list);
}

t_list			*init_test_lum(void)
{
	t_list		*list;
	t_obj		lum1;

	list = NULL;
	lum1.id = 0;
	lum1.name = ft_strdup("lum1");
	lum1.transform.scale = (t_vec3d){1, 1, 1, 1};
	lum1.type = 0;
	lum1.typel = 0;
	lum1.transform.transl = (t_vec3d){-15, 0, 15, 1};
	lum1.transform.rot = (t_vec3d){0, 0, 0, 1};
	lum1.color = (t_color){1, 1, 1};
	lum1.ka = 0;
	lum1.kd = 0;
	lum1.ks = 0;
	lum1.i = 1;
	lum1.t = 0;
	lum1.shininess = 0;
	ft_lstaddend(&list, ft_lstnew(&lum1, sizeof(t_obj)));
	return (list);
}
