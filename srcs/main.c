/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:03 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/19 02:21:49 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	t_env e;

	if (!(e.mlx = mlx_init()))
		return (0);
	if (!(e.win = mlx_new_window(e.mlx, W, H, "Rtv1")))
		return (0);
	if (!(e.img.img_ptr = (mlx_new_image(e.mlx, W, H))))
		return (0);
	if (!(e.img.buffer = (unsigned char *)mlx_get_data_addr(e.img.img_ptr, \
		&e.img.bpp, &e.img.bpl, &e.img.endian)))
		return (0);
	mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
	mlx_expose_hook(e.win, &expose_hook, &e);
	mlx_loop(e.mlx);
}
