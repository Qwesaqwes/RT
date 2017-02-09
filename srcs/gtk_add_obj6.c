/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:01:50 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/09 20:53:53 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	stof2(const char *s, float rez, float fact, int point_seen)
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

float	stof (const char *s)
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

void	reverse(char *str, int len)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int		intostr(int x, char *str, int d)
{
	int		i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
	str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return i;
}

const char		*itof(float nb)
{
	int			ipart;
	float		fpart;
	char		*res;
	int			i;

	if (nb == 0)
		return ("0");
	ipart = (int)nb;
	fpart = nb - (float)ipart;
	if (!(res = malloc(sizeof(const char*) * 20)))
		return (NULL);
	i = intostr(ipart, res, 0);
	if(fpart != 0)
	{
		res[i] = '.';
		fpart = fpart * pow(10, 6);
		intostr((int)fpart, res + i + 1, 6);
	}
	return ((const char*)res);
}
