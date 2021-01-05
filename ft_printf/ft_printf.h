/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:22:29 by hyeolee           #+#    #+#             */
/*   Updated: 2020/11/09 18:37:33 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# define ERROR -1

typedef	struct	s_tags
{
	char		flags;
	int			width;
	int			dot;
	int			pre;
}				t_tags;

int				ft_printf(const char *str, ...);

int				check_flags(char c, t_tags **tag);
int				check_width(char c, t_tags **tag, va_list va);
int				check_dot(char c, t_tags **tag);
int				check_precision(char c, t_tags **tag, va_list va);

int				ft_isdigit(int c);
int				ft_putchar(char c);
size_t			ft_strlen(const char *s);
int				ft_putstr(char *s);
char			*ft_strdup(const char *s1);

int				is_type(char c);
int				get_base_len(long long input, char *base);
long long		get_base(char c, char **base, va_list va);
void			print_nbr(long long input, int base_len, char *base, int *ret);
int				ft_putnbr_base(long long input, char *base, t_tags tag);

int				get_p(char c, t_tags tag, va_list va);
int				get_di(char c, t_tags tag, va_list va);
int				get_u(char c, t_tags tag, va_list va);
int				get_x(char c, t_tags tag, va_list va);
int				get_c(t_tags tag, va_list va);
int				get_s(t_tags tag, va_list va);
int				get_per(t_tags tag);

#endif
