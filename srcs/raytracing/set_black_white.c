/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_black_white.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:20:27 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/04 16:20:46 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		set_black(void)
{
	t_color	c;

	c.red = 0;
	c.green = 0;
	c.blue = 0;
	return (c);
}

t_color		set_white_color(void)
{
	t_color	c;

	c.red = 1;
	c.green = 1;
	c.blue = 1;
	return (c);
}
