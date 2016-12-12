/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:10:57 by jichen-m          #+#    #+#             */
/*   Updated: 2016/12/12 18:18:00 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		set_black_color(void)
{
	t_color	c;

	c.red = 0;
	c.green = 0;
	c.blue = 0;
	return(c);
}

t_color		set_white_color(void)
{
	t_color	c;

	c.red = 1;
	c.green = 1;
	c.blue = 1;
	return(c);
}

void printlist(t_list **list, char depth, char action)
{
	t_list *tmp;

	tmp = *list;
	printf("depth: %d, action: %d, list: {", depth, action);
	while(tmp != NULL)
	{
		printf("%f", *(float*)tmp->content);
		if (tmp->next)
			printf(", ");
		tmp = tmp->next;
	}
	printf("}\n");
}

t_color		indirect_color(t_scene s, t_values v, t_cv cv, t_no no)
{
	float		fresnel_coeff;
	t_color		color_refl;
	t_color		color_trans;

//ft_putchar('1');
	v.depth += 1;
	color_refl = compute_ray(reflect(no.normal, no.origin.dir, no.ip, cv), s, v);

	color_refl = color_fact(color_refl, no.obj.ks);
	cv.action = 0;
	if (cv.sign < 0)
	{
		cv.action = 2;
		ft_lstdelfirst(v.refr_index);
	}
//ft_putchar('a');
	init_calculed_values(&cv, *(float*)(*v.refr_index)->content, no.obj.refr_index);

	if (cv.sinT2 > 1.0 || no.obj.t == 0)
	{
		if (cv.action == 2)
			ft_lstadd(v.refr_index, ft_lstnew(&cv.n1, sizeof(float)));
		return (color_refl);
	}
	fresnel_coeff = schlick(cv);
	color_refl = color_fact(color_refl, fresnel_coeff);
	if (cv.action == 0)
	{
		v.enter = 1;
		cv.action = 1;
		ft_lstadd(v.refr_index, ft_lstnew(&cv.n2, sizeof(float)));
	}
//ft_putchar('B');
	color_trans = compute_ray(refract(no.normal, no.origin.dir, no.ip, cv), s, v);
	color_trans = color_mult(color_trans, no.obj.color);
	color_trans = color_fact(color_trans, (1 - fresnel_coeff) * no.obj.t);
//ft_putchar('c');
	if (cv.action == 1)
		ft_lstdelfirst(v.refr_index);
	else if (cv.action == 2)
		ft_lstadd(v.refr_index, ft_lstnew(&cv.n1, sizeof(float)));
//ft_putchar('d');
	return(color_add(color_refl, color_trans));
}

t_color		compute_ray(t_ray ray, t_scene s, t_values v)
{
	t_no	no;
	t_color	color;
	t_cv	cv;

	color = set_black_color();
	if(v.depth < MAX_DEPTH)
	{
		if (get_nearest_obj(ray, s.obj, &no) == 0)
		{
			color = s.background;
		}
		else
		{
			no.normal = compute_normal_vec(no);
			color = compute_color(no, s, no.normal, ray.origin);
			cv.cosI = -vector_dot(no.normal, no.origin.dir);
			if (cv.cosI < 0)
			{
				if (v.enter == 0)
				{
					ft_lstadd(v.refr_index, ft_lstnew(&no.obj.refr_index, sizeof(float)));
				}
				cv.sign = -1;
				no.normal = vector_fact(no.normal, -1);
				cv.cosI = -vector_dot(no.normal, no.origin.dir);
			}
			else
				cv.sign = 1;

			color = color_add(color, indirect_color(s, v, cv, no));
		}
	}
	return(color);
}
