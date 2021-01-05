/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:31:25 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/09 18:03:54 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int				get_base_len(long long input, char *base)
{
	int			length;
	int			base_len;

	base_len = ft_strlen(base);
	length = input >= 0 ? 0 : 1;
	if (input < 0)
		input *= -1;
	while (input / base_len)
	{
		input /= base_len;
		length++;
	}
	return (++length);
}

long long		get_base(char c, char **base, va_list va)
{
	long long	input;

	input = 0;
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
		input = va_arg(va, int);
	else if (c == 'u')
		input = va_arg(va, unsigned int);
	else if (c == 'p')
		input = va_arg(va, long long);
	if (c == 'd' || c == 'i' || c == 'u')
		*base = "0123456789";
	else if (c == 'x' || c == 'p')
		*base = "0123456789abcdef";
	else if (c == 'X')
		*base = "0123456789ABCDEF";
	return (input);
}

void			print_nbr(long long input, int base_len, char *base, int *ret)
{
	if (input >= base_len)
	{
		print_nbr(input / base_len, base_len, base, ret);
		*ret += ft_putchar(base[input % base_len]);
	}
	else
		*ret += ft_putchar(base[input % base_len]);
}

int				ft_putnbr_base(long long input, char *base, t_tags tag)
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
	else if (tag.width == 0)
		return (0);
	else
		ret += ft_putchar(' ');
	return (ret);
}
