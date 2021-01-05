/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:38:23 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/09 19:00:18 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_di_outline(int len, t_tags tag, int minus, char c)
{
	int			arg;
	int			ret;
	int			i;

	ret = 0;
	arg = (tag.pre + minus > len) ? tag.pre + minus : len;
	i = tag.width - arg;
	while (c == ' ' && i-- > 0)
		ret += ft_putchar(' ');
	while (c == '0' && i-- > 0)
		ret += ft_putchar('0');
	return (ret);
}

int				print_di_inline(int len, t_tags tag, int minus)
{
	int			ret;
	int			i;

	i = (tag.pre + minus) - len;
	ret = 0;
	while (i-- > 0)
		ret += ft_putchar('0');
	return (ret);
}

int				get_di(char c, t_tags tag, va_list va)
{
	char		*base; // d i u x X
	int			ret;
	int			minus;
	int			len; // 정수의 길이
	long long	input; // 정수의 값

	if (tag.flags == '0' && tag.pre == 0)
		tag.flags = '\0';
	ret = 0;
	input = get_base(c, &base, va);
	len = get_base_len(input, base); //자릿수
	minus = input < 0 ? 1 : 0;
	if (tag.flags == '\0' || (tag.flags == '0' && tag.pre > 0)) 
		ret += print_di_outline(len, tag, minus, ' ');
	if (minus == 1)
		ret += ft_putchar('-');
	if (tag.flags == '0' && (tag.pre == 0 || tag.pre == -1))
		ret += print_di_outline(len, tag, minus, '0');
	ret += print_di_inline(len, tag, minus);
	ret += ft_putnbr_base(input, base, tag);
	if (tag.flags == '-')
		ret += print_di_outline(len, tag, minus, ' ');
	return (ret);
}
