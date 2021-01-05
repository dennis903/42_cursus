/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:36:17 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/09 18:53:41 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_flags(char c, t_tags **tag)
{
	if (((*tag)->flags != '-') && (*tag)->width == 0
	&& (*tag)->pre == -1 && (*tag)->dot == 0 && (c == '-' || c == '0'))
	{
		(*tag)->flags = c;
		return (1); 
	}
	else if ((c == '-' || c == '0') && (*tag)->width == 0 && (*tag)->dot == 0)
		return (1);
	return (0);
}

int			check_width(char c, t_tags **tag, va_list va)
{
	if (c == '*' && (*tag)->dot == 0 && (*tag)->pre == -1)
	{
		if (c == '*')
			(*tag)->width = va_arg(va, int);
		if ((*tag)->width < 0)
		{
			(*tag)->width *= -1;
			(*tag)->flags = '-';
		}
		return (1);
	}
	else if (ft_isdigit(c) && (*tag)->dot == 0 && (*tag)->pre == -1)
	{
		(*tag)->width = ((*tag)->width * 10) + (c - '0');
		return (1);
	}
	return (0);
}

int			check_dot(char c, t_tags **tag)
{
	if (c == '.')
	{
		(*tag)->dot = 1;
		(*tag)->pre = 0;
		return (1);
	}
	return (0);
}

int			check_precision(char c, t_tags **tag, va_list va)
{
	if ((*tag)->dot == 1)
	{
		if (ft_isdigit(c))
			(*tag)->pre = ((*tag)->pre * 10) + (c - '0');
		else if (c == '*')
		{
			(*tag)->pre = va_arg(va, int);
			if ((*tag)->pre < 0)
				(*tag)->pre = -1;
		}
	}
	else
		return (0);
	return (1);
}
