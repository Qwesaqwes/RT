/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.options7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:01:50 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/02 14:04:17 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float stof2(const char *s, float rez, float fact, int point_seen)
{
	int i;
	int d;

	i = -1;
	while(s[++i] != '\0')
	{
		if (s[i] == '.')
		{
			point_seen = 1;
			continue;
		}
		d = s[i] - '0';
		if (d >= 0 && d <= 9)
		{
			if (point_seen)
				fact /= 10.0f;
			rez = rez * 10.0f + (float)d;
		}
	}
	return (rez * fact);
}

float stof (const char *s)
{
	float	rez;
	float	fact;
	int		point_seen;

	rez = 0;
	fact = 1;
	if (*s == '-')
	{
		s++;
		fact = -1;
	}
	point_seen = 0;
	return (stof2(s, rez, fact, point_seen));
}
