/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:29:32 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/07 18:41:12 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_u_outline(int len, t_tags tag, int minus, char c)
{
	int				arg;
	int				ret;
	int				i;

	ret = 0;
	arg = (tag.pre + minus > len) ? tag.pre + minus : len;
	i = tag.width - arg;
	while (c == ' ' && i-- > 0)
		ret += ft_putchar(' ');
	while (c == '0' && i-- > 0)
		ret += ft_putchar('0');
	return (ret);
}

int					print_u_inline(int len, t_tags tag, int minus)
{
	int				ret;
	int				i;

	i = (tag.pre + minus) - len;
	ret = 0;
	while (i-- > 0)
		ret += ft_putchar('0');
	return (ret);
}

int					get_u(char c, t_tags tag, va_list va)
{
	char			*base;
	int				ret;
	int				len;
	int				minus;
	unsigned int	input;

	if (tag.flags == '0' && tag.pre == 0)
		tag.flags = '\0';
	ret = 0;
	input = get_base(c, &base, va);
	len = get_base_len(input, base);
	minus = input < 0 ? 1 : 0;
	if (tag.flags == '\0' || (tag.flags == '0' && tag.pre > 0))
		ret += print_u_outline(len, tag, minus, ' ');
	if (minus == 1)
		ret += ft_putchar('-');
	if (tag.flags == '0' && (tag.pre == 0 || tag.pre == -1))
		ret += print_u_outline(len, tag, minus, '0');
	ret += print_u_inline(len, tag, minus);
	ret += ft_putnbr_base(input, base, tag);
	if (tag.flags == '-')
		ret += print_u_outline(len, tag, minus, ' ');
	return (ret);
}
