/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_per.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:17:46 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/07 18:34:28 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_per(t_tags tag)
{
	int		ret;
	int		i;

	ret = 0;
	i = tag.width - 1;
	if (tag.flags == '\0')
		while (i-- > 0)
			ret += ft_putchar(' ');
	if (tag.flags == '0' && tag.width > 0)
		while (i-- > 0)
			ret += ft_putchar('0');
	ret += ft_putchar('%');
	if (tag.flags == '-' && tag.width > 0)
		while (i-- > 0)
			ret += ft_putchar(' ');
	return (ret);
}
