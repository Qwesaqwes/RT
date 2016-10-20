/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 02:17:50 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 02:14:21 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		expose_hook(t_env *e)
{
	raytracing(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	return (0);
}

int		key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}
