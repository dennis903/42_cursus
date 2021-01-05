/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:34:42 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/07 17:36:59 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_s(t_tags tag, char *s, int len)
{
	int		ret;
	int		idx;
	int		i;

	idx = 0;
	ret = 0;
	if (tag.pre > -1 && tag.pre < len)
		i = tag.pre;
	else
		i = len;
	while (i-- > 0)
		ret += ft_putchar(s[idx++]);
	return (ret);
}

int			print_s_outline(int len, t_tags tag, char c)
{
	int		ret;
	int		arg;
	int		i;

	ret = 0;
	if (tag.pre > -1 && tag.pre < len)
		arg = tag.pre;
	else
		arg = len;
	i = tag.width - arg;
	while (c == ' ' && i-- > 0)
		ret += ft_putchar(' ');
	while (c == '0' && i-- > 0)
		ret += ft_putchar('0');
	return (ret);
}

int			get_s(t_tags tag, va_list va)
{
	char	*s;
	int		ret;
	int		len;

	if (tag.flags == '0' && tag.pre == 0)
		tag.flags = '\0';
	if (!(s = va_arg(va, char *)))
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	ret = 0;
	if (tag.flags == '\0')
		ret += print_s_outline(len, tag, ' ');
	if (tag.flags == '0')
		ret += print_s_outline(len, tag, '0');
	ret += print_s(tag, s, len);
	if (tag.flags == '-')
		ret += print_s_outline(len, tag, ' ');
	return (ret);
}
