/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:22:17 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/09 18:52:06 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_tags(t_tags *tag)
{
	tag->flags = '\0';
	tag->width = 0;
	tag->pre = -1;
	tag->dot = 0;
}

static int		read_types(const char *str, int idx, t_tags tag, va_list va)
{
	int			ret;

	ret = 0;
	if (str[idx] == 'd' || str[idx] == 'i')
		ret += get_di(str[idx], tag, va);
	else if (str[idx] == 'u')
		ret += get_u(str[idx], tag, va);
	else if (str[idx] == 'x' || str[idx] == 'X')
		ret += get_x(str[idx], tag, va);
	else if (str[idx] == 'p')
		ret += get_p(str[idx], tag, va);
	else if (str[idx] == 'c')
		ret += get_c(tag, va);
	else if (str[idx] == 's')
		ret += get_s(tag, va);
	else if (str[idx] == '%')
		ret += get_per(tag);
	else
		return (ERROR);
	return (ret);
}

static int		read_tags(const char *str, int idx, t_tags *tags, va_list va)
{
	while (str[idx])
	{
		if (is_type(str[idx]))
			break ;
		else if (check_flags(str[idx], &tags)) //'0', '-', '\0'
			idx++;
		else if (check_width(str[idx], &tags, va)) // %10d, %9d, %8d
			idx++;
		else if (check_dot(str[idx], &tags)) //10.9
			idx++;
		else if (check_precision(str[idx], &tags, va))
			idx++;
		else
			return (ERROR);
	}
	return (idx);
}

int				ft_printf(const char *str, ...)
{
	va_list		va; //가변인자
	t_tags		tags; //플래그를 저장할 구조체
	int			idx; //str의 인덱스
	int			ret; //최종 return할 값

	va_start(va, str);
	idx = 0;
	ret = 0;
	while (str[idx])
	{
		if (str[idx] == '%' && str[idx + 1])
		{
			init_tags(&tags); //tag초기화
			idx = read_tags(str, ++idx, &tags, va); //tag읽기
			ret += read_types(str, idx, tags, va);
		}
		else
			ret += ft_putchar(str[idx]);
		if (idx == ERROR || ret == ERROR)
			break ;
		idx++;
	}
	va_end(va);
	return (ret);
}
