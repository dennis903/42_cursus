/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:44:07 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/07 18:34:16 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_c(t_tags tag, va_list va)
{
	char	ch;
	int		ret;
	int		i;

	if (tag.flags == '0' && tag.pre == 0)
		tag.flags = '\0';
	ret = 0;
	ch = va_arg(va, int);
	i = tag.width - 1;
	if (tag.flags == '\0')
		while (i-- > 0)
			ret += ft_putchar(' ');
	if (tag.flags == '0' && tag.width > 0)
		while (i-- > 0)
			ret += ft_putchar('0');
	ret += ft_putchar(ch);
	if (tag.flags == '-' && tag.width > 0)
		while (i-- > 0)
			ret += ft_putchar(' ');
	return (ret);
}
