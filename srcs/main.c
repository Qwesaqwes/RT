/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:03 by jichen-m          #+#    #+#             */
/*   Updated: 2016/12/05 18:14:39 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(void)
{
	t_env e;

	if (!(e.mlx = mlx_init()))
		return (0);
	if (!(e.win = mlx_new_window(e.mlx, W, H, "RT")))
		return (0);
	if (!(e.img.img_ptr = (mlx_new_image(e.mlx, W, H))))
		return (0);
	if (!(e.img.buffer = (unsigned char *)mlx_get_data_addr(e.img.img_ptr, \
		&e.img.bpp, &e.img.bpl, &e.img.endian)))
		return (0);
	init_cam(&e.camera);
	init_vp(&e.vp);
	e.scene.ia = 0.1;
	e.scene.n = 5;
	e.scene.obj = init_test();
	e.scene.lum = init_test_lum();
	mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
	mlx_expose_hook(e.win, &expose_hook, &e);
	mlx_loop(e.mlx);
}
