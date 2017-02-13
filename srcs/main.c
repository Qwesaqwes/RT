/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:03 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/13 18:21:10 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	t_env e;

	gtk_init(&ac, &av);
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
	e.gtk.nb_effect = 0;
	init_gtk(&e);
	raytracing(&e);
	gtk_main();
	return (0);
}
//
