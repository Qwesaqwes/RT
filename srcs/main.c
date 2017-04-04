/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:03 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/04 16:13:53 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_cam_vp_scene(t_env *e)
{
	init_cam(&e->camera);
	init_vp(&e->vp);
	e->scene.ambiant.red = 1;
	e->scene.ambiant.green = 1;
	e->scene.ambiant.blue = 1;
	e->scene.background.red = 0;
	e->scene.background.green = 0;
	e->scene.background.blue = 0;
	e->scene.refr_index = 1;
	e->scene.obj = init_test();
	e->scene.lum = init_test_lum();
	e->scene.antialiasing = 1;
}

int			main(int ac, char **av)
{
	t_env	e;
	int		res;

	gtk_init(&ac, &av);
	if (ac > 2)
	{
		init_cam(&e.camera);
		init_vp(&e.vp);
		ft_putendl("So many file given");
		exit(0);
	}
	else if (ac == 2)
	{
		if ((res = ft_fill_parce(&e, av[1])) != 0)
			exit(0);
	}
	else if (ac == 1)
		init_cam_vp_scene(&e);
	e.gtk.nb_effect = 0;
	init_gtk(&e);
	raytracing(&e);
	gtk_main();
	ft_lstdel(&e.scene.obj, ft_free_obj);
	ft_lstdel(&e.scene.lum, ft_free_obj);
	return (0);
}
