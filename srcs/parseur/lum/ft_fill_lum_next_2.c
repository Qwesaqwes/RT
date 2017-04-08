/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lum_next_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:21:51 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/08 15:21:53 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void			ft_verif_limit_exist_lum(t_e *e, t_obj *tmp)
{
	if (e->vobject.x_min > 1 || e->vobject.x_max > 1 || e->vobject.y_min > 1
		|| e->vobject.y_max > 1 || e->vobject.z_min > 1 || e->vobject.z_max > 1)
		ft_puterror(e, "Wrong Info Lum - Min Max");
	if (e->vobject.x_min == 1 && e->vobject.x_max == 1)
		if (tmp->limit.x_min >= tmp->limit.x_max)
			ft_puterror(e,
			"Wrong Info Lum  x_min must to be less than x_max");
	if (e->vobject.y_min == 1 && e->vobject.y_max == 1)
		if (tmp->limit.y_min >= tmp->limit.y_max)
			ft_puterror(e,
			"Wrong Info Lum 	y_min must to be less than y_max");
	if (e->vobject.z_min == 1 && e->vobject.z_max == 1)
		if (tmp->limit.z_min >= tmp->limit.z_max)
			ft_puterror(e, "Wrong Info Lum  z_min must to be less than z_max");
}

static void		ft_fill_info_lum9(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "y_max") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.y_max = 1;
		e->vobject.y_max++;
		obj->limit.y_max = stof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "z_min") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.z_min = 1;
		e->vobject.z_min++;
		obj->limit.z_min = stof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "z_max") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.z_max = 1;
		e->vobject.z_max++;
		obj->limit.z_max = stof(e->split[1]);
	}
	else
	{
		ft_puterror(e, ft_strjoin("Wrong Info Light line ",
		ft_itoa(e->save_i + 1)));
	}
}

void			ft_fill_info_lum8(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "x_min") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.x_min = 1;
		e->vobject.x_min++;
		obj->limit.x_min = stof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "x_max") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.x_max = 1;
		e->vobject.x_max++;
		obj->limit.x_max = stof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "y_min") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.y_min = 1;
		e->vobject.y_min++;
		obj->limit.y_min = stof(e->split[1]);
	}
	else
		ft_fill_info_lum9(obj, e);
}
