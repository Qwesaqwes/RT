/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lum_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:04:50 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 22:04:52 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		ft_fill_info_lum6(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "translate_xyz") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.translate_xyz++;
		e->tmp = atof(e->split[1]);
		obj->transform.transl.x = e->tmp;
		e->tmp = atof(e->split[2]);
		obj->transform.transl.y = e->tmp;
		e->tmp = atof(e->split[3]);
		obj->transform.transl.z = e->tmp;
	}
	else
		ft_puterror(e, ft_strjoin("Wrong Info Light line ",
		ft_itoa(e->save_i + 1)));
}

void			ft_fill_info_lum5(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "rotation_xyz") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.rotation_xyz++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Object - rotation_x");
		obj->transform.rot.x = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Object - rotation_y");
		obj->transform.rot.y = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Object - rotation_z");
		obj->transform.rot.z = e->tmp;
	}
	else
		ft_fill_info_lum6(obj, e);
}
