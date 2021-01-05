/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:05:24 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/09 18:10:01 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putnbr_pbase(long long input, char *base, t_tags tag)
{
	int		base_len;
	int		ret;

	base_len = 0;
	ret = 0;
	if (tag.pre != 0 || input != 0)
	{
		base_len = ft_strlen(base);
		if (input < 0)
			input *= -1;
		print_nbr(input, base_len, base, &ret);
	}
	else
		ret += ft_putstr("0x");
	return (ret);
}

int				print_p_outline(int len, t_tags tag, char c)
{
	int			arg;
	int			ret;
	int			i;

	ret = 0;
	arg = (tag.pre > len) ? tag.pre : len;
	i = tag.width - arg;
	while (c == ' ' && i-- > 0)
		ret += ft_putchar(' ');
	while (c == '0' && i-- > 0)
		ret += ft_putchar('0');
	return (ret);
}

int				print_p_inline(int len, t_tags tag)
{
	int			ret;
	int			i;

	i = tag.pre - (len - 2);
	ret = 0;
	while (i-- > 0)
		ret += ft_putchar('0');
	return (ret);
}

int				get_p(char c, t_tags tag, va_list va)
{
	char		*base;
	int			ret;
	int			len;
	long long	input;

	if (tag.flags == '0' && tag.pre == 0)
		tag.flags = '\0';
	ret = 0;
	input = get_base(c, &base, va);
	if (input == 0 && tag.pre == 0)
		len = 2;
	else
		len = get_base_len(input, base) + 2;
	if (tag.flags == '\0' || (tag.flags == '0' && tag.pre > 0))
		ret += print_p_outline(len, tag, ' ');
	if (tag.pre != 0 || input != 0)
		ret += ft_putstr("0x");
	if (tag.flags == '0' && (tag.pre == 0 || tag.pre == -1))
		ret += print_p_outline(len, tag, '0');
	ret += print_p_inline(len, tag);
	ret += ft_putnbr_pbase(input, base, tag);
	if (tag.flags == '-')
		ret += print_p_outline(len, tag, ' ');
	return (ret);
}
