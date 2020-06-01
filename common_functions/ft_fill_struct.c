/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 00:18:47 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:38:41 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	fill_min(const char *str, int *i, va_list *lst, t_flags *f)
{
	if ('*' == str[*i] && ++(*i))
		f->min = va_arg(*lst, int);
	else if (ft_strchr_chr("123456789", str[*i]))
	{
		f->min = ft_atoi(&str[*i]);
		while (ft_strchr_chr("0123456789", str[*i]))
			(*i)++;
	}
	if ('*' == str[*i])
		++(*i);
	if (f->min < 0)
	{
		f->flag = '-';
		f->width = -1 * f->min;
		f->min = 0;
	}
}

void	fill_flags(const char *str, int *i, t_flags *f)
{
	if ('0' == str[*i] && '-' == str[*i + 1] && ((*i) += 2))
		f->flag = '-';
	else if ('-' == str[*i] && '0' == str[*i + 1] && ((*i) += 2))
		f->flag = '-';
	else if ('-' == str[*i] && '-' == str[*i + 1] && ((*i) += 2))
		f->flag = '-';
	else if ('0' == str[*i] && '0' == str[*i + 1] && ((*i) += 2))
		f->flag = '0';
	else if ('0' == str[*i] && ++(*i))
		f->flag = '0';
	else if ('-' == str[*i] && ++(*i))
		f->flag = '-';
}

void	fill_width(const char *str, int *i, va_list *lst, t_flags *f)
{
	if ('*' == str[*i] && ++(*i))
		f->width = va_arg(*lst, int);
	else if (ft_strchr_chr("0123456789", str[*i]))
	{
		f->width = ft_atoi(&str[*i]);
		while (ft_strchr_chr("0123456789", str[*i]))
			(*i)++;
	}
	if (f->width < 0)
	{
		f->width *= -1;
		if (f->flag == '0')
			f->flag = '-';
	}
}

void	fill_precision(const char *str, int *i, va_list *lst, t_flags *f)
{
	if (str[*i] == '.' && ++(*i))
	{
		if (str[*i] == '*' && ++(*i))
			f->precision = va_arg(*lst, int);
		else if (ft_strchr_chr("0123456789", str[*i]))
		{
			f->precision = ft_atoi(&str[*i]);
			while (ft_strchr_chr("0123456789", str[*i]))
				(*i)++;
		}
		else
			f->precision = 0;
	}
}

void	fill_type(const char *str, int *i, va_list *lst, t_flags *f)
{
	if (str[*i] == '*' && ++(*i))
		f->min = va_arg(*lst, int);
	else if (ft_strchr_chr("0123456789", str[*i]))
	{
		f->min = ft_atoi(&str[*i]);
		while (ft_strchr_chr("0123456789", str[*i]))
			(*i)++;
	}
	if (ft_strchr_chr("%cspdiuxX", str[*i]))
		f->type = str[*i];
	if (f->flag == '0' && f->precision >= 0 && ft_strchr_chr("diuxX", f->type))
	{
		f->min = f->width;
		f->width = -1;
		f->flag = 0;
	}
}
