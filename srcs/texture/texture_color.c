/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:37:04 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 19:00:04 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		procedural_texture(t_no no)
{
	if (no.obj.tex.texture == 1)
		return (checker(no));
	return (perlin_deriv(no));
}

t_color		texture_color(t_no no)
{
	if (no.obj.tex.texture == 1 || no.obj.tex.texture == 2 ||
		no.obj.tex.texture == 3 || no.obj.tex.texture == 4)
		return (procedural_texture(no));
	else if (no.obj.tex.texture == 5)
		return (texture_mapping(no));
	return (no.obj.color);
}
