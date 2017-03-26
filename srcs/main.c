/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:03 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:43:06 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	t_env 	e;

	gtk_init(&ac, &av);
	if (ac > 2)
		ft_puterror("So many file given");
	else if (ac == 2)
		ft_fill_parce(&e, av[1]);
	else if (ac == 1)
	{
		init_cam(&e.camera);
		init_vp(&e.vp);
		e.scene.ambiant.red = 1;
		e.scene.ambiant.green = 1;
		e.scene.ambiant.blue = 1;
		e.scene.background.red = 0;
		e.scene.background.green = 0;
		e.scene.background.blue = 0;
		e.scene.refr_index = 1;
		e.scene.obj = init_test();
		e.scene.lum = init_test_lum();
		e.scene.antialiasing = 1;
	}
	e.gtk.nb_effect = 0;
	init_gtk(&e);
	raytracing(&e);
	gtk_main();
	ft_lstdel(&e.scene.obj, ft_free_obj);
	ft_lstdel(&e.scene.lum, ft_free_obj);
	return (0);
}
