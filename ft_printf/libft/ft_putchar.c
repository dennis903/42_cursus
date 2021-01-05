/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:13:04 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/04 18:18:52 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_putstr(char *s)
{
	if (s == NULL)
		return (0);
	write(1, s, ft_strlen(s));
	return ((int)ft_strlen(s));
}
